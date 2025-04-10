#include <iostream>
using namespace std;

int F_r(int n) {
    if (n<=2) {
    return 1;
    }
    return n * F_r(n - 1) - F_r(n - 2);
}

int main() {
    for (int n=1; n<=5; n++) {
	    cout << "f(" << n << ") = " << F_r(n) << endl;
    }
    return 0;
}
