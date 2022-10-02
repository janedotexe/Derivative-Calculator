#include <bits/stdc++.h>
#include "polycalc_class.h"


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


int main(){

    start:
    // a poly is taken
    string poly;
    char v;
    cout << "Enter your polynomial ( Only use charcters like letters, digits and power '^' and plus-minus operators ): " << endl;
    getline(cin, poly);
    cout << "The differentiation is being done with respect to: ";
    cin >> v;

    // white space is removed
    poly.erase(remove_if(poly.begin(), poly.end(), ::isspace), poly.end());

    // this checks if the string contains anything other than the specified characters
    if (validity_checker(poly)) goto pass;
    else {
        cout << "Your string was invalid!" << endl;
        goto start;
    }

    pass:
    /*
    cout << endl;
    cout << "Polynomial: " << poly << endl << endl;
    */

    int i;

    // this stores the indexes of the operators + or -
    vector <int> array_of_operators;



    //this finds out where the plus minus operators are
    char plus = '+';
    char minus = '-';
    for(i=0; i<poly.size(); i++){
        if (poly[i] == minus || poly[i] == plus) {
            array_of_operators.push_back(i);
        }
    }

    // number of monomials
    int size = array_of_operators.size()+1;

    // this seperates a polynomial into a list of monomials;
    vector <string> monomials = monomial_separator(poly);         // this is the list of monomials

    // this prints monomials
    /*
    cout << "Monomials: ";
    for(vector<string>::iterator itr=monomials.begin();itr!=monomials.end();++itr)  {
        cout << *itr << " ";
    }
    cout << endl << endl;
    */



    list <string> updated_monos;          // this is the list of updated monomials in their default form
    string y;
    for (auto x: monomials) {
        y = power_1_adder(x);
        updated_monos.push_back(y);
    }


    // this converts the strings into unit_poly objects
    vector<unit_poly> u;
    for(i =0; i<size; i++) {
        u.push_back(value_setter(updated_monos.front(), v));
        updated_monos.pop_front();
    }

    /*
    cout << "Size of updated monos vector: " << u.size() << endl;


    for(i=0; i<size; i++) {
        cout << "Monomial " << i+1 << " in unit_poly form: ";
        display_mono(u[i]);
    }
    cout << endl;
    */

    string poly_derivative = "";

    for(i = 0; i<size; i++) {
        poly_derivative += differentiator(u[i]);
    }

    if(poly_derivative[0] == '+') poly_derivative.erase(0,2);
    else if (poly_derivative == "") poly_derivative = "0";

    cout << "Derivative of polynomial: " << poly_derivative << endl << endl;


}
