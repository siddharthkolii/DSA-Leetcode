/*
QUESTION:-
Given an array of integers nums and an integer k, return the total number
of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/

/*
APPROACH (Optimal - Prefix Sum + Hash Map):-

-> Keep a running prefix sum.

-> Suppose current prefix sum is sum.

-> We need a previous prefix sum equal to:
      sum - k

   because:

      current prefix - previous prefix = k

-> Store the frequency of every prefix sum in an unordered_map.

-> Initialize mp[0] = 1 because a subarray starting from index 0
   can itself have sum k.

-> For every element:
   1. Add it to the prefix sum.
   2. Check how many times (sum - k) has appeared.
   3. Add that frequency to the answer.
   4. Store the current prefix sum.
*/

// CODE:-

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int num : nums) {

            sum += num;

            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)