class Solution {
public:
    int solve(int i, int amount, vector<int>& coins,
              vector<vector<int>>& dp) {

        if (amount == 0) return 0;
        if (i == coins.size()) return 1e9;
        if (amount < 0) return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        // pick
        int pick = 1 + solve(i, amount - coins[i], coins, dp);

        // not pick
        int notPick = solve(i + 1, amount, coins, dp);

        return dp[i][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(0, amount, coins, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};