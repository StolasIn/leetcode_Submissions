// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128,0);
        int n=0;
        int left=0,right=0;
        int ma = 0;
        while(right<s.size()){
            if(n==0){
                ma = max(ma,right-left-1);
                if(cnt[s[right]]==0){
                    cnt[s[right++]]++;
                }
                else{
                    cnt[s[right++]]++;
                    n++;
                }
            }
            else{
                if(cnt[s[left]]>=2){
                    cnt[s[left++]]--;
                    n--;
                }
                else{
                    cnt[s[left++]]--;
                }
            }   
        }
        return ma+1;
    }
};