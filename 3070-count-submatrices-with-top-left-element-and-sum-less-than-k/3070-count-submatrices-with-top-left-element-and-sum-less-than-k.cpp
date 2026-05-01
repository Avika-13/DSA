class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>prefix(n, vector<int>(m, 0));
        int sum = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 0; j < m; j++){
                sum += grid[i][j];
                prefix[i][j] = sum;
            }
        }

        int count = 0;
        for (int j = 0; j < m; j++){
            int sum = 0;
            for (int i = 0; i < n; i++){
                sum += prefix[i][j];
                prefix[i][j] = sum;
                if(prefix[i][j] <= k) count++;
            }
        }
        return count;
    }
};