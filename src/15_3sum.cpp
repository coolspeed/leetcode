/*
311 / 311 test cases passed.
Status: Accepted
Runtime: 60 ms
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());  // Nlog(N)

        vector<vector<int>> ret;

        for (int i = 0; i < nums.size(); i++) {
            //cout << "i=" << i << "\tcurr_int=" << nums[i] << endl;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = 0 - nums[i];
            //cout << "target=" << target << endl;

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
};


int main()
{
    Solution mysolution = Solution();
    vector<int> nums{ -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> ret = mysolution.threeSum(nums);

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

