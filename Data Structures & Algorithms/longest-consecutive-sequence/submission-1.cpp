class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int val = nums[i];
            for(int j=i+1;j<n;j++){
                if(abs(val-nums[j])==1){
                    cnt++;
                    val = nums[j];
                }
            }
            ans=max(cnt+1,ans);
            cnt=0;
        }
    return ans;
    }
};
