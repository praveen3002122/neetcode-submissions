class Solution {
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s, t, dp) + solve(i + 1, j, s, t, dp);
        } else {
            return dp[i][j] = solve(i + 1, j, s, t, dp);
        }
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
    }
};