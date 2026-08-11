class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n * n + 1,false);

        queue<int> q;
        q.push(1);
        vis[1] = true;

        int rolls = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                if(curr == n * n){
                    return rolls;
                }

                for(int i=1;i<=6;i++){
                    int next = curr + i;

                    if(next > n * n){
                        break;
                    }

                    int level = (next - 1)/ n + 1;

                    int row = n - level;

                    int col = (next - 1) % n;

                    if(level % 2 == 0){
                        col = n - 1 - col;
                    }

                    if(board[row][col] != -1){
                        next = board[row][col];
                    }

                    if(!vis[next]){
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
            rolls++;
        }
        return -1;
    }
};