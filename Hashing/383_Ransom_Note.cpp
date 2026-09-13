/*
QUESTION:-
Given two strings ransomNote and magazine, return true if ransomNote
can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
*/

/*
APPROACH (Optimal - Frequency Counting):-
-> Create a frequency array of size 26.
-> Count the frequency of every character in magazine.
-> Traverse ransomNote.
-> For each character, decrease its frequency.
-> If the frequency is already 0, the character is unavailable.
-> Return false if any required character is unavailable.
-> Otherwise, return true.
*/

// CODE:-

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        for(char ch : magazine) {
            freq[ch - 'a']++;
        }

        for(char ch : ransomNote) {

            if(freq[ch - 'a'] == 0) {
                return false;
            }

            freq[ch - 'a']--;
        }

        return true;
    }
};

// TIME COMPLEXITY = O(N + M)
// SPACE COMPLEXITY = O(1)