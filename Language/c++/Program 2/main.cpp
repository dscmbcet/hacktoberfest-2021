#include <iostream>
using namespace std;

int main() {
    char Ascii_value_Variable;
    cin >> Ascii_value_Variable;
    if (Ascii_value_Variable >= 97 && Ascii_value_Variable <= 122) {
        cout << "\nYou have entered a small letter";
    } else if (Ascii_value_Variable >= 65 && Ascii_value_Variable <= 90) {
        cout << "\nYou have entered a capital letter";
    }

    else if (Ascii_value_Variable >= 0 && Ascii_value_Variable >= 47 || Ascii_value_Variable >= 54 && Ascii_value_Variable <= 64 || Ascii_value_Variable >= 91 && Ascii_value_Variable <= 96 || Ascii_value_Variable >= 123 && Ascii_value_Variable <= 127) {
        cout << "\nYou have entered a special v_charac_varible";
    } else if (Ascii_value_Variable >= 46 && Ascii_value_Variable <= 46) {
        cout << "\nYou have entered a digit ";
    }
}