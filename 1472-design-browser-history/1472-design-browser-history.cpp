class BrowserHistory {
public:
    BrowserHistory(const string &homepage) {
        container.clear();
        container.push_back(homepage);
        index = 0;
    }
    
    void visit(const string &url) {
        if ((index+1) == container.size()) {
            container.push_back(url);
            index++;
        } else {
            container[++index] = url;
            container.resize(index + 1);
        }
    }
    
    string back(int steps) {
        index -= steps;
        index = max(index, 0);
        return container[index];
    }
    
    string forward(int steps) {
        index += steps;
        index = min(index, (int)container.size() - 1);
        
        return container[index];
    }
private:
    int index = 0;
    vector<string> container;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */