/*
QUESTION:-
Given an integer array nums and an integer val, remove all occurrences
of val in nums in-place.

The relative order of the elements may be changed.

Return the number of elements in nums which are not equal to val.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5
*/

/*
APPROACH (Optimal - Two Pointers):-
-> Use pos to represent the position where the next valid element
   should be placed.
-> Traverse the array.
-> If nums[i] is not equal to val, place it at nums[pos].
-> Increment pos.
-> At the end, pos is the number of elements remaining.
*/

// CODE:-

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int pos = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != val) {
                nums[pos] = nums[i];
                pos++;
            }
        }

        return pos;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)