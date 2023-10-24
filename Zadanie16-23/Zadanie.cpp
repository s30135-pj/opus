#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cstring>
#include "Tbilet.h"
using namespace std;

int main () {
	Tbilet zolty, niebieski; 
		zolty.zapamietaj("Frankfurt", "Paris", Tbilet::ekspres, 1);
	zolty.wypisz();
	niebieski.zapamietaj("Zurich", "Genewa", Tbilet::przyspieszony);
	niebieski.wypisz();
	niebieski.zmien_rodzaj_pociagu(Tbilet::pospieszny); 
		cout << "\nPo zmianie tego biletu...\n";
	niebieski.wypisz();
}
