#include "PROD.h"
#include <sstream>
std::istream& operator>>(std::istream& is, Prod& a)
{
	std::string s;
	std::stringstream ss;
	getline(is, s);
	a.Name = s;
	getline(is, s);
	ss << s;
	ss >> a.Price;
	return is;
}

std::ostream& operator<<(std::ostream& os, Prod& a)
{
	os << a.Name << "\t" << "\t" << a.Price;
	return os;
}
std::ostream& operator<<(std::ostream& os, Bag& a)
{
	os << a.Name << "\t" << a.Section;
	return os;
}
std::ostream& operator<<(std::ostream& os, Market& a)
{
	os << a.Name << "\t" << a.Section << "\t" << a.Price;
	return os;
}
std::istream& operator>>(std::istream& is, Bag& a)
{
	std::string s;
	getline(is, s);
	a.Name = s;
	getline(is, s);
	a.Section = s;
	return is;
}
std::istream& operator>>(std::istream& is, Market& a)
{
	std::string s;
	std::stringstream ss;
	getline(is, s);
	a.Name = s;
	getline(is, s);
	a.Section = s;
	getline(is, s);
	ss << s;
	ss >> a.Price;
	return is;
}