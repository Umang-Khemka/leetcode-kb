class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;

        for (int len = 2; len <= 9; len++) {
            for (int start = 1; start <= 10 - len; start++) {
                int num = 0;
                int digit = start;

                for (int i = 0; i < len; i++) {
                    num = num * 10 + digit;
                    digit++;
                }

                nums.push_back(num);
            }
        }

        vector<int> ans;

        for (int num : nums) {
            if (num >= low && num <= high)
                ans.push_back(num);
        }

        return ans;
    }
};