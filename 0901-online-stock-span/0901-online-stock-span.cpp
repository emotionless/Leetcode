class StockSpanner {
public:
    pair<int, int> S[10001];
    int id = 0;
    int ind = -1;
    StockSpanner() {
        ind = 0;
        id = 0;
    }
    
    int next(const int price) {
        int pos = -1;
        while(id > 0 && S[id - 1].first <= price) {
            id--;
        }
        if (id) pos = S[id - 1].second;
        pos++;
        S[id++] = make_pair(price, ind++);
        return ind - pos;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */