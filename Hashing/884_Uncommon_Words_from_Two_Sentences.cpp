/*
QUESTION:-
A sentence is a string of space-separated words where each word consists
of lowercase English letters.

A word is uncommon if it appears exactly once in one sentence and does
not appear in the other sentence.

Given two sentences s1 and s2, return a list of all uncommon words.
You may return the answer in any order.

Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]

Example 2:
Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
*/

/*
APPROACH (Optimal - Hash Map):-
-> Combine the words from both sentences.
-> Use an unordered_map to count the frequency of every word.
-> Traverse the frequency map.
-> A word is uncommon if its frequency is exactly 1.
-> Add such words to the result.
*/

// CODE:-

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string, int> freq;
        vector<string> result;

        string word;

        stringstream ss1(s1);
        while(ss1 >> word) {
            freq[word]++;
        }

        stringstream ss2(s2);
        while(ss2 >> word) {
            freq[word]++;
        }

        for(auto it : freq) {

            if(it.second == 1) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N + M) average
// SPACE COMPLEXITY = O(N + M)