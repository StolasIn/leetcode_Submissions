// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1){
            return s.size();
        }
        vector<int> v(128,0);
        int m = s.size();
        int l=-1,r=-1;
        bool isre = false;
        int ans = 0;
        while(r+1<m){
            if(isre==false){
                if(v[s[++r]]>=1){
                    isre = true;
                }
                if(isre==false){
                    ans = max(ans,r-l);
                }
                v[s[r]]++;
            }
            else{
                if(v[s[++l]]==2){
                    isre = false;
                }
                v[s[l]]--;
            }
        }
        return ans;
    }
};