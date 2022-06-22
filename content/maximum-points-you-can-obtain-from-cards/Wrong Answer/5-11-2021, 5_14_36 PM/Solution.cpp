// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int m=c.size();
        int l=m-k,r=m-1;
        int sum=0;
        int ma=-INT_MAX;
        for(int i=l;i<=r;i++){
            sum+=c[i];
        }
        while(l!=1){
            ma=max(ma,sum);
            sum-=c[l];
            sum+=c[r];
            r++;
            l++;
            r%=m;
            l%=m;
        }
        return ma;
    }
};