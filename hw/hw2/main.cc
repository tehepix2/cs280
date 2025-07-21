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

bool A(void);
bool E(void);
bool O(void);
bool P(void);
bool U(void);
bool I(void);
bool C(void);
bool L(void);
bool D(void);

vector <string> strings;

int main() {
    cout << strings.size();
    strings.resize(strings.size() + 1);
    cout << strings.size();
    
    return 0;
}

bool A(void) { // A -> I = E

}

bool E(void) { // E -> P O P | P

}

bool O(void) { // O -> + | - | * | / | **

}

bool P(void) { // P -> I | L | UI | UL | (E)

}

bool U(void) { // U -> + | - | !

}

bool I(void) { // I -> C | CI

}

bool C(void) { // C -> a | b | ... | y | z

}

bool L(void) { // L -> D | DL

}

bool D(void) { // D -> 0 | 1 | ... | 8 | 9

}



