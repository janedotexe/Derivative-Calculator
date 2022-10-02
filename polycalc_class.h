#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stof;
using std::reverse;
using std::to_string;
using std::stringstream;
using std::fixed;
using std::list;
using std::stoi;
using std::vector;



//standard structure: y = a*x^n
struct unit_poly {
    char oper;
    float constant = 1;
    char variable;
    float power = 0;
};

string r_f_t_s(float ); //rounds float to string with precision
vector<string> monomial_separator(string ); // seperates a long equation into unit polynomials in an array with the operator that comes forward
unit_poly value_setter(string , char ); // sets value from string of unit polynomial to respective parts
string differentiator(unit_poly ); // differentiates a unit polynomial
void display_mono(unit_poly ); //displays a unit_poly object
string power_1_adder(string ); // sets monomial to its default form
int validity_checker (string ); //checks validity of the input string
