class Solution {
public:
    
    int n;
    vector<int>store[15];
    int dp[15];
    bool DFS(int u, vector<vector<int>> graph)
    {
        if(u == n-1) return true;
        
        int &ret = dp[u];
        if(ret != -1) return ret;
        ret = 0;
        
        for(auto v:graph[u])
        {
            int isPossible = DFS(v, graph);
            if(isPossible)
                store[u].push_back(v);
            ret += isPossible;
        }
        return ret;
    }
    
    vector<vector<int>> res;
    
    void Backtrack(int u, vector<int> curr)
    {
        if(u == n-1)
        {
            res.push_back(curr);
            return;
        }
        for(auto v:store[u])
        {
            curr.push_back(v);
            Backtrack(v, curr);
            curr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        memset(dp, -1, sizeof dp);
        DFS(0, graph);
        
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<i<<" : ";
        //     for(auto v:store[i])
        //         cout<<v<<" ";
        //     cout<<endl;
        // }
        vector<int>now;
        now.push_back(0);
        Backtrack(0, now);
        
        return res;
    }
};