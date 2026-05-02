class Solution {
public:
    void solve(vector<int>& digits, int curr, int& result, int n, bool flag){
        if (curr == 0 || curr > n) return;
        if (!flag) ++result;

        if (curr == -1) curr = 0;
        curr *= 10;
        for (int digit: digits){
            if (digit == 0 || digit == 1 || digit == 8)
                solve(digits, curr + digit, result, n, flag && true);
            else
                solve(digits, curr + digit, result, n, false);
        }
    }

    int rotatedDigits(int n) {
        vector<int> digits {0,1,2,5,6,8,9};
        int result = 0;

        solve(digits, -1, result, n, true);
        return result;
    }
};