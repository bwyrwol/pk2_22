/*
   Zadeklarowac Klase counter (licznik) posiadajaca pola/metody opisane ponizej. Zdefiniowac w programie obiekty klasy counter oraz przetestowac opracowane metody. W metodach wyprowadzac informacje na konsole o wywolaniu danej metody (konstruktora/destruktora, operatora itp.).
   Deklaracje klasy counter umiescic w pliku naglowkowym *.h, natomiast definicje w pliku implementacyjnym *.cpp.

   1. Zadeklarowac pole cnt przechowujace zawartosc licznika.
   2. Dodac do klasy konstruktor bezargumetowy/z argumentem domyslnym inicjujacy pole cnt oraz metody get/set.
   3. Opracowac nastepujace metody (operatory przeladowane)
      - operator przypisania =,
      - konwersji z counter na int oraz counter na double,
      - operator dodawania (counter += int, counter + int, int + counter) [ktory z nich wymaga zaprzyjaznienia z klasa i dlaczego?],
      - operator () (bez argumentu inkrementuje zawartosc licznika o 1, z argumentem - o podana wartosc),
      - operatory post- i pre- inkremetacji (++counter, counter++),
      - operator negacji (~counter),
      - operatory << oraz >> do wyswietlania i pobierania zawartosci licznika ze standardowych strumieni cout i cin [dlaczego wymagaja zaprzyjaznienia?], wyswietlanie zawartosci w postaci np. 8-bitowej liczby binarnej (mozna wykorzystac funkcje bitset - trzeba dolaczyc plik naglowkowy <bitset>),
      - operator przeniesienia zawartosci licznika (w przypadku pola statycznego, po przeniesieniu, mozna wyzerowac licznik zrodlowy).
 */

#include <iostream>
#include "counter.h"
#include "my_debug.h"

using namespace std;

void wyswietl_int(int i)
{
    cout << i << endl;
}

void wyswietl_double(double d)
{
    cout << d << endl;
}


int main()
{
    counter c;
    wyswietl_int(c);
    wyswietl_double(c);

    c = counter(7.3); // c = 7;
    cout << c << endl;

    c();
    cout << c << endl;

    c = c + 4;
    cout << c << endl;

    c = 1 + c;
    cout << c << endl;

    c += 2;
    cout << c << endl;

    cout << "========================================" << endl;

    int i = c;
    cout << endl << c << " " << i << endl;

    cout << "========================================" << endl;

    cout << "Podaj zawartosc licznika: ";
    cin >> c;
    cout << endl << "Licznik: " << c << endl;

    c = c;
    cout << endl << "Licznik: " << c << endl;
    cout << endl << "Licznik: " << (counter)(++c) << endl;
    cout << endl << "Licznik: " << (counter)(c++) << endl;
    cout << endl << "Licznik: " << (counter)(~c) << endl;

    cout << "========================================" << endl;
}
