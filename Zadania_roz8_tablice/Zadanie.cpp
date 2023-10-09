// Zadanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std; 
enum class Ruch {
	w_przod, w_tyl, stop
};
char prog[14]{ "programowanie" };
char xyz[3]{ 'x' , 'y', 'z' };
char tabl[10] = { "ABCD" };
void kopiuj_co_2(char tab[], char tab2[]) {
	int i = 0;
	while (tab[i]) {
		tab2[i / 2] = tab[i];
		i += 2;
	}
}
void podziel(char tab[], char parzyste[], char nieparzyste[]) {
	int i{ 0 };
	int j{ 0 };
	int k{ 0 };
	bool parz{ false };
	while (tab[i]) {
		if (parz) {
			parzyste[j] = tab[i];
			j++;
		}
		else {
			nieparzyste[k] = tab[i];
			k++;
		}
		if (tab[i] == ' ') parz = !parz;
		i++;
	}
} 
int main() {
	char tab[73]{ "gdyby kozka nie skakala to by nozki nie zlamala raz dwa trzy kot patrzy" };
	char tab2[50]{};
	kopiuj_co_2(tab, tab2); 
	int i{ 0 };
	while (tab2[i]) {
		cout << tab2[i];
		i++;
	}
	cout << endl;
	int j{ 0 };
	int k{ 0 };
	char parzyste[50]{};
	char nieparzyste[50]{};
	podziel(tab, parzyste, nieparzyste);
	while (parzyste[j]) {
		cout << parzyste[j];
		j++;
	}
	cout << endl;
	while (nieparzyste[k]) {
		cout << nieparzyste[k];
		k++;
	}
	cout << endl;

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
