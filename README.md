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
    
The inclusive_scan function takes an input array and a binary operation (in this case plus) and returns an array containing the result of the inclusive scan operation. In this example, we use addition as the binary operation.
    
    2. The second implementetion completes a parallel scan algorithm to compute the prefix sums of an input array. It is excluse which means it computes computes the sum of all elements up to, but not including, the current element. It performs an up-sweep phase, where adjacent elements are added together in a binary tree fashion, and a down-sweep phase, where elements are rearranged to propagate the sum values down the tree. The result is stored in the output array and printed as the prefix sums of the input array.
    Here is the pseudocode:
    1. Create an input array.
    2. Create an output array of the same size as the input array.
    3. Determine the size of the input array and calculate the logarithm base 2 of the size, storing it in logn.
    4. Perform the up-sweep phase:
       4.1. Iterate over d from 0 to logn (exclusive).
       4.2. Parallelize the loop using OpenMP.
       4.3. Iterate over k from 0 to n, incrementing by 1 << (d + 1) each time.
       4.4. Add the element at index k + (1 << (d + 1)) - 1 to the element at index k + (1 << d) - 1 in the input array.
    5. Set the last element of the input array to 0.
    6. Perform the down-sweep phase:
       6.1. Iterate over d from logn - 1 down to 0 (inclusive).
       6.2. Parallelize the loop using OpenMP.
       6.3. Iterate over k from 0 to n, incrementing by 1 << (d + 1) each time.
       6.4. Store the value of the element at index k + (1 << d) - 1 in a temporary variable t.
       6.5. Assign the value of the element at index k + (1 << (d + 1)) - 1 to the element at index k + (1 << d) - 1.
       6.6. Add the value of the temporary variable t to the element at index k + (1 << (d + 1)) - 1.
    7. Copy the elements of the input array to the output array.
    8. Print the prefix sums from the output array.
And the algorithm of this implementation:
    1. Initialize the input array and output array.
2. Determine the size of the input array (n).
3. Calculate the number of levels in the binary tree (logn).
4. Perform the Up-sweep phase:
   4.1. For d = 0 to logn:
       4.1.1. For k = 0 to n with a step of 2^(d+1):
               Update input[k + 2^(d+1) - 1] by adding input[k + 2^d - 1].

5. Set the last element of the input array to 0.
6. Perform the Down-sweep phase:
   6.1. For d = logn - 1 down to 0:
   6.2. For k = 0 to n with a step of 2^(d+1):
       Store the value of input[k + 2^d - 1] in a temporary variable (t).
       Update input[k + 2^d - 1] with the value of input[k + 2^(d+1) - 1].
       Update input[k + 2^(d+1) - 1] by adding the stored temporary variable (t).
7. Copy the elements from the input array to the output array.
8. Print the elements of the output array as the prefix sums.


    
