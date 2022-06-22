// https://leetcode.com/problems/get-equal-substrings-within-budget

class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        vector<int> co;
        int m = s.size();
        int l=0,r=0;
        int now=0;
        int ma=-1;
        for(int i=0;i<m;i++){
            co.emplace_back(abs(s[i]-t[i]));
        }
        while(r<m){
            if(now<=cost){
                ma=max(ma,r-l);
                now+=co[r];
                r++;
            }
            else{
                now-=co[l];
                l++;
            }
        }
        if(now<=cost){
            ma=max(ma,r-l);
        }
        return ma;
    }
};