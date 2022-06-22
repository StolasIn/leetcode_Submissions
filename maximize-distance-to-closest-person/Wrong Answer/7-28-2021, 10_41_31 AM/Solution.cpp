// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int m=s.size();
        int left[m],right[m];
        int l=0,r=m-1;
        for(int i=0;i<m;i++){
            if(s[i]==1) l=i;
            left[i]=l;
        }
        for(int i=m-1;i>=0;i--){
            if(s[i]==1) r=i;
            right[i]=r;
        }
        int ma=0;
        for(int i=0;i<m;i++){
            ma=max(ma,min(i-left[i],right[i]-i));
        }
        return ma;
    }
};