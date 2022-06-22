// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    int lookup[20][10010];
    void buildSparseTable(vector<int>& arr, int n)
    {
        for (int i = 0; i < n; i++)
            lookup[i][0] = arr[i];
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                if (lookup[i][j - 1] >
                            lookup[i + (1 << (j - 1))][j - 1])
                    lookup[i][j] = lookup[i][j - 1];
                else
                    lookup[i][j] =
                            lookup[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    int query(int L, int R)
    {
        int j = (int)log2(R - L + 1);
        if (lookup[L][j] > lookup[R - (1 << j) + 1][j])
            return lookup[L][j];
        else
            return lookup[R - (1 << j) + 1][j];
    }
    vector<int> maxSlidingWindow(vector<int>& n, int k) {
        if(k==1) return n;
        vector<int> ans;
        buildSparseTable(n,n.size());
        for(int i=0;i+k-1<n.size();i++){
            ans.emplace_back(query(i,i+k-1));
        }
        return ans;
    }
};