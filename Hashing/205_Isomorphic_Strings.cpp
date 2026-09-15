/*
QUESTION:-
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced
to get t.

All occurrences of a character must be replaced with another character
while preserving the order of characters. No two different characters
may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
*/

/*
APPROACH (Optimal - Two-Way Mapping):-
-> Maintain a mapping from characters of s to characters of t.
-> Also maintain a mapping from characters of t to characters of s.
-> For every pair of characters, check whether an existing mapping
   is consistent.
-> If either mapping conflicts, return false.
-> Otherwise, create both mappings.
-> If all characters are consistent, return true.
*/

// CODE:-

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for(int i = 0; i < s.size(); i++) {

            char a = s[i];
            char b = t[i];

            if(sToT.find(a) != sToT.end() && sToT[a] != b) {
                return false;
            }

            if(tToS.find(b) != tToS.end() && tToS[b] != a) {
                return false;
            }

            sToT[a] = b;
            tToS[b] = a;
        }

        return true;
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)