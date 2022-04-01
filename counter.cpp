#include <iostream>
#include <bitset>
#include "counter.h"
#include "my_debug.h"

using namespace std;

counter::counter(counter& c)
{
	cnt = c.cnt;
}

int counter::get()
{
	return cnt;
}

void counter::set(int _cnt)
{
	cnt = _cnt;
}

int counter::operator()(int step)
{
	__DEBUG_INFO__("wywolano operator ()");
	return cnt += step;
}

counter::operator int()
{
	__DEBUG_INFO__("wywolano operator konwersji typu na int");
	return cnt;
}

counter::operator double()
{
	__DEBUG_INFO__("wywolano operator konwersji typu na double");
	return static_cast<double>(cnt);
}

counter& counter::operator+=(int i)
{
	__DEBUG_INFO__("wywolano operator +="); 
	cnt += i;
	return *this;
}

counter& counter::operator+(int i)
{
	__DEBUG_INFO__("wywolano operator +");
	cnt += i;
	return *this;
}

int& counter::operator++()
{
	++cnt;
	return cnt;
}

int counter::operator++(int)
{
	int tmp = cnt;
	++cnt;

	return cnt;
}

int& counter::operator~()
{
	cnt = ~cnt;
	return cnt;
}

counter& operator+(int i, counter& c)
{
	__DEBUG_INFO__("wywolano operator +f");
	c.cnt = c.cnt + i;
	return c;
}

counter& counter::operator=(const counter& c)
{
	if (this == &c)
	{
		__DEBUG_INFO__("wywolano operator kopiujacy dla tego samego obiektu");
		return *this;
	}
	else
		__DEBUG_INFO__("wywolano operator kopiujacy");

	cnt = c.cnt;
	return *this;
}

counter& counter::operator=(counter&& c) noexcept
{
	if (this == &c)
	{
		__DEBUG_INFO__("wywolano operator przeniesienia dla tego samego obiektu");
		return *this;
	}
	else
		__DEBUG_INFO__("wywolano operator przeniesienia");

	cnt = c.cnt;
	c.cnt = 0;
	return *this;
}

ostream & operator << (ostream & s, const counter & c)
{
	s << bitset<8>{static_cast<size_t>(c.cnt)};
	return s;
}

std::istream& operator>>(std::istream& s, counter& c)
{
	s >> c.cnt;
	return s;
}
