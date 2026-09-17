/*
QUESTION:-
You're given strings jewels where each character is a type of stone that
is a jewel, and stones representing the stones you have.

Each character in stones is a type of stone you have.
You want to know how many of the stones you have are also jewels.

Letters are case-sensitive, so "a" is considered a different type of stone
from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0
*/

/*
APPROACH (Optimal - Hash Set):-
-> Store every jewel character in an unordered_set.
-> Traverse all characters in stones.
-> If the current stone exists in the set, increase the count.
-> Return the count.
*/

// CODE:-

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_set<char> jewelsSet;

        for(char ch : jewels) {
            jewelsSet.insert(ch);
        }

        int count = 0;

        for(char ch : stones) {

            if(jewelsSet.find(ch) != jewelsSet.end()) {
                count++;
            }
        }

        return count;
    }
};

// TIME COMPLEXITY = O(J + S) average
// SPACE COMPLEXITY = O(J)