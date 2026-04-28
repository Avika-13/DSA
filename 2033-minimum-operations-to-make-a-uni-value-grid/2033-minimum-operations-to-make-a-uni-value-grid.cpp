class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r=grid.size(),c=grid[0].size();
        vector<int>sa;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                sa.push_back(grid[i][j]);
            }
        }
        sort(sa.begin(),sa.end());
        int n=sa.size();
        int mid=sa[(n-1)/2];
        int count=0;
        for(int i=0;i<n;i++){
            if(abs(sa[i]-mid)%x!=0) return -1;
            count+=abs(sa[i]-mid)/x;
        }
        return count;
    }
};