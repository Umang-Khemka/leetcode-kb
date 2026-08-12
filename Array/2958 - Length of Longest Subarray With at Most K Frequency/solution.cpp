class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;

        while(left < n && right < n){
            mp[nums[right]]++;

            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans,right - left + 1);

            right++;
        }
        return ans;
    }
};