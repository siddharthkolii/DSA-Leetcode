/*
QUESTION:-
Given a 1-indexed array of integers numbers that is already sorted in
non-decreasing order, find two numbers such that they add up to a
specific target number.

Return the indices of the two numbers as [index1, index2], where
1 <= index1 < index2 <= numbers.length.

You may assume that exactly one solution exists.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
*/

/*
APPROACH (Optimal - Two Pointers):-
-> Place left at the beginning and right at the end.
-> Calculate numbers[left] + numbers[right].
-> If the sum equals target, return the indices.
-> If the sum is smaller than target, move left forward.
-> If the sum is greater than target, move right backward.
-> Because the array is sorted, this eliminates unnecessary searches.
*/

// CODE:-

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {

            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1};
            }

            if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)