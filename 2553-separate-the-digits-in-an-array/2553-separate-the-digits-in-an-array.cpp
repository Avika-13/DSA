class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string total;
        for (int i = 0; i < nums.size(); i++){
            total += to_string(nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i < total.size(); i++){
            ans.push_back(total[i] - '0');
        }
        return ans;
    }
};