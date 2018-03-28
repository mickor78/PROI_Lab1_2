#include <iostream>
#include <unistd.h>
#include "matrixclass.h"

using namespace std;

int main() {

    // Program testuje utworzoną klasę
    //menu urzytkownika

    int menu; // zmienna sterujaca menu

    //dwa obiekty na ktorych bedziemy pracowac
    MatrixClass macierzA;
    MatrixClass macierzB;

    //interface
    cout<<"*************************************"<<endl;
    cout<<"               MENU                  "<<endl<<endl;
    cout<<"Dzialanie na macierzach"<<endl;
    cout<<"1. Wylosuj Macierze"<<endl;
    cout<<"2. Wpisz Macierze"<<endl<<endl;
    cout<<"Obliczanie wyznacznika"<<endl;
    cout<<"3. Policz wyznacznik Macierzy"<<endl<<endl;
    cout<<"4. Szybka prezentacja"<<endl;
    cout<<"*************************************"<<endl;
    cout<<">>";
    cin>>menu;
    cout<<endl;

    //sprawdzenie strumienia wejscia
    //za każdym razem wyglada tak samo
    //dopóku warunek liczbowy lub błąd wejścia
    //pytaj o liczbę

    while(menu>4||menu<1||cin.fail()) {
        cin.clear(); //flaga na good
        cin.ignore(9999, '\n');//ignoruj inne znaki
        cout << "Nie ma takiej opcji. Wpisz jeszcze raz:" << endl;
        cout << ">>";
        cin >> menu;
        cout << endl;
    }
    cin.ignore(9999, '\n');


    switch(menu) {
        case 1: {
            cout<<"1. Wylosuj Macierze"<<endl;
            cout << "Wpisz wymiar macierzy" << endl;
            int wymiar;
            cout<<">>";
            cin>>wymiar;
            cout<<endl;
            while(cin.fail()) {
                cin.clear();
                cin.ignore(9999, '\n');
                cout << "Nie wpisales liczby. Sprobuj jeszcze raz:" << endl;
                cout << ">>";
                cin >> wymiar;
                cout << endl;
            }
            cin.ignore(9999, '\n');

            //ustaw wymiar macierzy
            macierzA.numberOfDegree = wymiar;
            macierzB.numberOfDegree = wymiar;

            //wygeneruj macierze
            macierzA.matrixGenerator();
            macierzB.matrixGenerator();

            //wypełnij losowymi wartościami
            macierzA.matrixRandomizer();
            sleep(1); // czeka na przejście zegara
            macierzB.matrixRandomizer();
            cout<<"Wygenerowane macierze.1 A:"<<endl<<macierzA<<"B:"<<endl<<macierzB;
            break;
        }
        case 2:{
            cout<<"2. Wpisz Macierze"<<endl<<endl;
            cout << "Wpisz wymiar macierzy" << endl;
            int wymiar;
            cout<<">>";
            cin>>wymiar;
            cout<<endl;
            while(cin.fail()) {
                cin.clear();
                cin.ignore(9999, '\n');
                cout << "Nie wpisales liczby. Sprobuj jeszcze raz:" << endl;
                cout << ">>";
                cin >> wymiar;
                cout << endl;
            }
            cin.ignore(9999, '\n');

            //ustaw wymiar
            macierzA.numberOfDegree = wymiar;
            //generuj
            macierzA.matrixGenerator();
            macierzB.numberOfDegree = wymiar;
            macierzB.matrixGenerator();
            cout<<"Wymiar macierzy to:"<<wymiar<<endl;

            //wpisywanie wartosci
            //petla po kolumnach i wierszach
            cout<<"Wpisz wartości macierzy A:"<<endl;
            for (int i = 0; i < wymiar; ++i) {
                cout<<"Kolumna"<<i+1<<":";
                for (int j = 0; j < wymiar; ++j) {
                    cin>>macierzA.matrix[j][i];
                    while(cin.fail()) {
                        cin.clear();
                        cin.ignore(9999, '\n');
                        cout << "Nie wpisales liczby. Sprobuj jeszcze raz:" << endl;
                        cout << ">>";
                        cin >> macierzA.matrix[j][i];
                        cout << endl;
                    }

                }
                cin.ignore(9999, '\n'); // czysc strumien po kazdej kolumnie
            }
            cout<<"Wpisz wartości macierzy B:"<<endl;
            for (int i = 0; i < wymiar; ++i) {
                cout<<"Kolumna"<<i+1<<":";
                for (int j = 0; j < wymiar; ++j) {
                    cin>>macierzB.matrix[j][i];
                    while(cin.fail()) {
                        cin.clear();
                        cin.ignore(9999, '\n');
                        cout << "Nie wpisales liczby. Sprobuj jeszcze raz:" << endl;
                        cout << ">>";
                        cin >> macierzB.matrix[j][i];
                        cout << endl;
                    }
                }
                cin.ignore(9999, '\n');
            }

            cout<<"Wpisane macierze A:"<<endl<<macierzA<<"B:"<<endl<<macierzB;
            break;
        }
        case 3:{
            cout<<"3. Policz wyznacznik Macierzy"<<endl;
            cout << "Wpisz wymiar macierzy" << endl;
            int wymiar;
            cout<<">>";
            cin>>wymiar;
            cout<<endl;
            while(cin.fail()) {
                cin.clear();
                cin.ignore(9999, '\n');
                cout << "Nie wpisales liczby. Sprobuj jeszcze raz:" << endl;
                cout << ">>";
                cin >> wymiar;
                cout << endl;
            }
            cin.ignore(9999, '\n');
            //Mozliwosc losowania
            cout<<"Czy losować? Tak:1. Nie:2."<<endl;
            cout<<">>";
            cin>>menu;
            cout<<endl;
            while(menu>2||menu<1||cin.fail()) {
                cin.clear();
                cin.ignore(9999, '\n');
                cout << "Nie ma takiej opcji. Wpisz jeszcze raz:" << endl;
                cout << ">>";
                cin >> menu;
                cout << endl;
            }
            cin.ignore(9999, '\n');
            macierzA.numberOfDegree = wymiar;
            macierzB.numberOfDegree = wymiar;
            macierzA.matrixGenerator();
            macierzB.matrixGenerator();

            //jesli wybrano 1 wypelnia wartosciami losowymi
            //jesli 2 to wpisuje wartosc samemu
            if(menu==1)
            {
                macierzA.matrixRandomizer();
            }
                else {
                cout << "Wpisz wartości macierzy A:" << endl;
                for (int i = 0; i < wymiar; ++i) {
                    cout << "Kolumna" << i + 1 << ":";
                    for (int j = 0; j < wymiar; ++j) {
                        cin >> macierzA.matrix[j][i];
                        while(cin.fail()) {
                            cin.clear();
                            cin.ignore(9999, '\n');
                            cout << "Nie wpisales liczby. Sprobuj jeszcze raz:" << endl;
                            cout << ">>";
                            cin >> macierzA.matrix[j][i];
                            cout << endl;
                        }
                    }
                    cin.ignore(9999, '\n');
                }
            }

            //zwracanie wyznacznika
            cout<<"Wpisane macierze A:"<<endl<<macierzA;
            cout<<"Wyznacznik |A| = "<<macierzA.determinant(macierzA)<<endl;
            return 0;
        }
        case 4:{
            int N;

            N = 4;
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
            cout<<endl<<endl<<"wyznacznik A ="<<det<<endl;
            return 0;
        }
    }

    //menu dzialan
    //do wyboru 7 opcji
    do {
        menu = -1;

        cout << "*************************************" << endl;
        cout << "Mozliwe dzialania" << endl;
        cout << "1. A+B=C" << endl;
        cout << "2. A-B=C" << endl;
        cout << "3. A*B=C" << endl;
        cout << "4. A+=B" << endl;
        cout << "5. A-=B" << endl;
        cout << "6. A*=B" << endl;
        cout << "0. Wyjdz z programu" << endl;
        cout << ">>";
        cin >> menu;
        cout << endl;
        while(menu>6||menu<0||cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Nie ma takiej opcji. Wpisz jeszcze raz:" << endl;
            cout << ">>";
            cin >> menu;
            cout << endl;
        }
        cin.ignore(9999, '\n');

        //wykonywanie dzialan
        switch (menu) {
            case 1: {
                MatrixClass macierzC(macierzA+macierzB);
                cout<<"A+B:"<<endl<<macierzA<<"+"<<endl<<macierzB<<"= C:"<<endl<<macierzC<<endl;
                break;
            }
            case 2: {
                MatrixClass macierzC(macierzA-macierzB);
                cout<<"A-B:"<<endl<<macierzA<<"-"<<endl<<macierzB<<"= C:"<<endl<<macierzC<<endl;
                break;
            }
            case 3: {
                MatrixClass macierzC(macierzA*macierzB);
                cout<<"A*B:"<<endl<<macierzA<<"*"<<endl<<macierzB<<"= C:"<<endl<<macierzC<<endl;
                break;
            }
            case 4: {
                macierzA+=macierzB;
                cout<<"A:"<<endl<<macierzA<<endl;
                break;
            }
            case 5: {
                macierzA -= macierzB;
                cout << "A:" << endl << macierzA << endl;
                break;
            }
            case 6: {
                macierzA *= macierzB;
                cout << "A:" << endl << macierzA << endl;
                break;
            }
            //jesli uzytkownik wybral 0 koniec programu
            default: return 0;
        }

    }while(menu!=0);


    return 0;
}