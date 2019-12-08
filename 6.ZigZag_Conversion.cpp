class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len <= 2 || len <= numRows || numRows == 1) return s;
        int step = 2 * numRows - 2;
        string ans;
        for(int i = 0;i < numRows;i++){
            int round = 0;
            while(round * step + i < len){
                ans += s[round * step + i];
                if(i != 0 && i != numRows - 1 && (round + 1) * step - i < len){
                    ans += s[(round + 1) * step - i];
                }
                round++;
            }
        }
        
        return ans;
    }
};