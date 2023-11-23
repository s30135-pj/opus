
#include <iostream>
using namespace std;
class Temperatura {
	double stopnie_celciusza;
	double fahrenheit_wart_bewzgledna;
	friend Temperatura operator"" _stC(long double stopnie);
	friend ostream & operator<<(ostream& ekran, Temperatura temp);
	friend Temperatura operator"" _stF(long double f);
public: 
	Temperatura(double c = 0, double f = 0) : stopnie_celciusza(c), fahrenheit_wart_bewzgledna(f) {};
	operator double() {
		return stopnie_celciusza;
	}
	Temperatura operator-() {
		fahrenheit_wart_bewzgledna = -fahrenheit_wart_bewzgledna;
		double c = round(((fahrenheit_wart_bewzgledna - 32) * 5 / 9.0) * 100) / 100;
		stopnie_celciusza = c;
		return *this;
	}
};
Temperatura operator"" _stC(long double stopnie) {
	Temperatura t;
	t.stopnie_celciusza = stopnie;
	return t;
}
Temperatura operator"" _stF(long double f) {
	double c = round ( ((f - 32) * 5 / 9.0) * 100 ) / 100;
	Temperatura t;
	t.stopnie_celciusza = c;
	t.fahrenheit_wart_bewzgledna = f;
	return t;
}
ostream & operator<<(ostream & ekran, Temperatura temp) {
	ekran << temp.stopnie_celciusza;
	return ekran;
}

class Tuplyw_czasu {
	int sekundy;
	friend ostream& operator<<(ostream& ekran, Tuplyw_czasu czas);
	friend Tuplyw_czasu operator"" _sek(unsigned long long s);
	friend Tuplyw_czasu operator"" _min(unsigned long long m);
	friend Tuplyw_czasu operator"" _godz(unsigned long long g);
	friend Tuplyw_czasu operator"" _d(unsigned long long d);
public:
	Tuplyw_czasu(int s = 0) : sekundy(s) {};
	Tuplyw_czasu operator+(Tuplyw_czasu c) {
		Tuplyw_czasu nowy;
		nowy.sekundy = sekundy + c.sekundy;
		return nowy;
	}
};
ostream& operator<<(ostream& ekran, Tuplyw_czasu czas) {
	ekran << czas.sekundy;
	return ekran;
}
Tuplyw_czasu operator"" _sek(unsigned long long s) {
	Tuplyw_czasu c;
	c.sekundy = s;
	return c;
}
Tuplyw_czasu operator"" _min(unsigned long long m) {
	Tuplyw_czasu c;
	c.sekundy = m * 60;
	return c;
}
Tuplyw_czasu operator"" _godz(unsigned long long g) {
	Tuplyw_czasu c;
	c.sekundy = g * 60 * 60;
	return c;
}
Tuplyw_czasu operator"" _d(unsigned long long d) {
	Tuplyw_czasu c;
	c.sekundy = d * 60 * 60 * 24;
	return c;
}

string operator"" _bitowo(unsigned long long licz) {
	string bitowo = "0000 0000 0000 0000 0000 0000 0000 0000";
	int ile = bitowo.length() -1;
	while (licz >= 1) {
		if (ile % 5 == 4) ile--;
		if (licz % 2 == 1) bitowo[ile] = '1';
		licz /= 2;
		ile--;
	}
	return bitowo;
}

int main()
{
	cout << "100.0_stF: " << 100.0_stF << " stopni Celsjusza" << endl;
	cout << "Temperatura ciala: " << 36.6_stC << endl;
	double x = 80.0_stF;
	cout << x << endl;
	cout << "-1.0_stF to w skali Celsjusza: " << -1.0_stF << endl;
	cout << " 0.0_stF to w skali Celsjusza: " << 0.0_stF << endl;
	cout << " 1.0_stF to w skali Celsjusza: " << 1.0_stF << endl;
	// Wa¿ne sprawdzenie. Powinno byæ -40F == -40C
	cout << " -40.0_stF to w skali Celsjusza: " << -40.0_stF << endl;
	cout << "40.0_stF = " << 40.0_stF << endl;
	cout << "-40.0_stF = " << -40.0_stF << endl;
	cout << "-(-40.0_stF) = " << -(-40.0_stF) << endl;
	cout << "-(-(40.0_stF)) = " << -(-(-40.0_stF)) << endl;
	cout << "-(-(-(-40.0_stF))) = " << -(-(-(-40.0_stF))) << endl;
	Tuplyw_czasu czas = 3_sek + 1_min;
	cout << "Krotszy czas = " << czas << endl;
	czas = czas + 24_godz + 2_d + 5_godz;
	cout << "Dluzszy czas = " << czas << endl;
	cout << "0xfa to taki rozklad bitow: " << 0xfa_bitowo << endl;
	cout << "0xfff to taki rozklad bitow: " << 0xfff_bitowo << endl;
}

