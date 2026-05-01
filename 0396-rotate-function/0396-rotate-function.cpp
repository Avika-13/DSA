class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int currentSum = 0;
        int totalSum = 0;
        for (int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        for (int i = 0; i < n; i++){
            currentSum += i * nums[i];
        }
        int k = 1;
        int ans = currentSum;

        while (k < n){
            int newSum = totalSum + currentSum - (n * nums[n - k]);
            ans = max(ans, newSum);
            currentSum = newSum;
            k++;
        }
        return ans;
    }
};