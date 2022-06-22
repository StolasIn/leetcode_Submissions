// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& num) {
        int f=0;
        int m=num.size();
        for(int i=1;i<m;i++){
            if(num[i]<num[i-1]){
                f++;
            }
        }
        if(f>=2) return false;
        else{
            int ma=-1;
            for(int i=0;i<m;i++){
                if(i!=0 && ma<num[i]) return false;
                ma=max(ma,num[i]);
            }
            return true;
        }
    }
};