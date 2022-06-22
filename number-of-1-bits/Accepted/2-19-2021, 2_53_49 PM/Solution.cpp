// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int mask=1;
        int cnt=0;
        for(int i=0;i<31;i++){
            if(mask & n){
                cnt++;
            }
            mask<<=1;
        }
        if(mask & n){
            cnt++;
        }
        return cnt;
    }
};