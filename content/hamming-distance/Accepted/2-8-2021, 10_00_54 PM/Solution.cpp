// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        x^=y;
        long int c=1;
        int cnt=0;
        for(int i=0;i<32;i++){
            if(x&c) cnt++;
            c<<=1;
        }
        return cnt;
    }
};