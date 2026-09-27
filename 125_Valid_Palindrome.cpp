/*
QUESTION:-
A phrase is a palindrome if, after converting all uppercase letters
into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: s = "race a car"
Output: false

Example 3:
Input: s = " "
Output: true
*/

/*
APPROACH (Optimal - Two Pointers):-
-> Use two pointers, left and right.
-> Move left forward while it points to a non-alphanumeric character.
-> Move right backward while it points to a non-alphanumeric character.
-> Compare both characters after converting them to lowercase.
-> If they differ, return false.
-> Continue until the pointers meet.
-> If no mismatch is found, return true.
*/

// CODE:-

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            while(left < right && !isalnum(s[left])) {
                left++;
            }

            while(left < right && !isalnum(s[right])) {
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)