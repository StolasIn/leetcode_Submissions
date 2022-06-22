// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int pre=0;
        int ma=-1;
        int mi=1e9;
        int cnt=0;
        for(int i=0;n!=0;i++){
            if(n%2==1){
                cnt++;
                mi=min(mi,i);
                ma=max(ma,i-pre);
                pre=i;
            }
            n/=2;
        }
        if(cnt<=1) return 0;
        return max(mi,ma);
    }
};