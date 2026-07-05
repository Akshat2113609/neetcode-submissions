class Solution {
public:
    int calculateBack(int i, vector<int>& nums){
        int n = nums.size();
        int ans=1;
        for(int k=0;k<i;k++){
            ans*=nums[k];
        }
        return ans;
    }
     int calculateFront(int i, vector<int>& nums){
        int n = nums.size();
        int ans=1;
        for(int k=i+1;k<n;k++){
            ans*=nums[k];
        }
        return ans;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int p=1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int b = calculateBack(i,nums);
            int f = calculateFront(i,nums);
            ans.push_back(b*f);
        }
    return ans;
    }
};
