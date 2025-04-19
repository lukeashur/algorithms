#include <iostream>

using namespace std;

int F_r(int n) {
    if (n <= 2) {
        return 1;
    }
    return n * F_r(n - 1) - F_r(n - 2);
}

int F_i(int n) {
    if (n <= 2) {
        return 1;
    }

    int f_n_minus_1 = 1, f_n_minus_2 = 1, f_n = 0;

    for (int i = 3; i <= n; i++) {
        f_n = i + f_n_minus_2;
        f_n_minus_2 = f_n_minus_1;
        f_n_minus_1 = f_n;
    }
    return f_n;
}

int main() {
    for (int n = 1; n <= 5; n++) {
        cout << "f_r(" << n << ") = " << F_r(n) << "\t f_i(" << n << ") = " << F_i(n) << endl;
    }
    return 0;
}