// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(f.size()==1 && f[0]==0 && n<=1) return true; 
        if(f.size()>1 && f[0]==0 && f[1]==0){
            f[0]=1;
            n--;
        }
        for(int i=1;i<f.size()-1;i++){
            if(f[i-1]==0 && f[i]==0 && f[i+1]==0){
                f[i]=1;
                n--;
            }
        }
        if(f.size()>=2 && f[f.size()-2]==0 && f[f.size()-1]==0){
            f[f.size()-1]=1;
            n--;
        }
        return n<=0;
    }
};