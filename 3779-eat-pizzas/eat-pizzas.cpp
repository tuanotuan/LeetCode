class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = (int)pizzas.size();
        int eat = n / 4;
        vector < int > v;
        for(int i = n / 2; i < n; i++)
        v.push_back(pizzas[i]);
        long long s = 0;
        int eatz = (eat + 1) / 2;
        n /= 2;
        for(int i = n - eatz; i < n; i++)
        s += v[i];
        int id = eatz, eaty = eat - eatz;
        while(eaty){
            s += v[id];
            id += 2;
            eaty--;
        }
        return s;
    }
};