class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>bp(n,1);
        vector<int>fp(n,1);
        for(int i=1;i<n;i++){
            bp[i]=nums[i-1]*bp[i-1];
        }
        for(int i=n-1;i>=1;i--){
            fp[i-1]=nums[i]*fp[i];
        }
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=(bp[i]*fp[i]);
        }
        return ans;
    }
};
