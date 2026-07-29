class Solution {
public:
    static const long long CAP = 2000000; // safely greater than k_max (1e6)
    long long countArrangements(array<int,26>& cnts, int total) {
        long long result = 1;
        int rem = total;
        for (int c = 0; c < 26 && rem > 0; c++) {
            int r = cnts[c];
            if (r == 0) continue;
            long long comb = 1;
            bool exceeded = false;
            for (int j = 1; j <= r; j++) {
                comb = comb * (long long)(rem - r + j) / j;
                if (comb > CAP) { exceeded = true; break; }
            }
            if (exceeded) return CAP + 1;

            result *= comb;
            if (result > CAP) return CAP + 1;
            rem -= r;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {
        long long kk = k;
        int n = s.size();

        array<int,26> freq{};
        for (char ch : s) freq[ch - 'a']++;

        int L = n / 2;
        char midChar = 0;
        array<int,26> half{};
        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2 == 1) midChar = 'a' + c;
            half[c] = freq[c] / 2;
        }

        long long total = countArrangements(half, L);
        if (total < kk) return "";

        string halfStr;
        halfStr.reserve(L);
        int remaining = L;

        for (int pos = 0; pos < L; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long cnt = countArrangements(half, remaining - 1);
                half[c]++;

                if (cnt >= kk) {
                    half[c]--;
                    halfStr.push_back('a' + c);
                    remaining--;
                    break;
                } else {
                    kk -= cnt;
                }
            }
        }

        string result = halfStr;
        if (midChar) result.push_back(midChar);
        for (int i = (int)halfStr.size() - 1; i >= 0; i--) result.push_back(halfStr[i]);
        return result;
    }
};