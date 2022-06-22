// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        if(b[0]!=5) return false;
        int h[11]={0};
        for(int i=0;i<b.size();i++){
            if(b[i]==5){
                h[5]++;
            }
            else if(b[i]==10){
                if(h[5]<1) return false;
                h[5]--;
                h[10]++;
            }
            else{
                if(h[10]>=1 && h[5]>=1){
                    h[10]--;
                    h[5]--;
                }
                else if(h[5]>=3){
                    h[5]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};