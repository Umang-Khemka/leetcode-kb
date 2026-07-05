class Solution {
public:
    int getDigitRange(int num) {
        if (num == 0) return 0;

        int mn = 9, mx = 0;

        while (num > 0) {
            int digit = num % 10;
            mn = min(mn, digit);
            mx = max(mx, digit);
            num /= 10;
        }

        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int sum = 0;

        for (int num : nums) {
            int range = getDigitRange(num);

            if (range > maxRange) {
                maxRange = range;
                sum = num;
            } 
            else if (range == maxRange) {
                sum += num;
            }
        }

        return sum;
    }
};