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

   ### 3. The code implements a parallel scan algorithm using multiple threads (C++11 threads) to compute the prefix sums of an input vector. It splits the computation into an up-sweep phase, where adjacent elements are combined, and a down-sweep phase, where values are updated and swapped to compute the final prefix sums. The algorithm utilizes the hardware concurrency to divide the work among multiple threads, improving the performance of the computation.
   This is the algorithm of the program: 
   1. Create a function named "parallel_scan" that takes references to an input vector and an output vector as parameters.
2. Calculate the size of the input vector and assign it to the variable "n".
3. Divide the input vector into multiple segments based on the number of available hardware threads and assign the segment size to the variable "segment_size".
4. Perform the up-sweep phase:
    4.1. Iterate over the levels of the up-sweep phase from 0 to log2(n).
    4.2. Divide the segments among the hardware threads.
    4.3. For each segment, calculate the start and end indices based on the thread's ID.
    4.4. Perform the scan operation within each segment by adding the value at (k + (1 << d) - 1) to the value at (k + (1 << (d + 1)) - 1).
5. Set the last element of the input vector to 0.
6. Perform the down-sweep phase:
    6.1. Iterate over the levels of the down-sweep phase from log2(n) - 1 to 0.
    6.2. Divide the segments among the hardware threads.
    6.3. For each segment, calculate the start and end indices based on the thread's ID.
    6.4. Perform the scan operation within each segment by swapping the values at (k + (1 << d) - 1) and (k + (1 << (d + 1)) - 1), and then updating the value at (k + (1 << (d + 1)) - 1) by adding the temporarily stored value.
7. Copy the resulting values from the input vector to the output vector.
8. Create the main function:
    8.1. Create an input vector and initialize it with the given values.
    8.2. Create an output vector with the same size as the input vector.
    8.3. Call the "parallel_scan" function with the input and output vectors.
    8.4. Print the resulting prefix sums.



    
