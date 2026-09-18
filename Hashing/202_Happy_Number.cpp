    /*
QUESTION:-
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:
-> Starting with any positive integer, replace the number by the sum
   of the squares of its digits.
-> Repeat the process until the number equals 1, or it loops endlessly
   in a cycle which does not include 1.

Return true if n is happy, and false otherwise.

Example 1:
Input: n = 19
Output: true

Example 2:
Input: n = 2
Output: false
*/

/*
APPROACH (Optimal - Hash Set + Cycle Detection):-
-> Use an unordered_set to store numbers that have already appeared.
-> Calculate the sum of squares of the digits.
-> If n becomes 1, return true.
-> If n appears again in the set, a cycle exists, so return false.
-> Otherwise, store n and continue.
*/

// CODE:-

class Solution {
public:

    int getNext(int n) {

        int sum = 0;

        while(n > 0) {

            int digit = n % 10;

            sum += digit * digit;

            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> seen;

        while(true) {

            if(n == 1) {
                return true;
            }

            if(seen.find(n) != seen.end()) {
                return false;
            }

            seen.insert(n);

            n = getNext(n);
        }
    }
};

// TIME COMPLEXITY = O(log N) average
// SPACE COMPLEXITY = O(log N)