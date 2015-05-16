#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else right--;
        }
        return maxArea;
    }
};


int main() {

    Solution mySolution = Solution();
    vector<int> height {2, 3, 4};
    int ret = mySolution.maxArea(height);
    cout << "ret = " << ret << endl;

    cin.get();
    return 0;
}

