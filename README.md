# Parallel-and-Prefix-Algorithm-Implementation

   ### 1. The first code we provided, which is Inclisive Scann This performs an inclusive scan on the input array [3 1 7 0 4 1 6 3] using addition as the binary operation. The result is stored in the output array and printed to the console. The output should be [3 4 11 11 15 16 22 25].

Here is the algorithm for this program:

    1. Initialize the input array and output array.
    2. Perform parallel inclusive scan operation on the input array.
       2.1. Use the par_unseq execution policy to enable parallel execution.
       2.2. Start the inclusive scan operation from the beginning to the end of the input array.
       2.3. Store the results of the inclusive scan in the output array.
       2.4. Use the plus<> operator as the binary operation for the scan.
    3. Print the prefix sums from the output array.
       3.1. Iterate over each element in the output array.
       3.2. Print the element followed by a space.

The inclusive_scan function takes an input array and a binary operation (in this case plus) and returns an array containing the result of the inclusive scan operation. In this example, we use addition as the binary operation.  
 ###   2. The second implementetion completes a parallel scan algorithm to compute the prefix sums of an input array. It is excluse which means it computes computes the sum of all elements up to, but not including, the current element. It performs an up-sweep phase, where adjacent elements are added together in a binary tree fashion, and a down-sweep phase, where elements are rearranged to propagate the sum values down the tree. The result is stored in the output array and printed as the prefix sums of the input array.    
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

   ### 3.


    
