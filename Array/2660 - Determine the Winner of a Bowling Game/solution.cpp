class Solution {
public:
    int getScore(vector<int>& player) {
        int score = 0;
        int n = player.size();

        for (int i = 0; i < n; i++) {
            if ((i >= 1 && player[i - 1] == 10) ||
                (i >= 2 && player[i - 2] == 10)) {
                score += 2 * player[i];
            } else {
                score += player[i];
            }
        }

        return score;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = getScore(player1);
        int s2 = getScore(player2);

        if (s1 > s2)
            return 1;
        if (s2 > s1)
            return 2;
        return 0;
    }
};