// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int m=c.size();
        int l=m-k,r=m;
        int sum=0;
        for(int i=l;i<r;i++){
            sum+=c[i];
        }
        int ma=sum;
        while(l!=1){
            ma=max(ma,sum);
            r%=m;
            l%=m;
            sum-=c[l];
            sum+=c[r];
            l++;
            r++;
        }
        return ma;
    }
};