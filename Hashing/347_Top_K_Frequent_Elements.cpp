/*
QUESTION:-
Given an integer array nums and an integer k, return the k most frequent
elements.

You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

/*
APPROACH (Optimal - Hash Map + Bucket Sort):-
-> Count the frequency of every number.
-> Create buckets where the index represents frequency.
-> Put each number into the bucket corresponding to its frequency.
-> Traverse buckets from highest frequency to lowest.
-> Add elements until k elements are collected.
*/

// CODE:-

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for(auto it : freq) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> result;

        for(int i = nums.size(); i >= 1 && result.size() < k; i--) {

            for(int num : buckets[i]) {

                result.push_back(num);

                if(result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)