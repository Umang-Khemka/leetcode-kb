class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        
        if (n == 1) {
            if (s1 == s2) return 0;
            if (s1 == "1") return -1; // s2 == "0", impossible
            return 1;                  // s1 == "0", s2 == "1"
        }
        
        long long D = 0, E = 0, k = 0;
        int runLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (s1[i] == '1' && s2[i] == '0') {
                E++;
                runLen++;
            } else {
                if (runLen % 2 == 1) k++;
                runLen = 0;
                if (s1[i] == '0' && s2[i] == '1') D++;
            }
        }
        
        if (runLen % 2 == 1) k++; // handle run ending at last index
        
        return (int)(D + (E + 3 * k) / 2);
    }
};