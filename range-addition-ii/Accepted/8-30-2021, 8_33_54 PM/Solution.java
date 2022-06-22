// https://leetcode.com/problems/range-addition-ii

class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int mix=Integer.MAX_VALUE,miy=Integer.MAX_VALUE;
        for(int i=0;i<ops.length;i++){
            mix=Math.min(mix,ops[i][0]);
            miy=Math.min(miy,ops[i][1]);
        }
        mix=Math.min(mix,m);
        miy=Math.min(miy,n);
        return mix*miy;
    }
}