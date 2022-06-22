// https://leetcode.com/problems/self-dividing-numbers

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            left=i;
            while(left!=0){
                if(left%10==0) break;
                if(i%(left%10)!=0) break;
                left/=10;
            }
            if(left==0){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};