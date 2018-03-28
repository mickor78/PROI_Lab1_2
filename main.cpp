#include <iostream>
#include <unistd.h>
#include "matrixclass.h"

using namespace std;

int main() {
    int N;
    int menu;
    MatrixClass *macierzA;
    MatrixClass *macierzB;
    cout<<"*************************************"<<endl;
    cout<<"               MENU                  "<<endl;
    cout<<"1. Wylosuj Macierze"<<endl;
    cout<<"2. Wpisz Macierze"<<endl;
    cout<<"3. Policz wyznacznik Macierzy"<<endl;
    cout<<">>";
    cin>>menu;
    cout<<endl;
    switch(menu) {
        default: {
            cout << "1,2,3 obsluguja menu. Wpisz jeszcze raz";
            cin >> menu;
            break;
        }
        case 1: {
            cout << "Wpisz wymiar macierzy" << endl;
            int wymiar;
            cout<<">>";
            cin>>wymiar;
            cout<<endl;
            1
            macierzA =new MatrixClass(wymiar);
            macierzB =new MatrixClass(wymiar);
            cout<<"Wygenerowane macierze.1 A:"<<endl<<macierzA<<"B:"<<endl<<macierzB;
            break;
        }
        case 2:{
            cout << "Wpisz wymiar macierzy" << endl;
            int wymiar;
            cout<<">>";
            cin>>wymiar;
            cout<<endl;
            double **macierzUzytkownikaA = new double *[wymiar];
            double **macierzUzytkownikaB = new double *[wymiar];
            for (int i = 0; i < wymiar; ++i) {
                macierzUzytkownikaA[i] = new double[wymiar];
                macierzUzytkownikaB[i] = new double[wymiar];
            }
            cout<<"Wymiar macierzy to:"<<wymiar<<endl;
            cout<<"Wpisz wartości macierzy A:"<<endl;
            for (int i = 0; i < wymiar; ++i) {
                cout<<"Kolumna"<<i+1<<":";
                for (int j = 0; j < wymiar; ++j) {
                    cin>>macierzUzytkownikaA[i][j];
                }
            }
            cout<<"Wpisz wartości macierzy B:"<<endl;
            for (int i = 0; i < wymiar; ++i) {
                cout<<"Kolumna"<<i+1<<":";
                for (int j = 0; j < wymiar; ++j) {
                    cin>>macierzUzytkownikaB[i][j];
                }
            }
            macierzA =new MatrixClass(wymiar, macierzUzytkownikaA);
            macierzB = new MatrixClass(wymiar,macierzUzytkownikaB);
            cout<<"Wpisane macierze A:"<<endl<<macierzA<<"B:"<<endl<<macierzB;
        }
        case 3:{


        }
    }

    cout<<"*************************************"<<endl;

























/*
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
    cout<<endl<<endl<<"wyznacznik A ="<<det;*/

    return 0;
}