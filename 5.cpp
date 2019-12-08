#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {

        int length = s.length();
        if(length == 0){
            return string("");
        }
        if(length == 1){
            return s;
        }
        for(int i = length;i>=0;i--){    
            s = s.substr(0,i).append("#").append(s.substr(i,s.length()-i));
        }
        cout << s << endl;
        
        length = s.length();

        int maxlength = 0;
        int maxid = -1;
        for(int i = 0;i < length;i++){
            int j = 1;
            for(;j <= min(i,length -i -1);j++){
                if(s[i-j] != s[i+j]){
                    if(j-1 > maxlength){
                        maxlength = j-1;
                        maxid = i;
                    }
                    break;
                }
            }
            if(j==i+1 || j == length-i){
                if(j-1 > maxlength){
                    maxlength = j-1;
                    maxid = i;
                }
            }
        }
        string temp = s.substr(maxid-maxlength,maxlength*2 +1);
        for(string::iterator it=temp.begin();it!=temp.end();it++){
            if(*it=='#'){
                temp.erase(it);
                it--;
            }
        }
        return temp;
    }
};

int main(){

    Solution solution;
    string question("ac");
    string answer = solution.longestPalindrome(question);
    cout << answer << endl;
    return 0;
}