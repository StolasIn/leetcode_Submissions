// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& num) {
        int f=0;
        int m=num.size();
        int tmp;
        for(int i=1;i<m;i++){
            if(num[i]<num[i-1]){
                f++;
                tmp=i-1;
            }
        }
        if(tmp+1>=num.size()) num[tmp]=num[tmp-1];
        else if(tmp-1<0) num[tmp]=num[tmp+1];
        else{
            num[tmp]=(num[tmp-1]+num[tmp+1])/2;
        }
        if(f>=2) return false;
        else{
            for(int i=1;i<m;i++){
                if(num[i]<num[i-1]){
                    return false;
                }
            }
            return true;
        }
    }
};