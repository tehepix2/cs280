// A -> I = E
// E -> P O P | P
// O -> + | - | * | / | **
// P -> I | L | UI | UL | (E)
// U -> + | - | !
// I -> C | CI
// C -> a | b | ... | y | z
// L -> D | DL
// D -> 0 | 1 | ... | 8 | 9

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;
#include <cstring>

bool A(int i);
bool E(int i);
bool O(int i);
bool P(int i);
bool U(int i);
bool I(int i);
bool C(int i);
bool L(int i);
bool D(int i);

vector <string> strings = {"a+b", "b+c", "c+d"};
vector <string> allStrings = {"a+b", "b+c", "c+d"};

int main() {
   
    for (size_t i = 0; i < strings.size(); ++i) {
        if (A(i) && strings[i] == "") {
            cout << "The string \"" << allStrings[i] << "\" is in the language." << "\n";
        }
        else {
            cout << "The string \"" << allStrings[i] << "\" is not in the language." << "\n";
        }
    }
    
    
    return 0;
}

bool A(int loop) { // A -> I = E
    cout << loop;
    return true;
}

bool E(int loop) { // E -> P O P | P
    string backup = strings[loop];

    if (P(loop)) {
        if (O(loop)) {
            if (P(loop)) {
                return true;
            }
        }
        strings[loop] = backup;
    }

    if (P(loop)) {
        return true;
    }

    return false;
}

bool O(int loop) { // O -> + | - | * | / | **
    if ((strings[loop][0] == '+') || (strings[loop][0] == '-') || (strings[loop][0] == '+') || (strings[loop][0] == '+')) {
        strings[loop] = strings[loop].substr(1);
        return true;
    }
    else if (strings[loop].size() >= 2 && strings[loop].substr(0, 2) == "**") {
        strings[loop] = strings[loop].substr(2); 
        return true;
    }
    else if ((strings[loop][0] == '*')) {
        strings[loop] = strings[loop].substr(1);
        return true;
    }
    return false;
}

bool P(int loop) { // P -> I | L | UI | UL | (E)
    string backup = strings[loop];
    if (I(loop)) {
        return true;
    }
    strings[loop] = backup;
    if (L(loop)) {
        return true;
    }
    strings[loop] = backup;
    if (U(loop)) {
        if (I(loop)) {
            return true;
        }
        else if (L(loop)) {
            return true;
        }
    }
    strings[loop] = backup;
    if (strings[loop][0] == '(') {
        strings[loop] = strings[loop].substr(1);
        if (E(loop)) {
            if (strings[loop][0] == ')') {
                strings[loop] = strings[loop].substr(1);
                return true;
            }
        }
    }
    return false;
}

bool U(int loop) { // U -> + | - | !
    if ((strings[loop][0] == '+') || (strings[loop][0] == '-') || (strings[loop][0] == '!')) {
        strings[loop] = strings[loop].substr(1);
        return true;
    }
    return false;
}

bool I(int loop) { // I -> C | CI
    if (!C(loop)) {
        return false;
    }

    while (C(loop)) {
        
    }

    return true;
}

bool C(int loop) { // C -> a | b | ... | y | z
    if ('a' <= strings[loop][0] && strings[loop][0] <= 'z') {
        strings[loop] = strings[loop].substr(1);
        return true;
    }
    return false;
}

bool L(int loop) { // L -> D | DL
    if (!D(loop)) {
        return false;
    }

    while (D(loop)) {
      
    }

    return true;
}

bool D(int loop) { // D -> 0 | 1 | ... | 8 | 9
    if ('0' <= strings[loop][0] && strings[loop][0] <= '9') {
        strings[loop] = strings[loop].substr(1);
        return true;
    }
    return false;
}



