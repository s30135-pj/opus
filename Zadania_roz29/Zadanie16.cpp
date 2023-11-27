
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	struct kolor {
		unsigned int niebieski : 6;
		unsigned int : 4;
		unsigned int zielony : 5;
		unsigned int : 1;
		unsigned int czerwony : 3;
	};
	union magazyn {
		kolor fragm;
		uint32_t wpis;
	};
	magazyn d;
	cout << "Wpisz date w formacie DDMMRRRR ";
	cin >> d.wpis;
	cout << d.wpis << " --> d.fragm.niebieski = " << d.fragm.niebieski << ", d.fragm.zielony = " << d.fragm.zielony << ", d.fragm.czerwony = " << d.fragm.czerwony << endl;
	cout << hex << "0x" << d.wpis << " --> d.fragm.niebieski = 0x" << d.fragm.niebieski << ", d.fragm.zielony = 0x" << d.fragm.zielony << ", d.fragm.czerwony = 0x" << d.fragm.czerwony << endl;
}