
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Tblaster
{
	double* zasobnik{ nullptr };
	public :
	Tblaster(double k = 1) { // konstruktor domniemany
		zasobnik = new double[150];
		for (int i = 0; i < 150; ++i) {
			zasobnik[i] = k * i;
		}
	}
	~Tblaster(); // destruktor
	Tblaster(const Tblaster&) = delete;
	Tblaster& operator = (const Tblaster & wzor); // operator przypisania
	// funkcja pomocnicza do wykorzystania przez funkcjê Tszuflada::co_teraz_w_unii
	void info() {
		for (int i = 0; i < 7; ++i) { cout << zasobnik[i] << " "; }
	}
};
Tblaster::~Tblaster() {
	if (zasobnik != nullptr)
	delete[] zasobnik;
}
Tblaster& Tblaster::operator=(const Tblaster& wzor) {
	if (zasobnik) delete[] zasobnik;
	zasobnik = new double[150];
	for (int i = 0; i < 150; i++) {
		zasobnik[i] = wzor.zasobnik[i];
	}
	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Tszuflada {
		union {
			std::vector<double> zestaw;
		std::string tekst;
		Tblaster pistolet;
	};
	enum Typ_wariantu { tryb_wektorowy, tryb_tekstowy, tryb_klasowy }; 
		Typ_wariantu wyroznik; 
public:
	Tszuflada();
	~Tszuflada();
	void co_teraz_w_unii();
		Tszuflada & operator= (const vector<double> &wartosc);
	Tszuflada& operator= (const string& napis);
	Tszuflada& operator=(const Tblaster& blaster);
};
//*****************************************************************************************************************
Tszuflada::Tszuflada() {
		new (&zestaw) std::vector<double>; // zak³adamy obiekt klasy vector
	wyroznik = tryb_wektorowy;
}
//*****************************************************************************************************************
Tszuflada::~Tszuflada() 
{
	if (wyroznik == tryb_tekstowy) {
		tekst.~string(); // likwidujemy string
		cout << "destrukcja stringu " << endl;
	}
	else if (wyroznik == tryb_tekstowy) { // czyli jeœli obecnie tryb_wektorowy
		zestaw.~vector<double>(); // to likwidujemy wektor
		cout << "destrukcja vectora " << endl;
	}
	else {
		pistolet.~Tblaster();
		cout << "destruktor blastera " << endl;
	}
}
//*****************************************************************************************************************
void Tszuflada::co_teraz_w_unii() 
{
	switch (wyroznik)
	{
	case tryb_wektorowy:
		cout << "W unii jest wektor liczb: ";
		for (auto n : zestaw) cout << n << ", ";
		cout << endl;
		break;
	case tryb_tekstowy:
		cout << "W unii jest tekst: " << tekst << endl;
		break;
	case tryb_klasowy:
		cout << "W unii jest blaster: ";
		pistolet.info();
		cout << endl;
		break;
	}
}
//*****************************************************************************************************************
Tszuflada& Tszuflada::operator=(const std::string& napis) 
{
	if (wyroznik == tryb_tekstowy) { // czyli jeœli ju¿ jesteœmy w trybie tekstowym...
		tekst = napis; // ...to wystarczy przypisaæ tekst 9
	}
	else // jeœli zaœ wczeœniej by³ wektor...
	{
		if (wyroznik == tryb_wektorowy)
		zestaw.~vector<double>(); // likwidujemy wektor Ba
		else pistolet.~Tblaster();
		new (&tekst) std::string(napis); // budujemy obiekt typu string Bb
		wyroznik = tryb_tekstowy;
	}
	return *this;
}
//*****************************************************************************************************************
Tszuflada& Tszuflada::operator=(const vector<double>& wek) 
{
	if (wyroznik == tryb_wektorowy) { // jeœli ju¿ jest w³aœciwy tryb wektorowy
		zestaw = wek; // to wystarczy skopiowaæ treœæ przys³anego Bd
	}
	else // jeœli zaœ tryb siê nie zgadza
	{
		if (wyroznik == tryb_tekstowy)
			tekst.~string(); // likwidujemy dotychczasowy obiekt typu string Be
		else pistolet.~Tblaster();
		new (&zestaw) vector<double>(wek); // i budujemy obiekt klasy vector Bf
		wyroznik = tryb_wektorowy;
	}
	return *this;
}
Tszuflada& Tszuflada::operator=(const Tblaster& blaster) {
	if (wyroznik == tryb_klasowy) { 
		pistolet = blaster; // 
	}
	else
	{
		if (wyroznik == tryb_tekstowy)
			tekst.~string();
		else zestaw.~vector<double>(); //
		pistolet = blaster;
		wyroznik = tryb_klasowy;
	}
	return *this;
}
	;
//*****************************************************************************************************************
int main()
{
	Tszuflada u;
	u.co_teraz_w_unii();
	u.zestaw.push_back(3.3);
	u.zestaw.push_back(2.2);
	u.co_teraz_w_unii();
	u = "Stal dwor szlachecki, z drzewa, lecz podmurowany";
	u.co_teraz_w_unii();
	cout << "Pracujemy... " << u.tekst.substr(5, 24) << endl; // przyk³ad korzystania Bj
	// wpisanie do unii innego typu treœci (wektora liczb)
	u = vector<double>{ 0, 0.1,0.2,0.3 }; // operatorem przypisania Ca
	u.zestaw[2] = 44.4; // ewentualne korzystanie Cb
	u.co_teraz_w_unii();
	// przypisanie tak¿e wektora, ale z innym zestawem liczb
	u = vector<double>{ 99.1, 98.2, 97.3, 96.4, 95.5 }; // operatorem przypisania Cc
	u.co_teraz_w_unii();
	// zmiana trybu z powrotem na tekstowy
	u = "Krotkie by³y Sedziego z synowcem witania";
	u.co_teraz_w_unii();
	u = "Slusznie Wozny powiadal, ze w zamkowej sieni";
	u.co_teraz_w_unii();
	Tblaster karabin(20);
	u = karabin;
	u.co_teraz_w_unii();
	u = vector<double>{ 1.0, 2.2, 3,3, 4.4 };
	u.co_teraz_w_unii();
	u = Tblaster(3);
	u.co_teraz_w_unii();
	u = Tblaster(0.2);
	u.co_teraz_w_unii();
	u = "Natenczas Wojski...";
	u.co_teraz_w_unii();
}