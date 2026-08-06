class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int x = n;x<=n+9;x++){
            int mul = 1;
            int y = x;

            while(y){
                mul *= y % 10;
                y /= 10;
            }

            if(mul % t == 0){
                return x;
            }
        }
        return -1;
    }
};