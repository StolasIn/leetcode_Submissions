// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int pre=0;
        int ma=-1;
        int mi=1e9;
        if(n%2==0) return 0;
        for(int i=0;n!=0;i++){
            if(n%2==1){
                mi=min(mi,i);
                ma=max(ma,i-pre);
                pre=i;
            }
            n/=2;
        }
        return max(mi,ma);
    }
};