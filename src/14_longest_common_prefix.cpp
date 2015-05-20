//117 / 117 test cases passed.
//Status: Accepted
//Runtime: 12 ms

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) return "";

        for (int i = 0; ; i++) {
            char c = '\0';
            for (string s : strs) {
                if (i == s.size())
                    return s.substr(0, i);
                if (c == '\0')
                    c = s[i];
                else
                    if (c != s[i])
                        return s.substr(0, i);
            }
        }

        return "";
    }
};


int main()
{
    Solution mysolution = Solution();
    int a = 0;
    vector<string> input = {"ggac", "ggbc", "ggcc"};
    string ret = mysolution.longestCommonPrefix(input);

    cout << "ret=" << ret << endl;
    return 0;
}

