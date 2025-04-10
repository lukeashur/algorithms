#include <iostream>
using namespace std;

void collatz(int n) {
    cout << "Start: " << n << endl;
    while (n !=1 ) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    cout << "1\n";
}

int main() {
    int values[] = {27, 37, 42};
    for (int n : values) {
        collatz(n);
        cout << "-------------\n";
    }
    return 0;
}