class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10 && x >=0) return true;
        string s = to_string(x);
        for(string::iterator p = s.begin(), q = s.end()-1;p!=q;p++,q--){
            if(*p != *q) return false;
            if(p + 1 == q) break;
        }
        return true;
    }
};