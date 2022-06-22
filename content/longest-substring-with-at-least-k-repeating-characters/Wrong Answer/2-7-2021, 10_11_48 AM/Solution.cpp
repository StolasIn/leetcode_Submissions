// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> v(128,0);
        int m=s.size();
        int cnt=0;
        for(int i=0;i<m;i++){
            v[s[i]]++;
        }
        for(int i='a';i<='z';i++){
            if(v[i]>=k)
                cnt+=v[i];
        }
        return cnt;
    }
};