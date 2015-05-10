/*
 * total comsume: 136 ms
*/

#include <iostream>
#include <cmath>

using namespace std;


//inline int mypow(int a, int b) {
//    int ret = 1 ;
//    for (int i = 0; i < b; i++) ret *= a;
//    return ret;
//}


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        double myLog = log10(x);
        int length = ceil(myLog);
        if (abs(myLog - length) < 0.00000000001) length = myLog + 1;

        if (length <= 1) return true;

        int left, right;
        if ((length & 0x1) == 0) { // % 2 == 0, even
            left = (length >> 1) - 1;
            right = length >> 1;
        }
        else {
            left = right = (length >> 1);
        }

        while (left >= 0 && right < length) {
            int weight_left = pow(10, length - 1 - left);
            int left_digit = x / weight_left % 10;
            int weight_right = pow(10, length - 1 - right);
            int right_digit = x / weight_right % 10;
            if (left_digit != right_digit)
                return false;

            left--;
            right++;
        }
        return true;
    }
};


int main()
{
    Solution mySolution = Solution();

    // simple test
    int a = 10;
    bool ret = mySolution.isPalindrome(a);
    cout << ret << endl;

    // unit tests

//    int input_cases[] = {0, 1, 101, 1551, 1561, 1789, 1553651};

//    for (int input : input_cases) {
//        bool output = mySolution.isPalindrome(input);
//        cout << "input = " << input << '\t' << "output = " << output << endl;
//    }

    return 0;
}

