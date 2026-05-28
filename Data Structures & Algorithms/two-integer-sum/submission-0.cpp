class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int num=target-nums[i];
            if(mp.find(num)!=mp.end()){
                ans.push_back(mp[num]);
                ans.push_back(i);
                break;
            }
            else{
                mp[nums[i]]=i;
            }
        }
        if(ans.empty()){
            return {-1,-1};
        }
    return ans;
    }
};
