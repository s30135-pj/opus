
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional> 
using namespace std;
int algorytm_zliczajacy(vector<int> pojemnik, function<bool(int)> orzecznik = [] (int licz) {
	if (licz > 0) return true;
	else return false;
	})
{
	int licznik_spelniajacych = 0;
	for (int element : pojemnik)
	{
		if (orzecznik(element))
			licznik_spelniajacych++;
	}
	return licznik_spelniajacych;
}

int main() {
	int war = 50;
	int parametr =5;
	vector<double> v{ 1.2, 3.4,3.2,3.22,1.22,2.33 };
	auto lambda_dodajaca = [war](int ar1, int ar2) {
		return ar1 + ar2 + war;
		};
	cout << lambda_dodajaca(100, 200);
	auto lamda_mnoz = [parametr](double liczba) {
		cout << liczba * parametr << endl;
		};

	auto czytaj = [](double liczba) {
		cout << liczba << endl;
		};
	for_each(v.begin(), v.end(), lamda_mnoz);
	for_each(v.begin(), v.end(), czytaj);
	int prog = 5;
	vector<int> v2{ -1, -2, 32, 12, -232, 1212, 323, -3223, 1212, 55 };
	cout << algorytm_zliczajacy(v2) << endl;
	cout << algorytm_zliczajacy(v2, [prog](int licz) {
		if (licz >= prog) return true;
		else return false;
		}) << endl;
	vector<double> v3;
	v3.resize(v2.size());
	try {
		transform(v2.begin(), v2.end(), v3.begin(),
			[](int l) throw(domain_error) {
				string msg = "Zla liczba "  + to_string(l);
			if (l == 55 || l == 0) throw domain_error(msg);
			return 1 / (double)l;
			});
	}
	catch (domain_error err) {
		cout << err.what() << endl;
	}
	for (auto el : v3) cout << el << endl;
}