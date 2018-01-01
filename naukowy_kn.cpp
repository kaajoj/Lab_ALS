#include <iostream>
#include <cmath>                                                        // pow
#include <vector>                                                       // kontenery
#include <stdlib.h>

using namespace std;

int main() {
	string wyrazenie;                                                   // przechowuje ciag liczb i symboli podanych przez uzytkownika
	vector <char> symbole;                                              // tablica przechowujaca symbole arytmeczyczne
	vector <double> liczby;                                             // tablica przechowujaca liczby

	cout << "KALKULATOR NAUKOWY" << endl << endl;
	cout << "Podaj ciag liczb i symboli (+,-,*,/,^)"<< endl;
	cout << "Aby zamknac wpisze - exit" << endl << endl << "Oblicz: ";
	cin >> wyrazenie;
/* przygotowanie wyrazenia do obliczen */
	while(wyrazenie!="exit"){
        int dlugosc=wyrazenie.length();                                 // pobranie dlugosci wyrazenia
        int i=0;
        string pom;                                                     // pomocniczny string
            for (i=0;i<dlugosc;i++) {
                if (isdigit(wyrazenie[i]) || wyrazenie[i]=='.') {       // sprawdzenie czy wprowadzono cyfrê lub kropkê
                    pom+=wyrazenie[i];
//                  cout << pom << endl;                                // TEST
                } else {
                    liczby.push_back(atof(pom.c_str()));                // od³o¿enie liczby
                    pom="";                                             // wyzerowanie
                    symbole.push_back(wyrazenie[i]);                    // pobranie symbolu
                    }
                if (i==(dlugosc-1)) {
                    liczby.push_back(atof(pom.c_str()));
                }}
/* Obliczenia */
        int j=0 ;                                                       // zmienna pomocniczna do przechodzenia po tablicach
        int ile_sym=symbole.size();                                     // liczba symboli
//      cout << ile_sym << endl;                                        // TEST
            while (j<ile_sym) {
                    if (symbole[j]=='^') {
                        liczby[j]=pow(liczby[j],liczby[j+1]);           // potegowanie
                        liczby.erase(liczby.begin()+j+1);               // usuniecie otatniego elementu, juz wykorzystanego w obliczeniach
                        symbole.erase(symbole.begin()+j);               // usuniecie wykorzystanego znaku
                        j--;                                            // pomniejzenie o 1 ilosci liczb wykorzystaych w obliczeniach, z 2 powstaje 1
                        ile_sym--;                                      // zmniejszenie o 1 liczby wykorzystaych symboli
                    } j++;                                              // inkrementacja w celu pozukiwania powtorzenia symbolu
                }j=0;                                                   // wyzerowanie zmiennej, aby wyszykwiac od pcozatku tablicy liczb i symboli
            while (j<ile_sym) {
                    if (symbole[j]=='*') {
                        liczby[j]*=liczby[j+1];                         // mnozenie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } else if (symbole[j]=='/') {
                        liczby[j]/=liczby[j+1];                         // dzielenie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } j++;
                } j=0;
            while (j<ile_sym) {
                    if (symbole[j]=='+') {
                        liczby[j]+=liczby[j+1];                         // dodawanie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } else if (symbole[j]=='-') {
                        liczby[j]-=liczby[j+1];                         // odejmowanie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } j++;
                }
            cout << "Wynik: " << liczby[0] << endl;
            liczby.clear();                                             // usuniecie wszyskich elementow z kontenera
            symbole.clear();                                            //  -||-
            cout << endl << "Oblicz: ";
            cin >> wyrazenie;
        }
    return 0;
}
