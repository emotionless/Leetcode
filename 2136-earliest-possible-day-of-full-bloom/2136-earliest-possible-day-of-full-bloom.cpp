class Solution {
public:
    struct node {
        int plant, grow;
        node(int _plant, int _grow) {
            plant = _plant;
            grow = _grow;
        }
    };
    
    struct comparator {
        inline bool operator() (const node &A, const node &B) {
            if (B.grow == A.grow) {
                return A.plant > B.plant;
            }
            return A.grow < B.grow;
        }
    };
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        priority_queue<node, vector<node>, comparator> pq;
        for (int i = 0; i < n; i++) {
            pq.push(node(plantTime[i], growTime[i]));
        }
        int mx = 0;
        int sum = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            // cout << top.plant << " " << top.grow << endl;
            sum += top.plant;
            mx = max(mx, sum + top.grow);
        }
        return mx;
    }
};