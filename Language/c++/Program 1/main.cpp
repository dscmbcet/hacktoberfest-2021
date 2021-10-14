#include <iostream>
using namespace std;

int main() {
    int sum, sub, mult, div, module;
    int a, b;
    cout << "Enter value of a =" ;
    cin >> a;
    cout << "Enter value of b =" ;
    cin >> b;
    sum = a + b;
    sub = a - b;
    mult = a * b;
    div = a / b;
    module = a % b;
    cout << endl;
    cout << "SUM =" << sum << endl;
    cout << "DIFFERENCE = " << sub << endl;
    cout << "PRODUCT = " << mult << endl;
    cout << "QUOTIENT = " << div << endl;
    cout << "REMAINDER = " << module << endl;

}