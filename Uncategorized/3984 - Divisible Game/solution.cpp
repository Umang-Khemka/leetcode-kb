class Solution {
public:
    const int MOD = 1e9 + 7;

    long long maxSubarraySum(vector<int> &arr) {
        long long res = arr[0];
        long long maxEnding = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            maxEnding = max((long long)arr[i], maxEnding + arr[i]);
            res = max(res, maxEnding);
        }

        return res;
    }

    int divisibleGame(vector<int>& nums) {
        unordered_set<int> candidates;
        int mx = 0;

        for (int x : nums) {
            mx = max(mx, x);

            for (int d = 2; 1LL * d * d <= x; d++) {
                if (x % d == 0) {
                    candidates.insert(d);
                    candidates.insert(x / d);
                }
            }

            if (x > 1)
                candidates.insert(x);
        }

        candidates.insert(mx + 1);

        long long bestDiff = LLONG_MIN;
        int bestK = INT_MAX;

        vector<int> temp(nums.size());

        for (int k : candidates) {

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] % k == 0)
                    temp[i] = nums[i];
                else
                    temp[i] = -nums[i];
            }

            long long diff = maxSubarraySum(temp);

            if (diff > bestDiff || (diff == bestDiff && k < bestK)) {
                bestDiff = diff;
                bestK = k;
            }
        }

        return (bestDiff % MOD + MOD) % MOD * bestK % MOD;
    }
};