class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int &it:nums){
            int idx = abs(it)-1;
            if(nums[idx]<0){
                return abs(it);
            }
            nums[idx]*=-1;
        }
    return -1;
    }
};
