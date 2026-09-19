/*
QUESTION:-
Given an array of strings words, return the words that can be typed using
letters of the alphabet on only one row of the American keyboard.

In the American keyboard:

Row 1: "qwertyuiop"
Row 2: "asdfghjkl"
Row 3: "zxcvbnm"

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]

Example 2:
Input: words = ["omk"]
Output: []

Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
*/

/*
APPROACH (Hashing / Row Mapping):-
-> Store the three keyboard rows as strings.
-> For every word, find the row containing its first character.
-> Check whether every character of the word belongs to that same row.
-> If all characters belong to the same row, add the word to the result.
-> Convert characters to lowercase so uppercase letters work correctly.
*/

// CODE:-

class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> result;

        for(string word : words) {

            string lower = word;

            for(char& ch : lower) {
                ch = tolower(ch);
            }

            string* row;

            if(row1.find(lower[0]) != string::npos) {
                row = &row1;
            }
            else if(row2.find(lower[0]) != string::npos) {
                row = &row2;
            }
            else {
                row = &row3;
            }

            bool valid = true;

            for(char ch : lower) {

                if(row->find(ch) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                result.push_back(word);
            }
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N * L)
// SPACE COMPLEXITY = O(1)