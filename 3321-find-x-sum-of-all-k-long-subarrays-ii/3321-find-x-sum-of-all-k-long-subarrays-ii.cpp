class Solution {
public:

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<pair<long long, long long>> containerMx, containerMn;
        nums.insert(nums.begin(), 0ll);
        int n = nums.size();
        unordered_map<long long, long long> counter;
        for (int i  = 0; i < k; i++) {
            counter[nums[i]]++;
        }
        long long sum = 0;
        for (auto ele : counter) {
            // cout << ele.first << " " << ele.second << endl;
            containerMx.insert(make_pair(ele.second, ele.first));
            sum += ele.first * ele.second;
        }
        vector<long long> ans;
        // cout << sum << endl;

        for (int i = k; i < n; i++) {
            int num1 = nums[i];
            int val1 = counter[num1];
            pair<long long, long long> p1 = make_pair(val1, num1);

            int num2 = 0;
            if ((i-k) >= 0) num2 = nums[i-k];
            // cout << num1 << " Pos " << i << endl;
            int val2 = counter[num2];
            pair<long long, long long> p2 = make_pair(val2, num2);

            if (num1 == num2) {
                ans.push_back(sum);
                continue;
            }

            if (containerMx.contains(p1)) {
                sum -= p1.first * p1.second;
                containerMx.erase(p1);
            }
            if (containerMx.contains(p2)) {
                sum -= p2.first * p2.second;
                containerMx.erase(p2);
            }
            
            containerMn.erase(p1);
            containerMn.erase(p2);
            p1.first++;
            p2.first--;
            counter[num1]++;
            // if (num2 > 0)
            counter[num2]--;
            
            if (!containerMn.empty()) {
                auto it = std::prev(containerMn.end());  // get iterator to last (largest) element
                auto p3 = *it;                           // copy the pair before erasing

                containerMn.erase(it);                   // erase by normal iterator
                containerMx.insert(p3);                  // insert the pair into the other container

                sum += p3.second * p3.first;                        // access .second of the pair
            }

            sum += p1.first * p1.second;
            sum += p2.first * p2.second;
            containerMx.insert(p1);
            containerMx.insert(p2);
            while (containerMx.size() > x) {
                auto it = containerMx.begin();   // iterator to smallest element
                auto cur = *it;                  // copy the pair BEFORE erasing
                // cout << cur.first << " " << cur.second << endl;
                sum -= cur.first * cur.second;               // subtract the .second value

                containerMx.erase(it);           // erase using the iterator
                
                containerMn.insert(cur);         // insert the pair into containerMn
            }
            // cout << endl;

            // cout << "Now have" << endl;
            // for (auto v : containerMx) {
            //     cout << v.first << " " << v.second << endl;
            // }
            // cout << "finished" << endl;

            ans.push_back(sum);
        }
        return  ans;
    }
};