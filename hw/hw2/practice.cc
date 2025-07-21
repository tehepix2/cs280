// E => T + E | T - E | T
// T => F * T | F / T | F
// F => I | D | ( E )
// I => a | ... | z
// D => 0 | ... | 9

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

bool E(void);
bool T(void);
bool F(void);
bool I(void);
bool D(void);

string s;

int main(int argc, char *argv[]) {
    string t;
    s = t = argc == 2 ? argv[1] : "";
    if (E() && s == "") {
        cout << "The string \"" << t << "\" is in the language." << endl;
    }
    else {
        cout << "The string \"" << t << "\" is not in the language." << endl;
    }
    return 0;
}

bool E(void) { // E => T + E | T - E | T
    if (T()) {
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
            if (E()) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
bool T(void) { // T => F * T | F / T | F
    if (F()) {
        if (s[0] == '*' || s[0] == '/') {
            s = s.substr(1);
            if (T()) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
bool F(void) { // F => I | D | ( E )
    if (I()) {
        return true;
    }
    else if (D()) {
        return true;
    }
    else if (s[0] == '(') {
        s = s.substr(1);
        if (E()) {
            if (s[0] == ')') {
                s = s.substr(1);
                return true;
            }
        }
    }
    return false;
}
bool I(void) { // I => a | ... | z
    if ('a' <= s[0] && s[0] <= 'z') {
        s = s.substr(1);
        return true;
    }
    return false;
}
bool D(void) { // D => 0 | ... | 9
    if ('0' <= s[0] && s[0] <= '9') {
        s = s.substr(1);
        return true;
    }
    return false;
}