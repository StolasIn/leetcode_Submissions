// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bi;
        uint32_t sum=1;
        long long pro=1;
        while(n!=0){
            bi.emplace_back(n%2);
            n/=2;
        }
        pro=pow(2,32-bi.size());
        for(int i=bi.size()-1;i>=0;i--){
            sum+=pro*bi[i];
            pro*=2;
        }
        return sum-1;
    }
};