// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> ans;
    int s;
    void per(vector<int>& n,int x){
        if(x==s) ans.emplace_back(n);
        for(int i=x;i<s;i++){
            if(i>x && n[i]==n[x]) continue;
            swap(n[i],n[x]);
            per(n,x+1);
            swap(n[i],n[x]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& n) {
        sort(n.begin(),n.end());
        s=n.size();
        per(n,0);
        return ans;
    }
};