// Source : https://leetcode.com/problems/two-sum/
// Author : coolspeed
// Date   : 2015-04-23

/**********************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
*
**********************************************************************************/


#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int index1 = -1, index2 = -1;
		unordered_map<int,int> map;  // key: wanted_num, value: matched index

		// main logic through loop
		for (auto i = 0; i < numbers.size(); ++i) {
			int curr_num = numbers[i];
			auto got = map.find(curr_num);

			// found?
			if (got != map.end()) {
				index1 = got->second;
				index2 = (int) i;
				break;
			}
			// not found. add it into map.
			else {
				int wanted_num = target - curr_num;
				map[wanted_num] = i;
			}
		}

		vector<int> ret {index1 + 1, index2 + 1};
		return ret;
	}
};


int main(int argc, char ** argv){
	vector<int> numbers{ 2, 7, 11, 15 };
	int target = 9;

	Solution a_solution = Solution();
	vector<int> my_answer = a_solution.twoSum(numbers, target);

	cout << "index1=" << my_answer[0] << ", index2=" << my_answer[1] << endl;

	cin.get();
	return 0;
}

