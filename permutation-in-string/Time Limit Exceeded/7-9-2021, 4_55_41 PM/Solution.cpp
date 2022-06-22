// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int check[128];
        int have[128];
        int cnt=0,now=0;
        for(int i='a';i<='z';i++){
            check[i]=0;
            have[i]=0;
        }
        int m=s1.size(),n=s2.size();
        for(int i=0;i<m;i++){
            check[s1[i]]++;
            if(check[s1[i]]==1) cnt++;
        }
        int l=0,r=0;
        while(r<n){
            if(now<cnt){
                if(check[s2[r]]!=0){
                    if(have[s2[r]]==check[s2[r]]-1){
                        cnt++;
                    }
                    have[s2[r]]++;
                    r++;
                }
                else{
                    now=0;
                    while(l<=r){
                        have[s2[l]]--;
                        l++;
                    }
                }
            }
            else{
                return true;
            }
        }
        return false;
    }
};