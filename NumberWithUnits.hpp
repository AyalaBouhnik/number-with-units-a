#include <iostream>
#include <string>

using namespace std;
namespace ariel{

class NumberWithUnits{

private:
	double number;
	string type;

public:
	NumberWithUnits(double num, string s){
	num=number;
	s=type;
	}

	~NumberWithUnits(){} //destructor


static void read_units(ifstream& f){}

NumberWithUnits operator+(const NumberWithUnits n1);
NumberWithUnits operator+=(const NumberWithUnits n1);
NumberWithUnits operator+();
NumberWithUnits operator-(const NumberWithUnits n1);
NumberWithUnits operator-=(const NumberWithUnits n1);
NumberWithUnits operator-();

bool operator<(const NumberWithUnits n1)const;
bool operator<=(const NumberWithUnits n1)const;
bool operator>(const NumberWithUnits n1)const;
bool operator>=(const NumberWithUnits n1)const;
bool operator==(const NumberWithUnits n1)const;
bool operator!=(const NumberWithUnits n1)const;

NumberWithUnits operator++();
NumberWithUnits operator++(const int n1);
NumberWithUnits operator--();
NumberWithUnits operator--(const int n1);

NumberWithUnits operator*(const double n1) ;
friend NumberWithUnits operator*(double n1, const NumberWithUnits n2);

friend istream& operator>>(istream& input, NumberWithUnits& n1);
friend ostream& operator<<(ostream& output, const NumberWithUnits n1);
};

}//-closing namespace ariel
