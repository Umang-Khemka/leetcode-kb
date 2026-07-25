class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        sort(digits.begin(), digits.end(), greater<int>());

        int ans = digits[0] * digits[1];

        for (int i = 1; i < digits.size(); i++) {
            if (digits[i] == digits[0]) {
                ans = digits[0] * digits[0];
                break;
            }
        }

        return ans;
    }
};