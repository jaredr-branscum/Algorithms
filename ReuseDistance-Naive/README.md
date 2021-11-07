# Stack-Based Reuse Distance Algorithm
Input: Given a trace that contains a list of distinct integers _A_.

Output: Find the reuse distances for each integer in the list and keep count of these reuse distances.

Time Complexity: O(n) where n = number of unique integers in the list

Reuse distance: given an index i in _A_, examine the integers between integer _a_ at index _i_ and the previous occurence of integer _a_ in the list. The reuse distance is defined as the number of distinct integers found in between those two integers. For example, if _a_ is found again right behind it in the list, meaning they're adjacent to each other, then the reuse distance for _A_\[_i_\] = 0. However, suppose _a_ = 1 and _i_ = 5 and you're looking at the following part of the trace 100421. Notice that the distinct integers are 0,4, and 2. Thus, the reuse distance for _A_\[_i_\] = 3. If _a_ is never found again in the trace, then the reuse distance is considered infinity.

# Example Answer Key Histogram for testing

test-data-1.txt 
Reuse Distance: infinity Count: 1
        Reuse Distance: 0 Count: 5

test-data-2.txt
Reuse Distance: infinity Count: 2
        Reuse Distance: 0 Count: 0
         Reuse Distance: 1 Count: 4

test-data-3.txt
Reuse Distance: infinity Count: 3
        Reuse Distance: 0 Count: 0
         Reuse Distance: 1 Count: 0
         Reuse Distance: 2 Count: 3

test-data-4.txt
Reuse Distance: infinity Count: 7
        Reuse Distance: 0 Count: 0

test-data-5.txt
Reuse Distance: infinity Count: 3
        Reuse Distance: 0 Count: 1
         Reuse Distance: 1 Count: 2
         Reuse Distance: 2 Count: 1

# Runnable executable
Inside the tests directory, the reuse-stack-unit.exe executable runs the unit tests for the reuse-stack algorithm

# Future Work
Release tree-based O(logN) solution with unit tests or it can be left as an exercise for the reader :)
Build usable static and dynamic library for public use
Refactor code to work with various data types besides integers, consider implementing templates
Refactor code to work with various dataset formats

