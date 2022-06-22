// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    void re(vector<int>& v,int n){
        for(int i=1;i<=n/2;i++){
            v.emplace_back(i);
            v.emplace_back(-i);
        }
    }
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2==0){
            re(ans,n);
        }
        else{
            ans.emplace_back(0);
            re(ans,n);
        }
        return ans;
    }
};