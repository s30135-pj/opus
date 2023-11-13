
#include <iostream>
#include <string>
using namespace std;
class Tsamochod {
	class Topona {
		string marka;
	public:
		Topona(string nazwa) : marka{ nazwa } { cout << "Zamontowano opone marki " << marka << endl; };
		~Topona() {
			cout << "Wymontowano opone" << endl;
		}
	};
	class Tdrzwi {
		string typ;
	public:
		Tdrzwi(string nazwa) : typ{ nazwa } { cout << "Zamontowano drzwi typu " << typ << endl; };
		~Tdrzwi() {
			cout << "Wymontowano drzwi" << endl;
		}
	};
	Topona pierwszaOpona;
	Topona drugaOpona;
	Topona trzeciaOpona;
	Topona czwartaOpona;
	Topona piataOpona;
	Tdrzwi pierwszeDrzwi;
	Tdrzwi drugieDrzwi;
public:
	Tsamochod(string po, string dro, string to, string co, string pio, string pd, string dd);
	~Tsamochod() {
		cout << "Samochod rozebrany" << endl;
	}
};

Tsamochod::Tsamochod(string po, string dro, string to, string co, string pio, string pd, string dd) : pierwszaOpona{ Topona(po) },
drugaOpona{ Topona(dro) }, trzeciaOpona{ Topona(to) },
czwartaOpona{ Topona(co) }, piataOpona{ Topona(po) },
pierwszeDrzwi{ Tdrzwi(pd)}, drugieDrzwi{Tdrzwi(dd)} {
	cout << "Samochod gotowy" << endl;
}
int main()
{
	Tsamochod skladak("continental", "continental", "continental", "continental", "continental", "jakiestam", "jakiestam");
}