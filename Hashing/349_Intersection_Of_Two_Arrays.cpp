/*
QUESTION:-
Given two integer arrays nums1 and nums2, return an array of their
intersection.

Each element in the result must be unique.

You may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
*/

/*
APPROACH (Optimal - Hash Set):-
-> Store all elements of nums1 in an unordered_set.
-> Traverse nums2.
-> If the current element exists in the set, add it to the result.
-> Erase the element after adding it so duplicates are not added.
-> Return the result.
*/

// CODE:-

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> seen(nums1.begin(), nums1.end());
        vector<int> result;

        for(int num : nums2) {

            if(seen.find(num) != seen.end()) {
                result.push_back(num);
                seen.erase(num);
            }
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N + M) average
// SPACE COMPLEXITY = O(N)