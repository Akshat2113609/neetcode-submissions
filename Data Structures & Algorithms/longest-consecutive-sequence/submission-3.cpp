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
            int val = 1;
            while(st.find(nums[i]+val)!=st.end()){
                val++;
            }
            ans = max(ans,val);
        }
    return ans;
    }
};
