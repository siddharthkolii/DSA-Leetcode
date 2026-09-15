/*
QUESTION:-
Given an integer array nums and an integer k, return true if there are
two distinct indices i and j in the array such that nums[i] == nums[j]
and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

/*
APPROACH (Optimal - Hash Map):-
-> Store each number and its most recent index in an unordered_map.
-> Traverse the array from left to right.
-> If the current number already exists, check the distance between
   the current index and its previous index.
-> If the distance is <= k, return true.
-> Update the number's index to the current index.
-> If no valid pair is found, return false.
*/

// CODE:-

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> lastIndex;

        for(int i = 0; i < nums.size(); i++) {

            if(lastIndex.find(nums[i]) != lastIndex.end()) {

                if(i - lastIndex[nums[i]] <= k) {
                    return true;
                }
            }

            lastIndex[nums[i]] = i;
        }

        return false;
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)