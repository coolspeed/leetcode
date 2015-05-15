/*

Leetcode 10: Regular Expression Matching

Some examples:
isMatch("aa","a") ¡æ false
isMatch("aa","aa") ¡æ true
isMatch("aaa","aa") ¡æ false
isMatch("aa", "a*") ¡æ true
isMatch("aa", ".*") ¡æ true
isMatch("ab", ".*") ¡æ true
isMatch("aab", "c*a*b") ¡æ true

cited from Rob Pike and Brian Kernighan.
and modified by coolspeed.

*/

#include <cstdio>
#include <iostream>

using namespace std;

int matchStar(char c, char* s, char* p);


bool isMatch(char* s, char* p) {
    if (*p == '\0')
        return *s == '\0';

    if (p[1] == '*')
        return matchStar(p[0], s, p + 2);

    if (*s != '\0' && (*p == '.' || *s == *p))
        return isMatch(s + 1, p + 1);

    return 0;
}


int matchStar(char c, char* s, char* p) {
    do {
        if (isMatch(s, p))
            return 1;
    }
    while (*s != '\0' && (*s++ == c || c == '.'));
    return 0;
}


int main() {
    char* s = "aa";
    char* p = ".*";
    bool matchResult = isMatch(s, p);
    printf("s=%s \t p=%s \t result=%d\n", s, p, matchResult);

    // unit test goes here
    cout << "test cases:" << endl;
    cout << (isMatch("aa", "a") == false) << endl;
    cout << (isMatch("aa", "aa") == true) << endl;
    cout << (isMatch("aaa", "aa") == false) << endl;
    cout << (isMatch("aa", "a*") == true) << endl;
    cout << (isMatch("aa", ".*") == true) << endl;
    cout << (isMatch("ab", ".*") == true) << endl;
    cout << (isMatch("aab", "c*a*b") == true) << endl;
    cout << (isMatch("abcd", "d*") == false) << endl;

    cin.get();
    return 0;
}


