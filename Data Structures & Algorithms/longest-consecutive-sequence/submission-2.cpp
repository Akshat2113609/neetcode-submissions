class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int ans=INT_MIN;
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            int val = nums[i];
            if(st.find(nums[i]-1)!=st.end()){
                continue;
            }
            else{
                for(int j=i+1;j<n;j++){
                    if((nums[j]-val)==1){
                        cnt++;
                        val=nums[j];
                    }
                }
            }
            ans = max(ans,cnt+1);
            cnt=0;
        }
    return ans;
    }
};
