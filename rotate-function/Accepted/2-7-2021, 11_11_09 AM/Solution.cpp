// https://leetcode.com/problems/rotate-function

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long int sum = 0, cur = 0;
        int n = A.size();
        for(int i=0;i<n;i++)
        {
            cur += i * A[i];
            sum += A[i];
        }
        
        long long int ans = cur;
        for(int i = n-1; i>=0;i--)
        {
            cur += sum - (long long)n*A[i];
            ans = max(cur, ans);
        }
        return ans;
    }
};
