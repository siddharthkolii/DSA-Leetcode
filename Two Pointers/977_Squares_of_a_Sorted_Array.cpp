/*
QUESTION:-
Given an integer array nums sorted in non-decreasing order, return an
array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

/*
APPROACH (Optimal - Two Pointers):-
-> The largest square must come from either the leftmost negative number
   or the rightmost positive number.
-> Use left at the beginning and right at the end.
-> Compare abs(nums[left]) and abs(nums[right]).
-> Put the larger square at the END of the result.
-> Move that pointer inward.
-> Continue until all positions are filled.
*/

// CODE:-

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> result(n);

        int left = 0;
        int right = n - 1;

        for(int i = n - 1; i >= 0; i--) {

            if(abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            }
            else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(N)