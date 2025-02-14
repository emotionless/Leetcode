class ProductOfNumbers {
public:
    /*
    ProductOfNumbers() {
        arr.clear();
    }
    
    void add(int num) {
        if (num == 0) arr.clear();
        if (num == 1) {
            int sz = arr.size();
            if (sz > 0 && arr[sz - 1].first == 1) {
                arr[sz - 1].second++;
            } else {
                arr.push_back({1, 1});
            }
        } else {
            arr.push_back({num, 1});
        }
    }
    
    int getProduct(int k) {
        int sz = arr.size();
        int res = 1;
        int ind = sz - 1;
        while(k > 0 && ind >= 0) {
            if (arr[ind].second > 1) {
                k -= arr[ind].second;
            } else {
                res *= arr[ind].first;
                k--;
            }
            ind--;
        }
        return res;
    }
    */
    
    ProductOfNumbers() {
        arr.clear();
        arr.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            arr.clear();
            arr.push_back(1);
        } else {
            arr.push_back(arr.back() * num);
        }
    }
    
    int getProduct(int k) {
        int sz = arr.size();
        if (k >= sz) return 0;
        return arr.back() / arr[sz - k - 1];
    }
    
    
private:
    vector<int> arr;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */