#include <iostream>
#include <vector>
#include <numeric>
#include <execution>
using namespace std;

int main() {
    vector<int> input = {3, 1, 7, 0, 4, 1, 6, 3};
    vector<int> output(input.size());

    // Perform parallel inclusive scan
    inclusive_scan(execution::par_unseq, input.begin(), input.end(), output.begin(), plus<>());

    // Print result
    cout << "Prefix sums: ";
    for (int x : output) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
