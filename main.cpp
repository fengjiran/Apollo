#include <iostream>
#include "header/test.h"
#include "header/cvdef.h"
#include "header/cvconfig.h"

using namespace std;

CV__DEBUG_NS_BEGIN
const int a = 10;
CV__DEBUG_NS_END

int main() {
    cout << "Hello, World!" << endl;
    cout << debug_build_guard::a << endl;
//    cout << CV__DEBUG_NS_BEGIN << endl;
    return 0;
}