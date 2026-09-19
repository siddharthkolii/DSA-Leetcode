/*
QUESTION:-
Given a string s, sort it in decreasing order based on the frequency
of the characters.

The frequency of a character is the number of times it appears in the
string.

Return the sorted string.

Example 1:
Input: s = "tree"
Output: "eert"

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"

Example 3:
Input: s = "Aabb"
Output: "bbAa"
*/

/*
APPROACH (Optimal - Hash Map + Sorting):-
-> Use an unordered_map to count the frequency of each character.
-> Store the character-frequency pairs in a vector.
-> Sort the pairs according to decreasing frequency.
-> Build the answer by adding each character frequency times.
*/

// CODE:-

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> arr;

        for(auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string result;

        for(auto it : arr) {

            for(int i = 0; i < it.second; i++) {
                result += it.first;
            }
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N + K log K)
// SPACE COMPLEXITY = O(N + K)