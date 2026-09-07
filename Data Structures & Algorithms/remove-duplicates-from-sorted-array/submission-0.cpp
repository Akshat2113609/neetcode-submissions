class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = 1;
        while(right<n){
            if(nums[right]==nums[right-1]){
                right++;
            }
            else{
                nums[left]=nums[right];
                left++;
                right++;
            }
        }
        return left;
    }
};