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
            return true;
        }
    }
};