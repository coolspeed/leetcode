/*
08 atoi
*/

#include <iostream>
#include <cctype>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        // strip whitespace chars
        int i;
        for (i = 0; i < str.size(); i++)
            if (! isspace(str[i])) break;

        if (i >= str.size()) return 0;
        // have not hit end

        // symbol
        int symbol = 1;
        if (str[i] == '+') i++;
        else if (str[i] == '-') {
            symbol = -1;
            i++;
        }

        // expect numbers
        if (i >= str.size()) return 0;
        // have not hit end

        string filted = "";
        while (i < str.size()) {
            if (!(str[i] >= '0' && str[i] <= '9')) break;

            filted += str[i];
            i++;
        }

        if (filted.size() <= 0) return 0;
        long long ret = 0;
        long long weight = 1;
        for (int j = filted.size() - 1; j >= 0; j--) {
            int num = filted[j] - '0';
            ret += symbol * num * weight;
            
            // overflow?
            if (ret > INT_MAX) return INT_MAX;
            else if (ret < INT_MIN) return INT_MIN;

            weight *= 10;
        }

        return ret;
    }
};


int main()
{
    string input = " +95535abc";
    Solution mySolution = Solution();
    int ret = mySolution.myAtoi(input);

    cout << "final result: " << ret << endl;
    
    cin.get();
    return 0;
}

