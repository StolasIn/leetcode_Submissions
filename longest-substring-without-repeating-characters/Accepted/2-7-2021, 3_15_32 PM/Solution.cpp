// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int beg=0,end=0;
        vector<int> v(128,0);
        int max1=-1;
        int m=s.size()-1;
        while(beg<=m && end<=m){
            if(v[s[end]]==0){
                max1=max(max1,end-beg+1);
                v[s[end]]++;
            }
            else{
                while(s[beg]!=s[end]){
                    v[s[beg]]--;
                    beg++;
                }
                beg++;
            }
            end++;
        }
        return max1;
    }
};