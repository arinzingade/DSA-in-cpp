#include <iostream>
#include <string>
#include <chrono>

using namespace std;

template <int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}

int main() {
    auto start1 = chrono::high_resolution_clock::now();

    constexpr int res = Factorial<11>::value;

    auto end1 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);

    cout << "Duration: " << duration.count() << " nanoseconds" << endl;
    cout << "Factorial of 10 is: " << res << endl;

    auto start2 = chrono::high_resolution_clock::now();
    const int ans = factorial(11);
    auto end2 = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    cout << "Duration: " << dur.count() << " nanoseconds" << endl;
    cout << "Factorial of 10 is: " << ans << endl;

    return 0;
}
