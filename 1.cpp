// O(n^2) time complexity but O(1) space complexity

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator p,q;
        bool flag = true;
        for(p = nums.begin();p != nums.end() && flag;++p){
            for(q = p+1;q != nums.end() && flag;++q){
                if(*p + *q == target) flag = false;
            }
        }
        
        
        vector<int> v(2);
        v[0] = p - nums.begin()-1;
        v[1] = q - nums.begin()-1;
        return v;
    }
};