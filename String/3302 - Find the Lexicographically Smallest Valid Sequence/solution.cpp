class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (dp[i + 1] < m &&
                word1[i] == word2[m - dp[i + 1] - 1]) {
                dp[i]++;
            }
        }

        vector<int> ans;

        int j = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && j < m; i++) {

            int remaining = m - j - 1;

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!usedMismatch && dp[i + 1] >= remaining) {
                ans.push_back(i);
                j++;
                usedMismatch = true;
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};