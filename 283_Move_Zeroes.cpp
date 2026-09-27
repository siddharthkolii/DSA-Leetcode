/*
QUESTION:-
Given an integer array nums, move all 0's to the end of it while
maintaining the relative order of the non-zero elements.

You must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
*/

/*
APPROACH (Optimal - Two Pointers):-
-> Use one pointer to track the position where the next non-zero
   element should be placed.
-> Traverse the array with another pointer.
-> Whenever a non-zero element is found, swap it with the element
   at the position pointer.
-> This moves all zeroes to the end while preserving order.
*/

// CODE:-

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int pos = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)