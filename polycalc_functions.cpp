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





//rounds float to string with precision
//r_f_t_s = rounded float to string
string r_f_t_s(float float_number){
    string float_string;
    stringstream stream;

    //set precision to 2
    stream.precision(2);
    stream << fixed;

    //convert float to string
    stream << float_number;
    float_string = stream.str();

    if( float_string[float_string.size() - 1] == '0' && float_string[float_string.size() - 2] == '0' ) {
        float_string.pop_back();
        float_string.pop_back();
        float_string.pop_back();
    }
    else if (float_string[float_string.size() - 1] == '0') float_string.pop_back();

    return float_string;
}





// seperates a long equation into unit polynomials in an array with the operator that comes forward;
vector<string> monomial_separator(string str) {
    vector<string> v;
    string s = "";
    int i;
    for(i=0;i<str.size();i++){
        if(str[i]== '+'){
            v.push_back(s);
            s.clear();
            if (str[i] = '+') s = '+';
            }

        else if (str[i]=='-') {
            v.push_back(s);
            s.clear();
            if (str[i] = '-') s = '-';
        }

        else s+=str[i];
    }
    if(s!="") v.push_back(s);
    return v;

}



// sets value from string of unit polynomial to respective parts
unit_poly value_setter(string unit_poly_string, char vari){
    unit_poly unit_poly_object;

    //this part erases the first character, operator
    if (unit_poly_string[0] == '-') {
        unit_poly_object.oper = unit_poly_string[0];
        unit_poly_string.erase(0, 1);
    }
    else unit_poly_object.oper = '+';



    //  this chunk finds the constant part;
    string constant_part= "";
    int i;
    for(i=0; i<unit_poly_string.size(); i++) {
        if( unit_poly_string[i] != vari) constant_part += unit_poly_string;
        else break;
    }

    unit_poly_object.constant = stof(constant_part);



    // this chunk reverses the string
    reverse(unit_poly_string.begin(), unit_poly_string.end());


    unit_poly_object.variable = vari;

    //this part finds the power
    string power_part;


    for(i=0; i < unit_poly_string.size() ; i++){
        if (unit_poly_string[i] != '^') power_part += unit_poly_string[i];
        else break;
    }
    reverse(power_part.begin(), power_part.end());
    float float_power_part = stof(power_part);
    unit_poly_object.power = float_power_part;

    return unit_poly_object;
}






// differentiates a unit polynomial
string differentiator(unit_poly unit_poly_object1) {
    string unit_derivative;
    string space = " ";
    if(unit_poly_object1.power == 2) unit_derivative = unit_poly_object1.oper + space + r_f_t_s(unit_poly_object1.constant*2) + unit_poly_object1.variable + ' ';
    else if(unit_poly_object1.power == 1) unit_derivative = unit_poly_object1.oper + space + r_f_t_s(unit_poly_object1.constant) + ' ';
    else if (unit_poly_object1.power == 0) unit_derivative = "";
    else unit_derivative = unit_poly_object1.oper + space + r_f_t_s(unit_poly_object1.constant * unit_poly_object1.power) + unit_poly_object1.variable + '^' + r_f_t_s(unit_poly_object1.power - 1) + ' ';

    return unit_derivative;
}





//displays a unit_poly object
void display_mono(unit_poly u) {
    cout << u.oper << "    " << u.constant << "    " << u.variable << "    " << u.power << endl;
}





//takes a monomial to its default form
string power_1_adder(string mono) {
    int i;

    if(mono.find('x') != string::npos && mono.back() == 'x') mono += "^1";
    else if (mono.find('^') == string::npos) mono += "x^0";

    return mono;
}

//checks validity of the input string
int validity_checker (string str) {
    string valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890^+-";
    int i;
    bool x = true;
    for(i=0; i<str.size(); i++) {
        if (valid_chars.find(str[i]) != string::npos) {
            x = true;
        }
        else {
            x = false;
            break;
        }
    }
    return x;
}
