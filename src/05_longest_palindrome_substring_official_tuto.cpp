/*
I heard of the longest palindrome string problem the first time,
and was researching for what it is. Then I found leetcode official tuto.
http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html
Among my google result, it was the best study material I had.
It was short and simple, that I didn't feel any need to do additional work.
I decided to paste it here and re-implement myself months later.

Now I would go to study the O(N) solution:
http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/


string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}


string longestPalindromeSimple(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;

    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}


class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindromeSimple(s);
    }
};

