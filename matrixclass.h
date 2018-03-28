//
// Created by michal on 25.03.18.
//

#ifndef PROI_LAB1_2_MATRIXCLASS_H
#define PROI_LAB1_2_MATRIXCLASS_H

#include <cstdlib>
#include <ctime>
#include <ostream>

class MatrixClass {
    int numberOfDegree;
    double **matrix;

public:
    explicit MatrixClass(int numberOfDegree);
    MatrixClass(const MatrixClass &m);
    MatrixClass();
    MatrixClass(int i, double **m);
    ~MatrixClass();

    double determinant(MatrixClass &m);
    void matrixGenerator();
    void matrixRandomizer();

    friend std::ostream &operator<<(std::ostream &, MatrixClass &);
    friend MatrixClass operator+(const MatrixClass &m, const MatrixClass &n);
    friend MatrixClass operator-(const MatrixClass &m, const MatrixClass &n);
    friend MatrixClass operator*(const MatrixClass &m, const MatrixClass &n);
    friend MatrixClass &operator+=(MatrixClass &m, const MatrixClass &n);
    friend MatrixClass &operator-=(MatrixClass &m, const MatrixClass &n);
    friend MatrixClass &operator*=(MatrixClass &m, const MatrixClass &n);

};


std::ostream &operator<<(std::ostream &out, MatrixClass &m);
MatrixClass operator+(const MatrixClass &m, const MatrixClass &n);
MatrixClass operator-(const MatrixClass &m, const MatrixClass &n);
MatrixClass operator*(const MatrixClass &m, const MatrixClass &n);
MatrixClass &operator+=(MatrixClass &m, const MatrixClass &n);
MatrixClass &operator-=(MatrixClass &m, const MatrixClass &n);
MatrixClass &operator*=(MatrixClass &m, const MatrixClass &n);


#endif //PROI_LAB1_2_MATRIXCLASS_H
