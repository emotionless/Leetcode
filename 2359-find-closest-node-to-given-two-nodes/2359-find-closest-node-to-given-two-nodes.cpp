class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == -1 && node2 == -1) return -1;
        else if (node1 == node2) return node1;
        else if (visited1.count(node2) && visited2.count(node1)) return min(node1, node2);
        else if (visited1.count(node2)) return node2;
        else if (visited2.count(node1)) return node1;
        if (visited1.count(node1) && visited2.count(node2)) return -1;
        visited1.insert(node1);
        visited2.insert(node2);
        return closestMeetingNode(edges, node1 != -1? edges[node1] : -1, node2 != -1? edges[node2] : -1);
    }
private:
    unordered_set<int> visited1, visited2;
};

/*
2 0 1 3  
\ | |//
 \| 4
  5
  |
  6


*/