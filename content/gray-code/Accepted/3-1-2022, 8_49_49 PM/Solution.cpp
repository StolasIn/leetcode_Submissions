// https://leetcode.com/problems/gray-code

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n<=1){
            return {0,1};
        }
        vector<int> ans = grayCode(n-1);
        int m = ans.size();
        int num = 1<<(n-1);
        ans.insert(ans.end(),ans.rbegin(),ans.rend());
        for(int i=m;i<ans.size();i++){
            ans[i] += num;
        }
        return ans;
    }
};