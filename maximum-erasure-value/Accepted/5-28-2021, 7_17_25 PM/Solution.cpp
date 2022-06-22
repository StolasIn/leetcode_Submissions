// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& n) {
        int l=0,r=0;
        int uni=0;
        int ma=-1;
        int m=n.size();
        int sum=0;
        int cnt[10010];
        memset(cnt,false,sizeof(cnt));
        while(r<m){
            if(uni==0){
                if(cnt[n[r]]<=0){
                    sum+=n[r];
                    ma=max(ma,sum);
                    cnt[n[r]]++;
                    r++;
                }
                else{
                    sum+=n[r];
                    cnt[n[r]]++;
                    r++;
                    uni++;
                }
            }
            else{
                if(cnt[n[l]]<=1){
                    sum-=n[l];
                    cnt[n[l]]--;
                    l++;
                }
                else{
                    sum-=n[l];
                    cnt[n[l]]--;
                    l++;
                    uni--;
                }
            }
        }
        return ma;
    }
};