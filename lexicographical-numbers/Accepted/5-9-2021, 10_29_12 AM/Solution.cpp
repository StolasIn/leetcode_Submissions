// https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            v.emplace_back(to_string(i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            ans.emplace_back(atoi(v[i].c_str()));
        }
        return ans;
    }
};