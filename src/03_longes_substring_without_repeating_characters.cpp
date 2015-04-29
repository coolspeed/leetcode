/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


/*
my own implementation, which is quite unefficient.

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max = 0;
		int start_index = 0, end_index = 0;
		unordered_set<char> myset;
		//int s_len = (int)s.size();

		int i = 0;
		for (auto i = 0; i < s.size();) {
			char c = s[i];

			// check s[i]
			bool repeated = myset.find(c) != myset.end();
			if (!repeated) {
				end_index++;

				// check length
				int curr_substring_length = end_index - start_index;
				// string curr_substring = s.substr(start_index, curr_substring_length);

				// max?
				if (curr_substring_length > max) max = curr_substring_length;
			}

			// prepare for next state
			if (repeated) {
				myset.erase(s[start_index++]);
				continue;
			}
			else {
				myset.insert(c);
			}

			i++;
		}

		return max;
	}
};

*/


// cited from:
// https://github.com/haoel/leetcode/blob/master/algorithms/longestSubstringWithoutRepeatingCharacters/longestSubstringWithoutRepeatingCharacters.cpp
// author of whom is the owner of http://coolshell.cn

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const int MAX_CHARS = 256;
		int m[MAX_CHARS];
		memset(m, -1, sizeof(m));

		int maxLen = 0;
		int lastRepeatPos = -1;
		for (int i = 0; i<s.size(); i++){
			if (m[s[i]] != -1 && lastRepeatPos < m[s[i]]) {
				lastRepeatPos = m[s[i]];
			}
			if (i - lastRepeatPos > maxLen){
				maxLen = i - lastRepeatPos;
			}
			m[s[i]] = i;
		}
		return maxLen;
	}
};


int main(int argc, char ** argv) {
	// run
	Solution mysolution = Solution();
	int myresult = mysolution.lengthOfLongestSubstring("aab");

	// print the result
	cout << myresult << endl;

	cin.get();
	return 0;
}

