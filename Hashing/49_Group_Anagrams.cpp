/*
QUESTION:-
Given an array of strings strs, group the anagrams together.

You can return the answer in any order.

An anagram is a word formed by rearranging the letters of another word,
using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output:
[["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]

Output:
[[""]]

Example 3:
Input: strs = ["a"]

Output:
[["a"]]
*/

/*
APPROACH (Optimal - Hash Map + Frequency Signature):-
-> Two anagrams have exactly the same frequency of every character.
-> Create a frequency array of size 26 for every word.
-> Convert this frequency array into a string key.
-> Use an unordered_map where:
      key   = frequency signature
      value = all words having that signature
-> Words with the same frequency signature are anagrams.
-> Return all the groups.
*/

// CODE:-

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string word : strs) {

            int freq[26] = {0};

            for(char ch : word) {
                freq[ch - 'a']++;
            }

            string key;

            for(int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        for(auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N * K)
// SPACE COMPLEXITY = O(N * K)