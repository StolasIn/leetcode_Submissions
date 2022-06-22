// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        if(n <= 2){
            return {{1},{1,1}};
        }
        ans = generate(n-1);
        vector<int> face = ans[ans.size()-1];
        vector<int> now;
        now.emplace_back(1);
        for(int i=0;i<face.size()-1;i++){
            now.emplace_back(face[i]+face[i+1]);
        }
        now.emplace_back(1);
        ans.emplace_back(now);
        return ans;
    }
};