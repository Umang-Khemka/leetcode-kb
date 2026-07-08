class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();

        vector<int> digits;
        vector<int> pos;

        // first compressed index at/after i
        vector<int> nextIdx(m, -1);

        // last compressed index at/before i
        vector<int> prevIdx(m, -1);

        // Build compressed digits and positions
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int k = digits.size();

        // No non-zero digits
        if (k == 0)
            return vector<int>(queries.size(), 0);

        // Build nextIdx
        int ptr = 0;
        for (int i = 0; i < m; i++) {
            while (ptr < k && pos[ptr] < i)
                ptr++;
            if (ptr < k)
                nextIdx[i] = ptr;
        }

        // Build prevIdx
        ptr = k - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (ptr >= 0 && pos[ptr] > i)
                ptr--;
            if (ptr >= 0)
                prevIdx[i] = ptr;
        }

        // powers of 10
        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix concatenation values
        vector<long long> P(k + 1, 0);

        // Prefix digit sums
        vector<long long> prefSum(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            P[i] = (P[i - 1] * 10 + digits[i - 1]) % MOD;
            prefSum[i] = prefSum[i - 1] + digits[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int L = nextIdx[l];
            int R = prevIdx[r];

            if (L == -1 || R == -1 || L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long x =
                (P[R + 1] - (P[L] * pow10[len]) % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};