// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int sum(vector<int>& v){
        int sum = 0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        return sum;
    }
    int maximumWealth(vector<vector<int>>& accounts) {
        int ma = -1;
        for(int i=0;i<accounts.size();i++){
            ma=max(ma,sum(accounts[i]));
        }
        return ma;
    }
};