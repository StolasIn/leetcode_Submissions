// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int m=n1.size();
        int n=n2.size();
        int ma=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(n1[i]==n2[j]){
                    int cnt=0;
                    for(int k=i,q=j;k<m && q<n;k++,q++){
                        if(n1[k]==n2[q]) cnt++;
                    }
                    ma=max(ma,cnt);
                }
            }
        }
        return ma;
    }
};