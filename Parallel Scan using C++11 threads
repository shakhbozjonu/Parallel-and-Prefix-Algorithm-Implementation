#include <iostream>
#include <vector>
#include <thread>
#include <cmath>

using namespace std;

void parallel_scan(vector<int>& input, vector<int>& output) {
    int n = input.size();
    int logn = ceil(log2(n));
    int num_threads = thread::hardware_concurrency();
    vector<thread> threads(num_threads);

    // Up-sweep phase
    for (int d = 0; d < logn; ++d) {
        int step = 1 << (d + 1);
        for (int t = 0; t < num_threads; ++t) {
            threads[t] = thread([&, t]{
                for (int k = t * step; k < n; k += num_threads * step) {
                    input[k + step - 1] += input[k + (step >> 1) - 1];
                }
            });
        }
        for (auto& t : threads) t.join();
    }

    // Down-sweep phase
    input[n - 1] = 0;
    for (int d = logn - 1; d >= 0; --d) {
        int step = 1 << (d + 1);
        for (int t = 0; t < num_threads; ++t) {
            threads[t] = thread([&, t]{
                for (int k = t * step; k < n; k += num_threads * step) {
                    int temp = input[k + (step >> 1) - 1];
                    input[k + (step >> 1) - 1] = input[k + step - 1];
                    input[k + step - 1] += temp;
                }
            });
        }
        for (auto& t : threads) t.join();
    }

    // Copy result to output array
    copy(input.begin(), input.end(), output.begin());
}

int main() {
    vector<int> input = {3, 1, 7, 0, 4, 1, 6, 3};
    vector<int> output(input.size());

    // Perform parallel scan
    parallel_scan(input, output);

    // Print result
    cout << "The prefix sums: ";
    for (int x : output) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
