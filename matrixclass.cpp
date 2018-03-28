//
// Created by michal on 25.03.18.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "matrixclass.h"

//Default constructor
MatrixClass::MatrixClass() {
    numberOfDegree = 1;
    matrixGenerator();
}
//Default constructor

MatrixClass::MatrixClass(int i, double **m) {
    this->numberOfDegree=i;
    matrixGenerator();
    for (int i = 0; i < numberOfDegree; ++i) {
        for (int j = 0; j < numberOfDegree; ++j) {
            //matrix[i][j] = (double)(std::rand())/(double)(RAND_MAX);
            this->matrix[i][j] = m[i][j];
        }
    }
}


//Copying consturtor
MatrixClass::MatrixClass(const MatrixClass &m) {
    this->numberOfDegree = m.numberOfDegree;
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            this->matrix[i][j] = m.matrix[i][j];
        }
    }
}
//Copying consturtor

//One parameter constructor
//Generate random NxN matrix
MatrixClass::MatrixClass(int numberOfDegree) {
    //set nuber of degree
    this->numberOfDegree = numberOfDegree;
    //call matrixGenerator()
    matrixGenerator();
    //call matrixRandomizer()
    matrixRandomizer();
}
//One parameter constructor

//Destructor
MatrixClass::~MatrixClass() {
    for (int i = 0; i < numberOfDegree; ++i)
        delete[] matrix[i];
    delete[] matrix;
}
//Destructor

//Matrix initializator
//initialize 2D table
void MatrixClass::matrixGenerator() {
    this->matrix = new double *[numberOfDegree];
    for (int i = 0; i < numberOfDegree; ++i) {
        this->matrix[i] = new double[numberOfDegree];
    }
}
//Matrix initializator

//Fill matrix with random Values
void MatrixClass::matrixRandomizer() {
    //set range
    int min=-10, max=10;
    //float - put 'n'
    char n = 'n';

    srand(time(NULL));
    for (int i = 0; i < this->numberOfDegree; ++i) {
        for (int j = 0; j < this->numberOfDegree; ++j) {
            if(n=='n')
                this->matrix[i][j] = (double)(std::rand())/(double)(RAND_MAX)*(max-min)+min;
            else this->matrix[i][j] = (std::rand() % (max-min))+min;
        }
    }
}




//Count determinant
//Recurrence
//Laplace'a algorithm
double MatrixClass::determinant(MatrixClass &m) {
    //det is determinant
    double det = 0.0;
    //if degree is 2 count determinant
    //if not make minors
    if (m.numberOfDegree == 2) {
        det = m.matrix[0][0] * m.matrix[1][1] - m.matrix[1][0] * m.matrix[0][1];
    } else {
        //table of first raw values
        double *columnVal = new double[m.numberOfDegree];
        //allocate memory for table of MatrixClass objects
        MatrixClass *minorTab = new MatrixClass[m.numberOfDegree];

        //for each row make minors
        for (int i = 0; i < m.numberOfDegree; i++) {
            //set minors degree
            minorTab[i].numberOfDegree = m.numberOfDegree - 1;
            minorTab[i].matrixGenerator(); // generate matrix
            //set column table value
            columnVal[i] = m.matrix[i][0];

            //ifBefore speaks false when going by colums and row you should miss one
           bool ifBefore = true;
            //loop fils minor column with values of matrix missing i-column and i-row
           for (int columnMinor = 0; columnMinor < minorTab[i].numberOfDegree; ++columnMinor) {
                for (int rowMinor = 0; rowMinor < minorTab[i].numberOfDegree; ++rowMinor) {
                    if (columnMinor == i) ifBefore=false;
                    if (ifBefore)
                        //mising row by add 1 to iterator
                        minorTab[i].matrix[columnMinor][rowMinor] = m.matrix[columnMinor][rowMinor+1];
                    else
                        //mising column by add 1 to iterator
                    minorTab[i].matrix[columnMinor][rowMinor] = m.matrix[columnMinor + 1][rowMinor + 1];
                }
            }
            //multiply depends on position by (-1)^(i+j)
            if (i%2!=1)
            det -= columnVal[i]*determinant(minorTab[i]);
            else
            det += columnVal[i]*determinant(minorTab[i]);



        }
        delete [] columnVal;
        delete [] minorTab;
    }

    return det;
}
//Count determinant

//
//Overload operators
//

std::ostream &operator<<(std::ostream &out, MatrixClass &m) {
    std::cout.precision(3);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            out << m.matrix[j][i] << " ";
        }
        out << std::endl;
    }
    return out;
}

MatrixClass operator+(const MatrixClass &m, const MatrixClass &n) {

    MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            temp.matrix[i][j] = m.matrix[i][j] + n.matrix[i][j];
        }
    }
    return temp;
}

MatrixClass operator-(const MatrixClass &m, const MatrixClass &n) {

    MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            temp.matrix[i][j] = m.matrix[i][j] - n.matrix[i][j];
        }
    }
    return temp;
}

MatrixClass operator*(const MatrixClass &m, const MatrixClass &n) {

    MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            temp.matrix[i][j] = 0;
        }
    }


    for (int rowBefore = 0; rowBefore < m.numberOfDegree; ++rowBefore) {
        for (int columnAfter = 0; columnAfter < n.numberOfDegree; ++columnAfter) {
            for (int columnBefore = 0; columnBefore < m.numberOfDegree; ++columnBefore) {
                temp.matrix[rowBefore][columnAfter] +=
                        m.matrix[rowBefore][columnBefore] * n.matrix[columnBefore][columnAfter];
            }

        }
    }

    return temp;
}


MatrixClass &operator+=(MatrixClass &m, const MatrixClass &n) {
    //MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            m.matrix[i][j] += n.matrix[i][j];
        }
    }
    return m;
}


MatrixClass &operator-=(MatrixClass &m, const MatrixClass &n) {
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            m.matrix[i][j] -= n.matrix[i][j];
        }
    }
    return m;
}

MatrixClass &operator*=(MatrixClass &m, const MatrixClass &n) {

    MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            temp.matrix[i][j] = 0;
        }
    }

    for (int rowBefore = 0; rowBefore < m.numberOfDegree; ++rowBefore) {
        for (int columnAfter = 0; columnAfter < n.numberOfDegree; ++columnAfter) {
            for (int columnBefore = 0; columnBefore < m.numberOfDegree; ++columnBefore) {
                temp.matrix[rowBefore][columnAfter] +=
                        m.matrix[rowBefore][columnBefore] * n.matrix[columnBefore][columnAfter];
            }

        }
    }
    m += temp;
    return m;
}

