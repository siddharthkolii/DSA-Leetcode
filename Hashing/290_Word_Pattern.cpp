/*
QUESTION:-
Given a pattern and a string s, find if s follows the same pattern.

Here, "follows" means a full match, such that there is a bijection between
a letter in pattern and a non-empty word in s.

Specifically:
-> Each letter in pattern maps to exactly one word in s.
-> Each word in s maps to exactly one letter in pattern.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
*/

/*
APPROACH (Optimal - Two-Way Mapping):-
-> Split the sentence into individual words.
-> Maintain a mapping from pattern character to word.
-> Maintain another mapping from word to pattern character.
-> For every character-word pair, check whether the existing mappings
   are consistent.
-> If either mapping conflicts, return false.
-> Otherwise, store both mappings.
-> If all pairs are consistent, return true.
*/

// CODE:-

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        stringstream ss(s);

        while(ss >> word) {
            words.push_back(word);
        }

        if(pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for(int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string w = words[i];

            if(charToWord.find(ch) != charToWord.end() &&
               charToWord[ch] != w) {
                return false;
            }

            if(wordToChar.find(w) != wordToChar.end() &&
               wordToChar[w] != ch) {
                return false;
            }

            charToWord[ch] = w;
            wordToChar[w] = ch;
        }

        return true;
    }
};

// TIME COMPLEXITY = O(N + M) average
// SPACE COMPLEXITY = O(N + M)