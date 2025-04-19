#include <iostream>

using namespace std;

// Function to compute GCD using Euclid's algorithm (by repeated subtraction)
int computeGCD(int a, int b) {
    int m = a;
    int n = b;

    while (n != 0) {
        if (m < n) {
            int temp = m;
            m = n; // Swap m and n
            n = temp;
        }

        int r = m - n;
        m = n;
        n = r;
    }
    return m; // GCD found
}

int main() {
    int a, b;
    cout << "Enter two non-negative integers (a and b): ";
    cin >> a >> b;

    if (a < 0 || b < 0) {
        cout << "Please enter only non-negative integers." << endl;
        return 1;
    }

    if (a == 0 && b == 0) {
        cout << "GCD is undefined when both numbers are zero." << endl;
        return 1;
    }

    int gcd = computeGCD(a, b);
    cout << "The greatest common divisor (GCD) of " << a << " and " << b << " is: " << gcd << endl;

    return 0;
}
