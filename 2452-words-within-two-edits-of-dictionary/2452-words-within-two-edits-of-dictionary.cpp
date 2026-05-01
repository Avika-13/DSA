class Solution {
public:
    vector<string> twoEditWords(vector<string>& arr, vector<string>& dic) {
        vector<string> ans;
        for (int i = 0; i < arr.size(); i++){
            for (int j = 0; j < dic.size(); j++){
                string s1 = arr[i], s2 = dic[j];
                int x = 0, y = 0, cnt = 0;
                while (x < s1.size()){
                    if (s1[x] != s2[y]){
                        cnt++;
                    }
                    if (cnt > 2){
                        break;
                    }
                    x++, y++;
                }
                if (cnt <= 2){
                    ans.push_back(s1);
                    break;
                }
            }
        }
        return ans;
    }
};