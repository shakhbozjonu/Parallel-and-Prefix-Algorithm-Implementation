# Parallel-and-Prefix-Algorithm-Implementation

1. The first code we provided, which is Inclisive Scann This performs an inclusive scan on the input array [3 1 7 0 4 1 6 3] using addition as the binary operation. The result is stored in the output array and printed to the console. The output should be [3 4 11 11 15 16 22 25].

Here is the pseudocode for this algorithm:
input = [3, 1, 7, 0, 4, 1, 6, 3]
output = array of size input.size

// Perform parallel inclusive scan
output = inclusive_scan(input, plus)

// Printing result
for x in output:
    print x
    
    2.
ok
