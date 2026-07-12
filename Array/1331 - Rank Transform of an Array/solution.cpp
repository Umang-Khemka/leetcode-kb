class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        vector<int> temp = arr;
        int n = arr.size();

        sort(temp.begin(), temp.end());

        int rank = 1;

        for (int i = 0; i < n; i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank;
                rank++;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};