// Zadanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream> 
#include <vector>
using namespace std; 
vector<vector<int>> tablica { { 0, 1, 2, 3}, { 10, 11, 12, 13 } };
vector<vector<int>> tablica2;
vector<vector<int>> tablica3;

vector<vector<int>> tablica4{ 3, vector<int>(7, 2)};

vector<vector<double>> dane{ { 1.1, 2.2, 3.3, 4.4, 5.5}, {6.6, 7.7, 8.8, 9.9, 10.10 }, {11.11, 12.12, 13.13, 14.14, 15.15} };
void potroj(vector<double> &wek);
int main() {
	tablica2.resize(2);
	for (int i = 0; i < tablica2.size(); i++) {
		tablica2[i].resize(4);
		for (int j = 0; j < tablica2[i].size(); j++) {
			tablica2[i][j] = i * 10 + j;
		}
	}
	for (auto elem : tablica2) {
		for (auto el : elem) {
			cout << el << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < 2; i++) {
		vector<int> chwilowa_tablica;
		for (int j = 0; j < 4; j++) {
			chwilowa_tablica.push_back(i * 10 + j);
		}
		tablica3.push_back(chwilowa_tablica);
	}
	for (auto elem : tablica3) {
		for (auto el : elem) {
			cout << el << ' ';
		}
		cout << endl;
	}
	tablica4.pop_back();
	tablica4[1].resize(10);
	while (tablica4[0].size() > 4) {
		tablica4[0].pop_back();
	}
	for (auto elem : tablica4) {
		for (auto el : elem) {
			cout << el << ' ';
		}
		cout << endl;
	}
	potroj(dane[2]);
	for (auto elem : dane) {
		for (auto el : elem) {
			cout << el << ' ';
		}
		cout << endl;
	}
}
void potroj(vector<double>& wek) {
	for (int i = 0; i < wek.size(); i++) {
		wek[i] *= 3;
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
