class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1] + 1){
                break;
            }
            sum += nums[i];
        }

        int x = sum;
        while(st.find(x) != st.end()){
            x++;
        }

        return x;
    }
};