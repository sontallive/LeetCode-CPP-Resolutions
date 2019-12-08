class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        int c = 1;
        long result = 0;
        for(string::iterator it = str.begin();it != str.end();it++){
            if(start == 0){
                if(*it == ' ') continue;
                else{
                    if(*it == '-'){
                        c = -1;
                        start = 1;
                    }else if(*it == '+'){
                        c = 1;
                        start = 1;
                    }else if(*it >= '0' && *it <= '9'){
                        result = *it - '0';
                        start = 1;
                    }else{
                        return 0;
                    }
                }
            }else{
                if(*it == '.') break;
                if(*it >= '0' && *it <= '9'){
                    result *= 10;
                    result += *it - '0';
                    if(result*c < INT_MIN) return INT_MIN;
                    if(result*c > INT_MAX) return INT_MAX;
                }else{
                    break;
                }
            }
        }
        result *= c;
        
        return result;
    }
};