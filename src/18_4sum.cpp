/*
282 / 282 test cases passed.
Status: Accepted
Runtime: 72 ms
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums, int target_3sum = 0) {
    vector<vector<int>> ret;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = target_3sum - nums[i];

        for (int left = i + 1, right = nums.size() - 1; left < right;) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                vector<int> elem{ nums[i], nums[left], nums[right] };
                ret.push_back(elem);
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else if (sum < target) {
                left++;
            }
            else {  // sum > target
                right--;
            }
        }
    }

    return ret;
}


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort
        sort(nums.begin(), nums.end());  // Nlog(N)

        vector<vector<int>> ret;

        for (int i = 0; i < nums.size(); i++) {
            //cout << "i=" << i << "\tcurr_int=" << nums[i] << endl;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target_3sum = target - nums[i];
            //cout << "target_3sum=" << target_3sum << endl;

            if (i < nums.size() - 2) {  // not one of the last 2 elems
                vector<int> threeSumInput(nums.begin() + i + 1, nums.end());
                vector<vector<int>> sums_of_3 = threeSum(threeSumInput, target_3sum);
                // nums[i] cross sums_of_3
                for (vector<int> vec : sums_of_3) {
                    vector<int> ret_elem{ nums[i], vec[0], vec[1], vec[2] };
                    ret.push_back(ret_elem);
                }
            }
        }

        return ret;
    }
};


int main()
{
    Solution mysolution = Solution();
    vector<int> nums{ 1, 0, -1, 0, -2, 2 };
    vector<vector<int>> ret = mysolution.fourSum(nums, 0);

    // print ret
    cout << "===============================================" << endl;
    cout << "ret:" << endl;
    for (vector<int> vec : ret) {
        for (int elem : vec)
            cout << elem << '\t';
        cout << endl;
    }

    cin.get();
    return 0;
}

