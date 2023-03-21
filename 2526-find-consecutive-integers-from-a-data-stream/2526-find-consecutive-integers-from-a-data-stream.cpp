class DataStream {
public:
    DataStream(int _value, int _k) {
        value = _value;
        k = _k;
    }
    
    bool consec(int num) {
        if (num == value) cnt++;
        else cnt = 0;
        return cnt >= k;
    }
private:
    int k, value;
    int cnt = 0;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */