/*
QUESTION:-
You are given two integer arrays nums1 and nums2, sorted in non-decreasing
order, and two integers m and n.

Merge nums2 into nums1 as one sorted array.

The final sorted array should not be returned by the function, but instead
be stored inside nums1.

nums1 has enough space to hold the additional elements from nums2.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3,
       nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Example 2:
Input: nums1 = [1], m = 1,
       nums2 = [], n = 0
Output: [1]
*/

/*
APPROACH (Optimal - Two Pointers):-
-> Start from the END of both arrays.
-> Compare the largest remaining elements.
-> Place the larger element at the END of nums1.
-> Move the corresponding pointer backward.
-> Continue until all elements of nums2 are placed.
*/

// CODE:-

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j >= 0) {

            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};

// TIME COMPLEXITY = O(M + N)
// SPACE COMPLEXITY = O(1)