class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res=0;
        unordered_map<char,int>mp;
        int left = 0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]] >= left){
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            res=max(res, i - left + 1);
        }
    return res;
    }
};