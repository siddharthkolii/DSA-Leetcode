/*
QUESTION:-
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

/*
APPROACH (Optimal - Hash Map):-
-> Traverse the array once.
-> For every element, calculate the required value:
   required = target - nums[i].
-> Check whether the required value already exists in the hash map.
-> If it exists, return its stored index and the current index.
-> Otherwise, store the current value and its index in the map.
*/

// CODE:-

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int required = target - nums[i];

            if(mp.find(required) != mp.end()) {
                return {mp[required], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)