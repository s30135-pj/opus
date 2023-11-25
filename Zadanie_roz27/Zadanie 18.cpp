
#include <iostream>
#include <cstring> // dla funkcji strlen, memcpy
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Twizytowka
{
public:
	char* wsk_nazwiska{ nullptr };
	int dl_tablicy{ 0 };
	int rok_urodzenia{ 0 };
	explicit Twizytowka(const char* nazw, int rok)
	{
		dl_tablicy = strlen(nazw) + 1;
		wsk_nazwiska = new char[dl_tablicy];
		memcpy(wsk_nazwiska, nazw, dl_tablicy);
		rok_urodzenia = rok;
	}
	//------------------
	~Twizytowka()
	{
		if (!wsk_nazwiska) return;
		delete[] wsk_nazwiska;
	}
	//------------------
	Twizytowka(const Twizytowka& inny)
	{
		dl_tablicy = inny.dl_tablicy;
		wsk_nazwiska = new char[dl_tablicy];
		memcpy(wsk_nazwiska, inny.wsk_nazwiska, dl_tablicy);
		rok_urodzenia = inny.rok_urodzenia;
		cout << "Konstrukor Kopiujacy utworzy³: ";
		przedstaw_sie();
	};
	//------------------
	// konstruktor przenosz¹cy 5
	Twizytowka(Twizytowka&& inny)
	{
		// kopiujemy sk³adniki
		wsk_nazwiska = inny.wsk_nazwiska;
		dl_tablicy = inny.dl_tablicy;
		rok_urodzenia = inny.rok_urodzenia;
		// zacieramy œlady po przejêciu tablicy
		inny.wsk_nazwiska = nullptr;
		inny.dl_tablicy = 0;
		// inny.rok_urodzenia = 0; // szkoda czasu Ba
		cout << "Konstruktor PRZENOSZACY: ";
		przedstaw_sie();
	}
	//----------------------------
	Twizytowka& operator=(Twizytowka&&inny) {
		if (&inny != this) {
			delete[] wsk_nazwiska;
			wsk_nazwiska = inny.wsk_nazwiska;
			dl_tablicy = inny.dl_tablicy;
			rok_urodzenia = inny.rok_urodzenia;
			inny.wsk_nazwiska = nullptr;
		}
		cout << "Operator przenoszacy: ";
		przedstaw_sie();
		return *this;
	}
	void przedstaw_sie()
	{
		cout << wsk_nazwiska << ", ur. " << rok_urodzenia << endl;
	}
	void swap(Twizytowka& czerwony)
	{
		Twizytowka plast = std::move(*this); 
			* this = std::move(czerwony); 
			czerwony = std::move(plast); 
	}
};
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Twizytowka daj_rwartosc(int ktory)
	{
		Twizytowka a("Adam", 1980);
		Twizytowka k("Kazia", 1931);
		Twizytowka z("Zenek", 2001);
		if (ktory == 1)
			return a;
		else if (ktory == 2)
			return k;
		else
			return z;
	}

//*****************************************************************************************************************
int main()
{
	for (int i = 0; i < 3; ++i)
	{
		Twizytowka wybraniec = daj_rwartosc(i); 
			cout << "w main: ";
		wybraniec.przedstaw_sie(); 
	}
	Twizytowka wyb1("Franek", 1988);
	Twizytowka wyb2("Sranek", 1991);

	wyb1.swap(wyb2);

	wyb1.przedstaw_sie();
}
