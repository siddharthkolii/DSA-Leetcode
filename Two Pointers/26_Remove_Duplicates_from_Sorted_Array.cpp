/*
QUESTION:-
Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once.

Return the number of unique elements.

Example 1:
Input: nums = [1,1,2]
Output: 2

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5
*/

/*
APPROACH (Optimal - Two Pointers):-
-> Since the array is sorted, duplicates are next to each other.
-> Use pos to store the position of the next unique element.
-> Start from the second element.
-> If nums[i] is different from the previous unique element,
   place it at nums[pos].
-> Return pos as the number of unique elements.
*/

// CODE:-

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int pos = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] != nums[pos - 1]) {
                nums[pos] = nums[i];
                pos++;
            }
        }

        return pos;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)