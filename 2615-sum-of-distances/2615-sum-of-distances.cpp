class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> d;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            d[nums[i]].push_back(i);
        }
        vector<long long> res(n, 0);
        for (auto& [_, v] : d) {
            if (v.size() > 1) {
                int c = v.size();
                int i = v[0];
                long long sum = 0;
                for (int x : v) 
                    sum += x;
                res[i] = sum - 1LL * c * i;
                int x = 0, y = c - 2;
                for (int k = 1; k < c; k++) {
                    int nidx = v[k];
                    res[nidx] = res[i] + 1LL * (x - y) * (nidx - i);
                    x++;
                    y--;
                    i = nidx;
                }
            }
        }
        return res;
    }
};