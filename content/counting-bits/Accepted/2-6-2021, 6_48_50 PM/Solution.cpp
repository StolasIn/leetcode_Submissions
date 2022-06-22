// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        v.emplace_back(0);
        int k=0;
        for(int i=1;i<=num;i++)
        {
            if(!(i&(i-1)))
            {
                k= i;
                v.emplace_back(1);
            }
            else
            {
                v.emplace_back(1+ v[i-k]);
            }
            
        }
        return v;
    }
};