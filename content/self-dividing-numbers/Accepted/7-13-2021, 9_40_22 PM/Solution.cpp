// https://leetcode.com/problems/self-dividing-numbers

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        int t;
        for(int i=left;i<=right;i++){
            t=i;
            while(t!=0){
                if(t%10==0) break;
                if(i%(t%10)!=0) break;
                t/=10;
            }
            if(t==0){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};