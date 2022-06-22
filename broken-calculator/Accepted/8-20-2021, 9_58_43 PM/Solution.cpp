// https://leetcode.com/problems/broken-calculator

class Solution {
public:
    int brokenCalc(int s, int t) {
        int ans=0;
        while(t>s){
            ans++;
            if(t%2==1){
                t++;
            }
            else{
                t/=2;
            }
        }
        return s-t+ans;
    }
};