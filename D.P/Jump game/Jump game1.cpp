// Question : https://leetcode.com/problems/jump-game/submissions/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return true;
        int step = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] >= step - i) 
                step = i;
        }
        if(step == 0)
            return true;
        return false;
        
    }
};
