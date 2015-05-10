#include <iostream>
#include <cmath>
#include <vector>
//#include <stack>
//#include <numeric>

//const int INT_MAX = 2147483647;

using namespace std;


class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        if (x > INT_MAX) return 0;
        if (x < INT_MIN) return 0;

        //cout << INT_MAX << ' ' << INT_MIN;

        vector<char> vec;

        if (x > 0) {
            long long temp = x;
            long long weight = 1;
            while (temp > 0) {
                char currDigit = (temp / weight) % 10;
                cout << "temp=" << temp << '\t';
                cout << "weight=" << weight << '\t';
                cout << "currDigit=" << (int)currDigit << '\t';
                cout << endl;
                vec.push_back(currDigit);

                temp -= currDigit * weight;
                weight *= 10;
            }
        }
        else {  // x < 0
            long long temp = x;
            long long weight = 1;
            while (temp < 0) {
                char currDigit = -((temp / weight) % 10);
                cout << "temp=" << temp << '\t';
                cout << "weight=" << weight << '\t';
                cout << "currDigit=" << (int)currDigit << '\t';
                cout << endl;
                vec.push_back(currDigit);

                temp += currDigit * weight;
                weight *= 10;
            }
        }

        // print out the stack
        long long ret = 0;
        if (x > 0) {
            long long weight = 1;
            for (int i = vec.size() - 1; i >= 0; i--) {
                ret += vec[i] * weight;
                cout << "ret=" << ret << endl;
                //if (ret > numeric_limits<int>::max()) return 0;
                if (ret > INT_MAX) return 0;
                weight *= 10;
            }
        }
        else {  // x < 0
            long long weight = 1;
            for (int i = vec.size() - 1; i >= 0; i--) {
                ret -= vec[i] * weight;
                cout << "ret=" << ret << endl;
                //if (ret < numeric_limits<int>::min()) return 0;
                if (ret < INT_MIN)
                    return 0;
                weight *= 10;
            }
        }

        cout << "final ret=" << ret << endl;

        return (int)ret;
    }
};


int main()
{
    //long input = (0 - 2147483648);
    long input = - (signed long) 2147483648L;

    Solution mySolution = Solution();
    int ret = mySolution.reverse(input);

    cout << ret << endl;

    cin.get();
    return 0;
}

