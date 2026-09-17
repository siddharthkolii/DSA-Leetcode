/*
QUESTION:-
Given a non-empty array of integers nums, every element appears twice
except for one. Find that single one.

You must implement a solution with linear runtime complexity and use
only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

/*
APPROACH (Optimal - XOR):-
-> XOR has two important properties:
   1. x ^ x = 0
   2. x ^ 0 = x
-> XOR all elements of the array.
-> Every number appearing twice cancels out.
-> The only remaining number is the single number.
*/

// CODE:-

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;

        for(int num : nums) {
            result = result ^ num;
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)