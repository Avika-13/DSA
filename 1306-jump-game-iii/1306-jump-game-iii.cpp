class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (arr[node] == 0)
                return true;
            int l = node - arr[node];
            int r = node + arr[node];
            if (l >= 0 && !visited[l]) {
                q.push(l);
                visited[l] = true;
            }
            if (r < n && !visited[r]) {
                q.push(r);
                visited[r] = true;
            }
        }
        return false;
    }
};