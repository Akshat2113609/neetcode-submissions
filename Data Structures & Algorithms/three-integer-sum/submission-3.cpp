class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int k=i+1;
            int j = n-1;
            while(k<j){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[k],nums[j]});
                    while(k<j && nums[k]==nums[k+1]){k++;}
                    while(k<j && nums[j]==nums[j-1]){j--;}
                    k++;
                    j--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    j--;
                }
                else{
                    k++;
                }
            }
        }
    return ans;
    }
};