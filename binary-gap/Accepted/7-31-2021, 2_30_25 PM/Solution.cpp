// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int pre=0;
        int ma=-1;
        int cnt=0;
        for(int i=0;n!=0;i++){
            if(n%2==1){
                cnt++;
                if(cnt==1){
                    pre=i;
                    n/=2;
                    continue;
                }
                ma=max(ma,i-pre);
                pre=i;
            }
            n/=2;
        }
        if(cnt<=1) return 0;
        return ma;
    }
};