// https://leetcode.com/problems/combinations

class Solution {
public:
    vector<vector<int>> ans;
    int s;
    int siz;
    vector<int> num1;
    void com(vector<int> num,int x){
        if(num.size()==s){
            ans.push_back(num);
            return;
        }
        for(int i=x;i<=siz;i++){
            num.push_back(i);
            com(num,i+1);
            num.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> num2;
        for(int i=1;i<=n;i++){
            num1.push_back(i);
        }
        if(k==n){
            ans.push_back(num1);
            return ans;
        }
        siz=n;
        s=k;
        com(num2,1);
        return ans;
    }
};