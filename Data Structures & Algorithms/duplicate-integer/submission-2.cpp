class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(auto &it:nums){
            st.insert(it);
        }
        return st.size()<n;
    }
};
