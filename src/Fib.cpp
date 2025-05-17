#include <iostream>
#include <chrono>

double fib_r(int n) {
    if (n < 2) {
        return n;
    }
    return fib_r(n - 1) + fib_r(n - 2);
}

double fib_i(int n) {
    if (n < 2) {
        return n;
    }
    double a = 0, b = 1; // Initialize the first two Fibonacci numbers
    for (int i = 2; i <= n; i++) {
        b = a + b; // Update b to the next Fibonacci number
        a = b - a; // Update a to the previous Fibonacci number
    }
    return b; // Return the nth Fibonacci number
}

double fib_i_3(int n) {
    if (n < 2) {
        return n;
    }
    double prev1 = 0, prev2 = 1, current = 0;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return current;
}

void measure_fibonacci(int duration_seconds, bool use_recursive) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int n = 0;

    while (true) {
        if (use_recursive) {
            fib_r(n); // Measure recursive Fibonacci
        } else {
            fib_i(n); // Measure iterative Fibonacci
        }
        n++;

        auto current_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
        if (elapsed_time >= duration_seconds) {
            break;
        }
    }

    std::cout << "Calculated " << n << " Fibonacci numbers in " << duration_seconds << " seconds using "
              << (use_recursive ? "recursive" : "iterative") << " method." << std::endl;
}

int main() {
    
    int input;
    std::cout << "Enter the number of terms: ";
    std::cin >> input;
    std::cout << "\nn" << "\tRecursive" << "\tIterative" << "\tIterative (3 Variables)" << std::endl;

    for (int n = 0; n < input; n++) {
        std::cout << n << "\t" << fib_r(n) << "\t\t" << fib_i(n) << "\t\t" << fib_i_3(n) << std::endl;
    }

    std::cout << "\nMeasuring Fibonacci calculations...\n";

    std::cout << "\n1 second test:\n";
    measure_fibonacci(1, true);  // Recursive
    measure_fibonacci(1, false); // Iterative

    std::cout << "\n10 seconds test:\n";
    measure_fibonacci(10, true);  // Recursive
    measure_fibonacci(10, false); // Iterative

    std::cout << "\n1 minute test:\n";
    measure_fibonacci(60, true);  // Recursive
    measure_fibonacci(60, false); // Iterative

    return 0;
}