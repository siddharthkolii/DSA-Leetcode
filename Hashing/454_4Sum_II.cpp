/*
QUESTION:-
Given four integer arrays nums1, nums2, nums3, and nums4, all of length n,
return the number of tuples (i, j, k, l) such that:

nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

Example 1:
Input:
nums1 = [1,2]
nums2 = [-2,-1]
nums3 = [-1,2]
nums4 = [0,2]

Output: 2

Explanation:
The two tuples are:
(0,0,0,1) -> 1 + (-2) + (-1) + 2 = 0
(1,1,1,0) -> 2 + (-1) + 2 + 0 = 3
*/

/*
APPROACH (Optimal - Hash Map):-
-> Calculate every possible sum of nums1[i] + nums2[j].
-> Store the frequency of each sum in a hash map.
-> Calculate every possible sum of nums3[k] + nums4[l].
-> We need:
      sum1 + sum2 = 0

   Therefore:
      sum1 = -sum2

-> Add the frequency of -sum2 to the answer.
*/

// CODE:-

class Solution {
public:
    int fourSumCount(vector<int>& nums1,
                     vector<int>& nums2,
                     vector<int>& nums3,
                     vector<int>& nums4) {

        unordered_map<int, int> mp;

        for(int a : nums1) {
            for(int b : nums2) {
                mp[a + b]++;
            }
        }

        int count = 0;

        for(int c : nums3) {
            for(int d : nums4) {

                int required = -(c + d);

                if(mp.find(required) != mp.end()) {
                    count += mp[required];
                }
            }
        }

        return count;
    }
};

// TIME COMPLEXITY = O(N²) average
// SPACE COMPLEXITY = O(N²)