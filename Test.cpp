#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "doctest.h"
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

NumberWithUnits first_km{158,"km"};
NumberWithUnits second_KM{15,"KM"}; //Should return error- big letters
NumberWithUnits second_km{15,"km"};
NumberWithUnits first_m{100,"m"};
NumberWithUnits first_g{15,"g"};
NumberWithUnits first_kg{100,"kg"};

TEST_CASE("plus operan:"){
	CHECK(((first_km+second_km) == NumberWithUnits{173,"km"}));
	CHECK_THROWS((first_km+second_KM)); //Should return error- big letters
	CHECK(((first_km+first_m) == NumberWithUnits{158.1,"km"}));  //km+m=km
	CHECK(((first_m+first_km) == NumberWithUnits{1100,"m"}));    //m+km=m
	CHECK(((first_kg+first_g) == NumberWithUnits{100.015,"kg"}));//kg+g=g
	CHECK(((first_g+first_kg) == NumberWithUnits{1015,"g"}));    //g+kg=g
	CHECK_THROWS(((first_m+first_kg))); //Should return error- not the same kind of type.
}

TEST_CASE("minus operand:"){
	CHECK(((first_km-second_km) == NumberWithUnits{143,"km"}));
	CHECK_THROWS((first_km-second_KM)); //Should return error- big letters
	CHECK(((first_km-first_m) == NumberWithUnits{157.9,"km"})); //km-m=km
	CHECK(((first_m-first_km) == NumberWithUnits{-1400,"m"})); //negetive answer
	CHECK(( (-(first_m-first_km)) == NumberWithUnits{1400,"m"})); // -operand() 
	CHECK(((first_kg-first_g) == NumberWithUnits{99.085,"kg"})); //kg-g=kg
	CHECK(((first_g-first_kg) == NumberWithUnits{-99985,"g"})); //negetive answer
}

TEST_CASE("+= and -= operands:"){
	CHECK(((first_km+=second_km) == NumberWithUnits{173,"km"}));
	CHECK(((first_km-=second_km) == NumberWithUnits{143,"km"}));
}

TEST_CASE("equals operator:"){
	CHECK(((first_km>second_km) == true));
	CHECK_THROWS(first_km.operator == (first_g));
	CHECK(((first_km<second_km) == false));
	CHECK(((first_km>=second_km) == false));
	CHECK(((first_km<=first_km) == true));
	CHECK(((first_km==first_km) == true));
	CHECK(((first_km==second_km) == false));
	CHECK(((first_km!=first_km) == false));
	CHECK(((first_km!=second_km) == true));
	CHECK(((first_kg-first_g) != NumberWithUnits{99.085,"g"})); //kg-g!=kg 
}

TEST_CASE("++ operands:"){
	//first_km = 158, first_kg = 15;
	CHECK(((first_km++) == NumberWithUnits{158,"km"}));
	CHECK(((++first_km) == NumberWithUnits{159,"km"}));
	CHECK(((++first_kg) == NumberWithUnits{15,"km"}));
	CHECK(((first_kg++) == NumberWithUnits{16,"km"}));
}

TEST_CASE("--operands:"){
	CHECK(((first_km--) == NumberWithUnits{158,"km"}));
	CHECK(((--first_km) == NumberWithUnits{157,"km"}));
	CHECK(((--first_kg) == NumberWithUnits{100,"kg"}));
	CHECK(((first_kg--) == NumberWithUnits{99,"kg"}));
}

TEST_CASE("multiply:"){
	CHECK(((first_km*3) == NumberWithUnits{474,"km"}));
	CHECK(((4*second_km) == NumberWithUnits{60,"km"}));
	CHECK(((4*first_kg) == NumberWithUnits{400,"kg"}));
	CHECK_THROWS((4*second_KM)); //Should return error- big letters
}


TEST_CASE("input:"){
	NumberWithUnits a{700, "kg"};
	istringstream sample_input_a{"700 [ kg ]"};
 	sample_input_a >> a;
	CHECK((a==NumberWithUnits{700, "kg"}));
	
	NumberWithUnits b{900, "g"};
	istringstream sample_input_b{"900  g ]"};
	CHECK_THROWS((sample_input_b >> b)); //Should return error- missing '[' 
	
	NumberWithUnits c{900, "g"};
	istringstream sample_input_c{"900 [G]"};
	CHECK_THROWS((sample_input_c >> c)); //Should return error- big letter 
	
	NumberWithUnits d{900, "g"};
	istringstream sample_input_d{"900  "};
	CHECK_THROWS((sample_input_d >> d)); //Should return error- missing '[type]
	
	NumberWithUnits e{900, "g"};
	istringstream sample_input_e{"[ kg ] 900 "};
	CHECK_THROWS((sample_input_e >> e)); //Should return error- not the right order
}


