// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
     int countBinarySubstrings(const string & s) {
    int ct = 0;
    int prev = 0;
    int cur = 1;
    for (int i=1; i<s.size(); ++i) {
      if (s[i] == s[i-1])
        ++cur;
      else {
        ct += min(prev, cur);
        prev = cur;
        cur = 1;
      }
    }
    return ct + min(prev, cur);
  }
};