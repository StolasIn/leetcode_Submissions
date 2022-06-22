// https://leetcode.com/problems/maximum-69-number

class Solution {
public:
    int maximum69Number (int num) {
        int n=num;
        int t=-1;
        for(int i=0;num!=0;i++){
            if(num%10==6){
                t=i;
            }
            num/=10;
        }
        if(t==-1){
            return n;
        }
        return n+3*pow(10,t);
    }
};