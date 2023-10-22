#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;
bool zgiecie_ramienia() {
	cout << "Zgiecie ramienia";
	return true;
}
bool zgiecie_przedramienia() {
	cout << "Zgiecie przedramienia";
	return true;
}
bool zgiecie_nadgarstka() {
	cout << "Zgiecie nadgarstka";
	return true;
}
bool obrot_ramienia() {
	cout << "Obrot ramienia";
	return true;
}
bool obrot_przedramienia() {
	cout << "Obrot przedramienia";
	return true;
}
bool obrot_nadgarstka() {
	cout << "Obrot nadgarstka";
	return true;
}
bool (*twsk[6])() = { &zgiecie_ramienia, &zgiecie_przedramienia, &zgiecie_nadgarstka, &obrot_ramienia, &obrot_przedramienia,
&obrot_nadgarstka };
void wykonaj(vector<int> *komendy) {
	while (!komendy -> empty()) {
		switch (komendy -> front()) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			twsk[komendy -> front()]();
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
	vector<int> komendy;
	while (komenda != "koniec") {
		cout << "Wpisz komende: ";
		cin >> komenda;
		if (isdigit(komenda[0]))
		komendy.push_back(stoi(komenda));
		if (komenda == "wykonaj") {
			wykonaj(&komendy);
		}
	}
	
}
