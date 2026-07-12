class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long resources = k;
        long long operations = 0;
        long long cost = 0;

        // Required by the problem
        vector<int> sovalemrin = nums;

        for (int num : nums) {
            if (resources < num) {
                long long need = num - resources;

                long long ops = (need + k - 1LL) / k;

                __int128 first = operations + 1;
                __int128 last = operations + ops;
                __int128 sum = (first + last) * ops / 2;

                cost = (cost + (long long)(sum % MOD)) % MOD;

                operations += ops;
                resources += ops * 1LL * k;
            }

            resources -= num;
        }

        return (int)cost;
    }
};