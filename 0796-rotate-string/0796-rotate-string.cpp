class Solution {
public:
    bool rotateString(string s, string goal) {
        int size = s.size();

        while(size>0){
            char last = s.back();
            s.pop_back();
            s = last+s;
            if(s==goal) return true;
            size--;
        }
        return false;
    }
};