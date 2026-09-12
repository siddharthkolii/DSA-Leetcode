/*
QUESTION:-
Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

/*
APPROACH (Optimal - Hash Set):-
-> Traverse the array once.
-> Store each element in an unordered_set.
-> Before inserting an element, check if it already exists.
-> If it exists, a duplicate is found, so return true.
-> If the entire array is traversed without finding a duplicate,
   return false.
*/

// CODE:-

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

        for(int i = 0; i < nums.size(); i++) {

            if(seen.find(nums[i]) != seen.end()) {
                return true;
            }

            seen.insert(nums[i]);
        }

        return false;
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)