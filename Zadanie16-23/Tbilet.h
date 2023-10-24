#pragma once
// ------------------------------------
// Plik: Tbilet.h
//------------------------------------
#include <string>
/////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tbilet {
public:
	enum Trodzaj_pociagu { osobowy, przyspieszony, pospieszny, ekspres }; 
		void zapamietaj(std::string sk, std::string dok, Trodzaj_pociagu poc, int kl = 2); 
		void wypisz();
	void zmien_rodzaj_pociagu(Trodzaj_pociagu poc); 
private:
	std::string skad;
	std::string dokad;
	int klasa_kolejowa;
	Trodzaj_pociagu jaki_pociag;
	std::string opis_rodzaju();
	static int wydrukowano_biletow; //
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline void Tbilet::zmien_rodzaj_pociagu(Trodzaj_pociagu poc) 
{
	jaki_pociag = poc;
}