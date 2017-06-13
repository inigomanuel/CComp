#include <iostream>

using namespace std;

struct USCurrency {
    int dollars;
    int cents;
};

USCurrency operator+(const USCurrency m, const USCurrency o) {
    USCurrency tmp = {0, 0};
    tmp.cents = m.cents + o.cents;
    tmp.dollars = m.dollars + o.dollars;

    if(tmp.cents >= 100) {
        tmp.dollars += 1;
        tmp.cents -= 100;
    }
    return tmp;
}
ostream& operator<<(ostream &output, const USCurrency &o)
{
    output << "$" << o.dollars << "." << o.cents;
    return output;
}

int main() {
    USCurrency a = {2, 50};
    USCurrency b = {1, 75};
    USCurrency c = a + b;
    cout << c << endl;
    return 0;
}
