#include <iostream>
#include <unistd.h>
#include "matrixclass.h"

using namespace std;

int main() {

    int N = 4;
    MatrixClass A(N);
    sleep(1);
    MatrixClass B(N);
    cout<<"A=\n"<<A<<"B=\n"<<B;
    cout<<endl;

    MatrixClass C(A+B);
    cout<<"A+B=\n"<<C;
    cout<<endl;

    MatrixClass D(A-B);
    cout<<"A-B=\n"<<D;
    cout<<endl;

    MatrixClass E(A*B);
    cout<<"A*B=\n"<<E;
    cout<<endl;

    A+=B;
    cout<<"A+=B\nA=\n"<<A;

    double det = A.determinant(A);
    cout<<endl<<endl<<"wyznacznik A ="<<det;

    return 0;
}