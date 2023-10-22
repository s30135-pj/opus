#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cstring>
using namespace std;
bool zgiecie_ramienia(double s) {
	cout << "Zgiecie ramienia o "  << s << " stopni";
	return true;
}
bool zgiecie_przedramienia(double s) {
	cout << "Zgiecie przedramienia o " << s << " stopni";
	return true;
}
bool zgiecie_nadgarstka(double s) {
	cout << "Zgiecie nadgarstka o " << s << " stopni";
	return true;
} 
bool obrot_ramienia(double s) {
	cout << "Obrot ramienia o " << s << " stopni";
	return true;
}
bool obrot_przedramienia(double s) {
	cout << "Obrot przedramienia o " << s << " stopni";
	return true;
}
bool obrot_nadgarstka(double s) {
	cout << "Obrot nadgarstka o " << s << " stopni";
	return true;
}
bool (*twsk[6])(double) = { &zgiecie_ramienia, &zgiecie_przedramienia, &zgiecie_nadgarstka, &obrot_ramienia, &obrot_przedramienia,
&obrot_nadgarstka };
void wykonaj(vector<pair<int, double>>* komendy) {
	while (!komendy -> empty()) {
		int nr = komendy->front().first;
		double stopnie = komendy->front().second;
		switch (nr) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			twsk[nr](stopnie);
			cout << endl;
			break;
		default:
			cout << "Podano zly numer" << endl;
			break;
		}
		komendy->erase(komendy->begin());
	}
}

int main(int argc, char* argv[]) {
	string komenda;
	vector<pair<int, double>> komendy;
	while (komenda != "koniec") {
		pair<int, double> dane;
		cout << "Wpisz komende od 0 do 5: ";
		cin >> komenda;
		if (komenda == "wykonaj") {
			wykonaj(&komendy);
		}
		if (komenda.size() == 1 && isdigit(komenda[0]))
			dane.first = stoi(komenda);
		else continue;
		cout << "Podaj o ile stopni poruszyc: ";
		cin >> komenda;
		for (char s : komenda) {
			if (!isdigit(s) && s != '.')
			{
				cout << "Podaj stopnie w formie liczbowej: ";
				cin >> komenda;
			}
		}
		double stopnie = stod(komenda);
		dane.second = stopnie;
		komendy.push_back(dane);
	}
	
}
