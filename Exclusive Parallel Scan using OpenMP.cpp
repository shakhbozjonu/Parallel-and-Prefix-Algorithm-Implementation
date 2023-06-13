#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>

using namespace std;

int main() {
    vector<int> input = {3, 1, 7, 0, 4, 1, 6, 3};
    vector<int> output(input.size());

    int n = input.size();
    int logn = ceil(log2(n));

    // Up-sweep phase
    for (int d = 0; d < logn; ++d) {
#pragma omp parallel for
        for (int k = 0; k < n; k += 1 << (d + 1)) {
            input[k + (1 << (d + 1)) - 1] += input[k + (1 << d) - 1];
        }
    }

    // Down-sweep phase
    input[n - 1] = 0;
    for (int d = logn - 1; d >= 0; --d) {
#pragma omp parallel for
        for (int k = 0; k < n; k += 1 << (d + 1)) {
            int t = input[k + (1 << d) - 1];
            input[k + (1 << d) - 1] = input[k + (1 << (d + 1)) - 1];
            input[k + (1 << (d + 1)) - 1] += t;
        }
    }

    // Copy result to output array
    copy(input.begin(), input.end(), output.begin());

    // Print result
    cout << "Prefix sums: ";
    for (int x : output) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
