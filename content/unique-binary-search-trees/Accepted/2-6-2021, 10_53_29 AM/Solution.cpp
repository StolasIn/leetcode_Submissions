// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n+1,0);
        ans[0]=1;
        ans[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                ans[i]+=ans[j-1]*ans[i-j];
                //j-1表示左子樹的可能組合
                //i-1-(j-1)=(i-j) 表示右子樹的可能組合
            }
        }
        return ans[n];
    }
};