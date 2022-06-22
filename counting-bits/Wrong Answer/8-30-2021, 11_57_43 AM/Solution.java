// https://leetcode.com/problems/counting-bits

class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n+1];
        ans[0]=0;
        int pow2=0;
        for(int i=1;i<=n;i++){
            if((i^(i-1))==0){
                ans[i]=1;
                pow2=i;
            }
            else{
                ans[i]=1+ans[i-pow2];
            }
        }
        return ans;
    }
}