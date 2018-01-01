// Karol Nowak
// Grupa: I6X1N1
// Nr albumu: 67471

// silnia z wykorzystaniem charow

#include <iostream>
#include <cstdlib>

using namespace std;

inline int cyfra(char znak) {
       return int(znak-48);
       }

inline char znak(int liczba) {
       return char(liczba+48);
       }

string dodawanie(string &A,string &B){
       while(A.length()!=B.length()) {
            if(A.length() > B.length()) {
                B="0"+B;
                }
                else {
                A="0"+ A;
            }
       }

    int tym = 0;           // zmienna pomocnicza
    string wynik = "";

    for(int i=A.length()-1;i>=0;i--) {
        int Tym = cyfra(A[i]) + cyfra(B[i]) + tym;
        wynik = znak(Tym%10) + wynik;
        tym = int(Tym/10);
        }
        if(tym!=0)
        wynik=znak(tym)+wynik;
    return wynik;
}

string mnozenie(string STR, unsigned long long int INT) {
        string wynik = "0";
        unsigned long long int i ;
        
        for(i=1;i;i<<=1) {
        if(INT&i)
        wynik=dodawanie(wynik,STR);
        STR=dodawanie(STR,STR);
        }
    return wynik;
}

// G³ówny czêœæ programu
int main(void)
{
    setlocale(LC_ALL, "");

    string silnia = "1";
    unsigned long long int n,i;
    
    cout << "Podaj liczbê dla której ma byæ obliczona silnia: " << endl << endl;
    cin >> n;
    
    if(n==0 || n==1) {
        cout << "";
        }
    else {
         for(i=2;i<=n;i++) {
         silnia = mnozenie(silnia,i);
         }
    }
    cout << endl << "Wynik: " << silnia << endl << endl;

system("pause");
return 0;
}
