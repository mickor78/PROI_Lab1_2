//
// Created by michal on 25.03.18.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "matrixclass.h"

//Default constructor
MatrixClass::MatrixClass() {
}
////Default constructor

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


//Conut determinant
//Recurennce
double MatrixClass::determinant(MatrixClass &m) {
    double det = 0.0;
    if (m.numberOfDegree == 2) {
        det = m.matrix[0][0] * m.matrix[1][1] - m.matrix[1][0] * m.matrix[0][1];
    } else {
        double *columnVal = new double[m.numberOfDegree];
        MatrixClass *minorTab = new MatrixClass[m.numberOfDegree];


        for (int i = 0; i < m.numberOfDegree; i++) {
            minorTab[i].numberOfDegree = m.numberOfDegree - 1;
            minorTab[i].matrixGenerator();
            columnVal[i] = m.matrix[i][0];

           bool ifBefore = true;
           for (int columnMinor = 0; columnMinor < minorTab[i].numberOfDegree; ++columnMinor) {
                for (int rowMinor = 0; rowMinor < minorTab[i].numberOfDegree; ++rowMinor) {
                    if (columnMinor == i) ifBefore=false;
                    if (ifBefore)
                        minorTab[i].matrix[columnMinor][rowMinor] = m.matrix[columnMinor][rowMinor+1];
                    else
                    minorTab[i].matrix[columnMinor][rowMinor] = m.matrix[columnMinor + 1][rowMinor + 1];
                }
            }

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
    //std::cout<<"Wynik z operatora:\n\n" <<temp;
    return temp;
}

MatrixClass operator-(const MatrixClass &m, const MatrixClass &n) {

    MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            temp.matrix[i][j] = m.matrix[i][j] - n.matrix[i][j];
        }
    }
    //std::cout<<"Wynik z operatora:\n\n" <<temp;
    return temp;
}

MatrixClass operator*(const MatrixClass &m, const MatrixClass &n) {

    MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            temp.matrix[i][j] = 0;
        }
    }
    //std::cout<<"Wynik z operatora:\n\n" <<temp;

    for (int rowBefore = 0; rowBefore < m.numberOfDegree; ++rowBefore) {
        for (int columnAfter = 0; columnAfter < n.numberOfDegree; ++columnAfter) {
            for (int columnBefore = 0; columnBefore < m.numberOfDegree; ++columnBefore) {
                temp.matrix[rowBefore][columnAfter] +=
                        m.matrix[rowBefore][columnBefore] * n.matrix[columnBefore][columnAfter];
            }

            //std::cout << "Wynik z operatora:\n\n" << rowBefore << " " << columnAfter << " " << temp;
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
    //std::cout<<"Wynik z operatora:\n\n" <<temp;
    return m;
}


MatrixClass &operator-=(MatrixClass &m, const MatrixClass &n) {
    //MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            m.matrix[i][j] -= n.matrix[i][j];
        }
    }
    //std::cout<<"Wynik z operatora:\n\n" <<temp;
    return m;
}

MatrixClass &operator*=(MatrixClass &m, const MatrixClass &n) {

    MatrixClass temp(m.numberOfDegree);
    for (int i = 0; i < m.numberOfDegree; ++i) {
        for (int j = 0; j < m.numberOfDegree; ++j) {
            temp.matrix[i][j] = 0;
        }
    }
    //std::cout<<"Wynik z operatora:\n\n" <<temp;

    for (int rowBefore = 0; rowBefore < m.numberOfDegree; ++rowBefore) {
        for (int columnAfter = 0; columnAfter < n.numberOfDegree; ++columnAfter) {
            for (int columnBefore = 0; columnBefore < m.numberOfDegree; ++columnBefore) {
                temp.matrix[rowBefore][columnAfter] +=
                        m.matrix[rowBefore][columnBefore] * n.matrix[columnBefore][columnAfter];
            }

            //std::cout << "Wynik z operatora:\n\n" << rowBefore << " " << columnAfter << " " << temp;
        }
    }
    m += temp;
    return m;
}


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



