#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        string ret = "";
        int strLen = s.size();
        int period = 2 * numRows - 2;
        int times = ceil(strLen / (double) period);

        for (int i = 0; i < numRows; i++){
//            cout << "i=" << i << endl;

            if (i == 0 || i == numRows - 1)  // print every one period
                for (int sIndex = i; sIndex < strLen; sIndex += period)
                    ret += s[sIndex];
            else {
                for (int iterTime = 0; iterTime < times; iterTime++) {
                    int sIndex;

                    // print +iterIndex th
                    sIndex = iterTime * period + i;
                    if (sIndex < strLen) ret += s[sIndex];

                    // print next -iterIndex th
                    sIndex = (iterTime + 1) * period - i;
                    if (sIndex > 0 && sIndex < strLen) ret += s[sIndex];
                }
            }
//            cout << ret << endl;
        }

        return ret;
    }
};


int main()
{   
    string input = "PAYPALISHIRING";

    Solution mySolution = Solution();

    string output = mySolution.convert(input, 3);
    if (output == "PAHNAPLSIIGYIR")
        cout << "PAYPALISHIRING passed test." << endl;

    cout << output << endl;

    return 0;
}

