class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);

        unordered_map<int,int> xmp;
        unordered_map<int,int> ymp;

        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];

            if(xmp.count(x)){
                dsu.unite(i,xmp[x]);
            }
            else {
                xmp[x] = i;
            }

            if(ymp.count(y)){
                dsu.unite(i,ymp[y]);
            }
            else {
                ymp[y] = i;
            }
        }

        int largest = 0;
        int secondLargest = 0;

        for(int i=0;i<n;i++){
            if(dsu.find(i) == i){
                if(dsu.size[i] > largest){
                    secondLargest = largest;
                    largest = dsu.size[i];
                }
                else if(dsu.size[i] > secondLargest){
                    secondLargest = dsu.size[i];
                }
            }
        }

        if(secondLargest == 0){
            return largest + 1;
        }

        return largest + secondLargest + 1;
    }
};