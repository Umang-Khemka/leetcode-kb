class Solution {
public:
    int partitionString(string s) {
        int cnt = 1;
        vector<bool> seen(26,false);

        for(char c : s){
            int idx = c - 'a';

            if(seen[idx]){
                cnt++;
                fill(seen.begin(),seen.end(),false);
            }
            seen[idx] = true;
        }
        return cnt;
    }
};