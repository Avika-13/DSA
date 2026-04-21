class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];

        };
        auto uni = [&](int a, int b) {
            int fa = find(a), fb = find(b);
            if (fa == fb) 
                return;

            if (rank[fa] < rank[fb]) 
                swap(fa, fb);

            parent[fb] = fa;
            if (rank[fa] == rank[fb])
                rank[fa]++;
        };

        for (auto& p : allowedSwaps) {
            uni(p[0], p[1]);
        }

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int ans = 0;
        for (auto& [_, idxs] : groups) {
            unordered_map<int, int> freq;
            for (int i : idxs) {
                freq[source[i]]++;
            }

            for (int i : idxs) {
                if (freq[target[i]] > 0) {
                    freq[target[i]]--;
                } else {
                    ans++;
                }
            }

        }
        return ans;
    }
};