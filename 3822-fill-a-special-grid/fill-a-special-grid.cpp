int calc(int n, int x, int y){
    if(n == 1){
    if(x == 0 && y == 0)
    return 3;
    if(x == 0 && y == 1)
    return 0;
    if(x == 1 && y == 0)
    return 2;
    if(x == 1 && y == 1)
    return 1;
    }
    int sz = 1 << (n - 1);
    int block = sz * sz;
    if(x < sz && y < sz)
    return 3 * block + calc(n-1,x,y);
    if(x >= sz && y < sz)
    return 2 * block + calc(n-1,x-sz,y);
    if(x >= sz && y >= sz)
    return block + calc(n-1,x-sz,y-sz);
    if(x < sz && y >= sz)
    return calc(n-1,x,y-sz);
    return -1;
}
class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int m = 1 << n;
        vector < vector < int > > v(m, vector<int>(m,0));
        if(m == 1)
        return v;
        for(int i = 0;  i < m; i++){
            for(int j = 0; j < m; j++)
            v[i][j] = calc(n,i,j);
        }
        return v;
    }
};