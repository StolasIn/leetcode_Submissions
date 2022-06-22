// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        //declare a vector of size num and initialise with 0
        vector<int> v;
        v.push_back(0);
        int k=0;
        for(int i=1;i<=num;i++)
        {
            if(!(i&(i-1))) //number is a power of 2 or not
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