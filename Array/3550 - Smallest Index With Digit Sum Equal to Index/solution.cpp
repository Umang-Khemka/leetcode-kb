class Solution {
public:

    bool isHelper(int value, int idx){
        int sum = 0;

        while(value > 0){
            sum += value % 10;
            value = value / 10;
        }

        return idx == sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(isHelper(nums[i],i)){
                return i;
            }
        }
        return -1;
    }
};