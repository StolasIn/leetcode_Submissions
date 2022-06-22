// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> v(128,0);
        int l=0,r=0;
        bool isre = false;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(isre==false){
                ans = max(ans,r-l);
                if(v[s[r]]>=1){
                    isre = true;
                }
                v[s[r]]++;
                r++;
            }
            else{
                if(v[s[l]]==1){
                    isre = false;
                }
                v[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};