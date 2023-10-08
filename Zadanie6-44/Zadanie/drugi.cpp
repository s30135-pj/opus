#include <iostream>
#include "nagl.h"
using namespace std;
int cztery = 4;
double piec = 5.5;
char szesc = 'F';
void f1()
{
  cout << "Jeden " << jeden << " Dwa " << dwa << " Trzy " << trzy << " Cztery " << cztery << " Piec " << piec << " Szesc " << szesc << endl;
  jeden++;
  dwa *= 2;
  trzy++;
  cztery--;
  piec *= 5;
  szesc--;
  cout << "Jeden " << jeden << " Dwa " << dwa << " Trzy " << trzy << " Cztery " << cztery << " Piec " << piec << " Szesc " << szesc << endl;
}
void f2() {
  cout << "Jeden " << jeden << " Dwa " << dwa << " Trzy " << trzy << " Cztery " << cztery << " Piec " << piec << " Szesc " << szesc << endl;
  jeden++;
  dwa *= 2;
  trzy++;
  cztery--;
  piec *= 5;
  szesc--;
  cout << "Jeden " << jeden << " Dwa " << dwa << " Trzy " << trzy << " Cztery " << cztery << " Piec " << piec << " Szesc " << szesc << endl;
}