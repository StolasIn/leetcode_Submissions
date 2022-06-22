// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int t1,t2,t3,ans=0;
        while(a!=0 || b!=0 || c!=0){
            t1=a%2;
            t2=b%2;
            t3=c%2;
            a/=2;
            b/=2;
            c/=2;
            if((t1|t2)!=t3){
                if(t3==1){
                    ans++;
                }
                else{
                    if(t1) ans++;
                    if(t2) ans++;
                }
            }
        }
        return ans;
    }
};