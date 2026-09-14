/*
QUESTION:-
Given a string s, find the first non-repeating character in it and
return its index.

If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
*/

/*
APPROACH (Optimal - Frequency Counting):-
-> Create a frequency array of size 26.
-> Traverse the string and count the frequency of every character.
-> Traverse the string again from left to right.
-> The first character whose frequency is 1 is the first unique character.
-> Return its index.
-> If no character has frequency 1, return -1.
*/

// CODE:-

class Solution {
public:
    int firstUniqChar(string s) {

        int freq[26] = {0};

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        for(int i = 0; i < s.size(); i++) {

            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)