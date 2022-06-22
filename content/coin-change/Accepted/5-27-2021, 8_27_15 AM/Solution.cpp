// https://leetcode.com/problems/coin-change

class Solution {
public:
    void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans) {
        if (amount == 0) {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size()) return;
        if (vi[amount][c_index] <= count) return;

        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--) {
            int nextAmount = amount - k * coins[c_index];
            coinChange(coins, nextAmount, c_index + 1, count + k, ans);
        }
        vi[amount][c_index] = min(vi[amount][c_index], count);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        vi = vector<vector<int>>(amount + 1, vector<int>(coins.size(), INT_MAX));
        coinChange(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

private:
    vector<vector<int>> vi;
};
