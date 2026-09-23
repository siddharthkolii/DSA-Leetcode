/*
QUESTION:-
Given an unsorted array of integers nums, return the length of the longest
consecutive elements sequence.

You must write an algorithm that runs in O(N) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

/*
APPROACH (Optimal - Hash Set):-
-> Store all numbers in an unordered_set.
-> A number is the start of a sequence only if num - 1 does not exist.
-> From each starting number, keep checking num + 1.
-> Track the longest sequence.
*/

// CODE:-

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for(int num : s) {

            if(s.find(num - 1) == s.end()) {

                int current = num;
                int length = 1;

                while(s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)