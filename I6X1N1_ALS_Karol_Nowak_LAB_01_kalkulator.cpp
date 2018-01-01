#include <iostream>

using namespace std;

int main(void) {

	double a=0;
	double b=0;
	double c=0;	// wynik
	int d=9999;	// opcja
	double x=0;	// dalsze obliczenia

	cout<<"KALKULATOR"<<endl<<endl;

	cout<<"Podaj pierwsza i druga liczbe"<<endl;
	cin>>a;
	cin>>b;

while(d!=0) {

	cout<<endl;
	cout<<"MENU"<<endl;
	cout<<"Aby wykoanc dodawanie wpisz:     1"<<endl;
	cout<<"Aby wykoanc odejmowanie wpisz:   2"<<endl;
	cout<<"Aby wykoanc mnozenie wpisz:      3"<<endl;
	cout<<"Aby wykoanc dzielenie wpisz:     4"<<endl;
	cout<<"Aby zamknac kalkulator wpisz:    0"<<endl;
	cin>>d;


	if(d==0) exit(0);

	switch(d) { 
         case 1:  
			c=a+b;
            break;  
         case 2:  
			c=a-b;
			 break;  
		 case 3:  
			 c=a*b;
            break;  
         case 4:  
			 if (b!=0) {
			 c=a/b; 
			 }
			 else {
				 cout<< "Nie mozna dzielic przez 0";
			 }
			 break; 
      }  
		cout<< "Twoj wynik: "<<c;	
		cout<<endl;
		cout<<"Czy chcesz wykorzystac wynik w dalszych obliczeniach? wcisnij 1 (TAK) lub 0 (NIE) ";
		cout<<endl;
		cin>>x;
		if (x==1) {
		a=c;
		cout<<endl;
		cout<<"Podaj druga liczbe do dzialan: ";
		cin>>b;
		}
		if (x==0) {
		cout<<"Podaj pierwsza i druga liczbe"<<endl;
		cin>>a;
		cin>>b;
		}

}

	system("pause");
	return 0;
}