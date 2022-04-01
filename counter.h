#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <ostream>
#include "my_debug.h"

class counter
{
private:
	int cnt;

public:
	counter(int init = 0) : cnt(init)
	{
		__DEBUG_INFO__("wywolano konstruktor bezargumentowy/jednoargumentowy");
	}

	counter(counter& c);

	~counter() {};

	int get();
	void set(int);

	int operator()(int step = 1);

	// operatory konwersji
	operator int();
	operator double();

	// operatory dodawania
	counter& operator+=(int);                // counter += int
	counter& operator+(int);                 // counter + int
	friend counter& operator+(int, counter&);// int + counter

	// operator ++i/i++
	int& operator++();
	int operator++(int);

	// operator negacji
	int& operator~();

	// operator wypisywania
	friend std::ostream& operator<<(std::ostream& s, const counter& c);
	friend std::istream& operator>>(std::istream& s, counter& c);

	// operator przypisania
	counter& operator=(const counter&);

	// operator przenoszenia
	counter& operator=(counter&&) noexcept;
};

#endif//COUNTER_H
