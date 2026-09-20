/*
QUESTION:-
Given two arrays of strings list1 and list2, find the common strings with
the smallest index sum.

The index sum of a common string is the sum of its index in list1 and
its index in list2.

Return all the common strings with the minimum index sum.
You may return the answer in any order.

Example 1:
Input:
list1 = ["Shogun","Tapioca Express","Burger King","KFC"]
list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]

Output:
["Shogun"]

Example 2:
Input:
list1 = ["Shogun","Tapioca Express","Burger King","KFC"]
list2 = ["KFC","Shogun","Burger King"]

Output:
["Shogun"]

Example 3:
Input:
list1 = ["happy","sad","good"]
list2 = ["sad","happy","good"]

Output:
["sad","happy"]
*/

/*
APPROACH (Optimal - Hash Map):-
-> Store every string from list1 along with its index in an unordered_map.
-> Traverse list2.
-> If a string exists in the map, it is common to both lists.
-> Calculate its index sum.
-> Keep track of the minimum index sum.
-> If the current sum is smaller, clear the result and add the string.
-> If the current sum equals the minimum, add the string as well.
*/

// CODE:-

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                   vector<string>& list2) {

        unordered_map<string, int> mp;

        for(int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for(int j = 0; j < list2.size(); j++) {

            if(mp.find(list2[j]) != mp.end()) {

                int sum = mp[list2[j]] + j;

                if(sum < minSum) {

                    minSum = sum;

                    result.clear();

                    result.push_back(list2[j]);
                }
                else if(sum == minSum) {

                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};

// TIME COMPLEXITY = O(N + M) average
// SPACE COMPLEXITY = O(N)