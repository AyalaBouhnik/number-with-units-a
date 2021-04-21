#include <iostream>
#include <string>
#include "NumberWithUnits.hpp"
using namespace ariel;

namespace ariel{

NumberWithUnits NumberWithUnits:: operator+(const NumberWithUnits n1){return *this;}
NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits n1){return *this;}
NumberWithUnits NumberWithUnits::operator+(){return *this;}
NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits n1){return *this;}
NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits n1){return *this;}
NumberWithUnits NumberWithUnits::operator-(){return *this;}

bool NumberWithUnits::operator<(const NumberWithUnits n1)const{return true;}
bool NumberWithUnits::operator<=(const NumberWithUnits n1)const{return true;}
bool NumberWithUnits::operator>(const NumberWithUnits n1)const{return true;}
bool NumberWithUnits::operator>=(const NumberWithUnits n1)const{return true;}
bool NumberWithUnits::operator==(const NumberWithUnits n1)const{return true;}
bool NumberWithUnits::operator!=(const NumberWithUnits n1)const{return true;}

NumberWithUnits NumberWithUnits::operator++(){return *this;}
NumberWithUnits NumberWithUnits::operator++(const int n1){return *this;}
NumberWithUnits NumberWithUnits::operator--(){return *this;}
NumberWithUnits NumberWithUnits::operator--(const int n1){return *this;}

NumberWithUnits NumberWithUnits::operator*(const double n1){return *this;}
NumberWithUnits operator*(double n1, const NumberWithUnits n2){return n2;}

istream& operator>>(istream& input, NumberWithUnits& n1){return input;}
ostream& operator<<(ostream& output, const NumberWithUnits n1){return cout<<'a';}


}//-closing namespace ariel

