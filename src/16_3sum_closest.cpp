/*
* author: coolspeed

120 / 120 test cases passed.
Status: Accepted
Runtime: 28 ms

Given an array S of n integers, find three integers in S such that the sum
is closest to a given number, target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort: O(NLogN)
        sort(nums.begin(), nums.end());

        int curr_min = INT_MAX;
        int closest_sum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int new_target = target - nums[i];

            if (i < nums.size() - 1) {  // not the last elem
                int left = i + 1, right = nums.size() - 1;
                
                while (left < right) {
                    int sum = nums[left] + nums[right];

                    if (sum == new_target) {
                        closest_sum = nums[i] + sum;
                        curr_min = 0;
                        break;
                    }
                    else if (sum < new_target) {
                        // min?
                        if (new_target - sum < curr_min)
                            closest_sum = nums[i] + sum;
                        curr_min = min(curr_min, new_target - sum);
                        // prepare for next
                        left++;
                        // avoid repeat
                        while (left < right && nums[left] == nums[left - 1]) left++;
                    }
                    else {  // sum > new_target
                        // min?
                        if (sum - new_target < curr_min)
                            closest_sum = nums[i] + sum;
                        curr_min = min(curr_min, sum - new_target);
                        // prepare for next
                        right--;
                        // avoid repeat
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
            }
        }

        return closest_sum;
    }
};


int main() {
    Solution mysolution = Solution();
    vector<int> nums{ 0, 0, 0 };
    int target = 1;
    int ret = mysolution.threeSumClosest(nums, target);

    // print ret
    cout << "============================================" << endl;
    cout << "ret=" << ret << endl;

    cin.get();
    return 0;
}

