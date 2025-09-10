class Solution {
public:

    bool isCommon(vector<int> &first, vector<int> &second) {
        int i = 0, j = 0;
        while (i < first.size() && j < second.size()) {
            if (first[i] == second[j]) return true;
            if (first[i] < second[j]) i++;
            else j++;
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        for (auto &language : languages) {
            sort(language.begin(), language.end());
        }
        vector<int> counter(n+ 1,  0);
        int mx = 0;
        int ans = 0;
        unordered_set<int> container;
        for (auto friendship : friendships) {
            int u = friendship[0] - 1;
            int v = friendship[1] - 1;
            if (!isCommon(languages[u], languages[v])) {
                // for (auto l : languages[u]) {
                //     counter[l]++;
                //     // if (counter[l] > mx) {
                //     //     mx = counter[l];
                //     //     ans = l;
                //     // }
                // }
                // for (auto l : languages[v]) {
                //     counter[l]++;
                //     // mx = max(mx, counter[l]);
                //     // if (counter[l] > mx) {
                //     //     mx = counter[l];
                //     //     ans = l;
                //     // }
                // }
                container.insert(u);
                container.insert(v);
            }
        }

        for (auto u : container) {
            for (auto l : languages[u]) {
                counter[l]++;
            }
        }
        
        int res = 0;
        for (int l = 1; l <= n; l++) {
            if (counter[l] > mx) {
                mx = counter[l];
                ans = l;
            }
        }
        cout << mx << " " << ans << endl;
        vector<int> common;
        common.push_back(ans);
        for (auto u : container) {
            if (!isCommon(languages[u], common)) res++;
        }
        // for (auto friendship : friendships) {
        //     int u = friendship[0] - 1;
        //     int v = friendship[1] - 1;
        //     if (!isCommon(languages[u], languages[v])) {
        //         if (!isCommon(languages[u], common)) res++;
        //         if (!isCommon(languages[v], common)) res++;
        //     }
        // }

        return res;
    }
};