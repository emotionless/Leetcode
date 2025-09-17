class FoodRatings {
public:
    struct Node {
        string name;
        int id;
        int value;
        Node(string _, int __, int ___) {
            name = _;
            id = __;
            value = ___;
        }
    };
    struct CompareNode {
        bool operator()(const Node& a, const Node& b) const {
            // return true if `a` should come *after* `b`
            // (because priority_queue puts the "largest" first)
            if (a.value != b.value)
                return a.value < b.value;
            return a.name > b.name;
        }
    };

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int sz = foods.size();
        for (int i = 0; i < sz; i++) {
            container[cuisines[i]].push(Node(foods[i], gid, ratings[i]));
            latest[foods[i]] = gid;
            gid++;
            cuisineName[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = cuisineName[food];
        container[cuisine].push(Node(food, gid, newRating));
        latest[food] = gid;
        gid++;
    }
    
    string highestRated(string cuisine) {
        auto &curContainer = container[cuisine];
        while (curContainer.size() > 0) {
            auto top = curContainer.top();
            if (top.id != latest[top.name]) {
                curContainer.pop();
            } else {
                return top.name;
            }
        }
        return "";
    }
private:
    int gid = 0;
    unordered_map<string, int> latest;
    unordered_map<string, priority_queue<Node, vector<Node>, CompareNode>> container;
    unordered_map<string, string> cuisineName;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */