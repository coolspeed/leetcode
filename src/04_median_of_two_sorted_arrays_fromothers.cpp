// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : coolspeed. cited and modified from: http://blog.csdn.net/yutianzuijin/article/details/11499917
// You can find my own python implementation at: https://github.com/coolspeed/leetcode/blob/master/src/04_median_of_two_sorted_arrays_myown.py
// Date   : 2015-05-03

/**********************************************************************************
*
* There are two sorted arrays A and B of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
**********************************************************************************/


/*
2078 / 2078 test cases passed.
Status: Accepted
Runtime: 51 ms
*/


/*
A trick:
Unfortunately the C++ version code framework passes vector to your function instead of array.
You can get the address of the first element of the vector to treat it as a int[]
*/


#include <iostream>
#include <vector>

using namespace std;


inline int min(int a, int b) {
    return a <= b ? a : b;
}


double findKth(int a[], int m, int b[], int n, int k) {
    //always assume that m is equal or smaller than n
    if (m > n)
        return findKth(b, n, a, m, k);

    if (m == 0)
        return b[k - 1];

    if (k == 1)
        return min(a[0], b[0]);

    //divide k into two parts
    int pa = min(k / 2, m), pb = k - pa;
    if (a[pa - 1] < b[pb - 1])
        return findKth(a + pa, m - pa, b, n, k - pa);

    else if (a[pa - 1] > b[pb - 1])
        return findKth(a, m, b + pb, n - pb, k - pb);

    else
        return a[pa - 1];
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int total = m + n;

        int * A = &nums1[0];
        int * B = &nums2[0];

        if (total & 0x1)
            return findKth(A, m, B, n, total / 2 + 1);
        else
            return (findKth(A, m, B, n, total / 2)
            + findKth(A, m, B, n, total / 2 + 1)) / 2;
    }
};



int main() {
    vector<int> nums1{ 1, 2, 3, 4 };
    vector<int> nums2{ 5, 6, 7, 8 };

    Solution citedSolution = Solution();
    double result = citedSolution.findMedianSortedArrays(nums1, nums2);

    cout << "result=" << result << endl;

    cin.get();
    return 0;
}

