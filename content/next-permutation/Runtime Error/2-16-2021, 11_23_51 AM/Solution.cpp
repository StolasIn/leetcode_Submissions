// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& n) {
        int i,j,mi=INT_MAX,po;
        int m=n.size();
        for(i=m-1;i>0;i--){
            if(n[i]>n[i-1]) break;
        }
        i++;
        if(i==0){
            reverse(n.begin(),n.end());
            return;
        }
        else{
            for(j=i;j<m;j++){
                if(n[j]>n[i-1]){
                    mi=min(mi,n[j]);
                    po=j;
                }
            }
            swap(n[po],n[i-1]);
            sort(n.begin()+i,n.end());
        }
    }
};