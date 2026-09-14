/*
QUESTION:-
Given an array of integers arr, return true if the number of occurrences
of each value in the array is unique, or false otherwise.

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true

Explanation:
The value 1 has 3 occurrences, 2 has 2 occurrences, and 3 has 1 occurrence.
All occurrence counts are unique.

Example 2:
Input: arr = [1,2]
Output: false

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/

/*
APPROACH (Optimal - Hash Map + Hash Set):-
-> Use an unordered_map to count the frequency of every element.
-> Use an unordered_set to store the frequencies.
-> Traverse the frequency map.
-> If a frequency already exists in the set, return false.
-> Otherwise, insert the frequency into the set.
-> If all frequencies are unique, return true.
*/

// CODE:-

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;
        unordered_set<int> occurrences;

        for(int num : arr) {
            freq[num]++;
        }

        for(auto it : freq) {

            if(occurrences.find(it.second) != occurrences.end()) {
                return false;
            }

            occurrences.insert(it.second);
        }

        return true;
    }
};

// TIME COMPLEXITY = O(N) average
// SPACE COMPLEXITY = O(N)