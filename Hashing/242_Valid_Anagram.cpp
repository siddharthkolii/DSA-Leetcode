/*
QUESTION:-
Given two strings s and t, return true if t is an anagram of s,
and false otherwise.

An anagram is a word or phrase formed by rearranging the letters
of a different word or phrase, using all the original letters
exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/

/*
APPROACH (Optimal - Frequency Counting):-
-> If the two strings have different lengths, they cannot be anagrams.
-> Create a frequency array of size 26.
-> Traverse both strings.
-> Increment the frequency for characters in s.
-> Decrement the frequency for characters in t.
-> If every frequency becomes 0, the strings are anagrams.
*/

// CODE:-

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) {
            return false;
        }

        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)