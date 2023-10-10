// Zadanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream> 

using namespace std; 

void dwojkowo(int liczba, int ktora = 4);
int odczyty[16]{0,1,2,3,4,5,6,7,8,0,9,10,11,0,12, 112};
int main() {

	for (int i = 1; i < 16; i++) {
		if (odczyty[i] > 0) {
			cout << "Kombinacja ";
			dwojkowo(i);
			cout << "--> " << odczyty[i] << " razy" << endl;
		}
	}
	cout << "A teraz odwrotnie:" << endl;
	for (int i = 15; i > 0; i--) {
		if (odczyty[i] > 0) {
			cout << "Kombinacja ";
			dwojkowo(i);
			cout << "--> " << odczyty[i] << " razy" << endl;
		}
 }
}

void dwojkowo(int liczba, int ktora) {
	int reszta = liczba % 2;
	if (liczba > 1) {
		dwojkowo(liczba / 2, ktora-1);
	}
	if (reszta == 1) {
		switch (ktora) {
		case 4:
			cout << "DGF ";
			break;
		case 3:
			cout << "HEC ";
			break;
		case 2:
			cout << "GER ";
			break;
		case 1:
			cout << "FRS ";
			break;
		}
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
