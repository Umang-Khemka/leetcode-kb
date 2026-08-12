class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());

        if(!st.count(endGene)){
            return -1;
        }

        queue<string> q;
        q.push(startGene);

        unordered_set<string> vis;
        vis.insert(startGene);

        int mutations = 0;
        string chars = "ACGT";

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string current = q.front();
                q.pop();

                if(current == endGene){
                    return mutations;
                }

                for(int i=0;i<8;i++){
                    char original = current[i];

                    for(char c : chars){
                        current[i] = c;

                        if(st.count(current) && !vis.count(current)){
                            vis.insert(current);
                            q.push(current);
                        }
                    }
                    current[i] = original;
                }
            }
            mutations++;
        }
        return -1;
    }
};