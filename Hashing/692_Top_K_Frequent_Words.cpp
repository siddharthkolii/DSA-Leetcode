/*
QUESTION:-
Given an array of strings words and an integer k, return the k most frequent
strings.

Return the answer sorted by frequency from highest to lowest.
If two words have the same frequency, sort them alphabetically.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"],
k = 4
Output: ["the","is","sunny","day"]
*/

/*
APPROACH (Optimal - Hash Map + Sorting):-
-> Count the frequency of every word using an unordered_map.
-> Store word-frequency pairs in a vector.
-> Sort by:
   1. Higher frequency first.
   2. Alphabetical order when frequencies are equal.
-> Return the first k words.
*/

// CODE:-

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for(string word : words) {
            freq[word]++;
        }

        vector<pair<string, int>> arr;

        for(auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end(),
             [](const pair<string, int>& a, const pair<string, int>& b) {

                 if(a.second != b.second) {
                     return a.second > b.second;
                 }

                 return a.first < b.first;
             });

        vector<string> result;

        for(int i = 0; i < k; i++) {
            result.push_back(arr[i].first);
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N + M log M)
// SPACE COMPLEXITY = O(M)