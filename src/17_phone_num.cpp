/*
25 / 25 test cases passed.
Status: Accepted
Runtime: 0 ms

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size() <= 0) return ret;

        setUpCharTable();

        int retSize = 1;
        int digitSize = digits.size();
        for (int i = 0; i < digitSize; i++) retSize *= charTable[digits[i] - '0'].size();

        vector<string> ret2(retSize, "");

        for (int j = 0; j < ret2.size(); j++) {
            int product = 1;
            for (int k = 0; k < digitSize; k++) {
                int currCharSize = charTable[digits[k] - '0'].size();
                int currIndex = (j / product) % currCharSize;
                ret2[j] += charTable[digits[k] - '0'][currIndex];
                product *= currCharSize;
            }
        }

        return ret2;
    }

private:
    void setUpCharTable();

    vector<vector<int>> charTable;
};


void Solution::setUpCharTable() {
    this->charTable.clear();
    this->charTable.push_back({});
    this->charTable.push_back({});
    this->charTable.push_back({ 'a', 'b', 'c' });
    this->charTable.push_back({ 'd', 'e', 'f' });
    this->charTable.push_back({ 'g', 'h', 'i' });
    this->charTable.push_back({ 'j', 'k', 'l' });
    this->charTable.push_back({ 'm', 'n', 'o' });
    this->charTable.push_back({ 'p', 'q', 'r', 's' });
    this->charTable.push_back({ 't', 'u', 'v' });
    this->charTable.push_back({ 'w', 'x', 'y', 'z' });
}


int main() {
    Solution mysolution = Solution();
    string digits = "23";
    vector<string> ret = mysolution.letterCombinations(digits);

    // print ret
    cout << "====================================================" << endl;
    for (string elem : ret)
        cout << elem << endl;

    cin.get();
    return 0;
}

