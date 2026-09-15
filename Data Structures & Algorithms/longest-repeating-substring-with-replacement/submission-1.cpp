class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mp;
        int res=0;
        int left=0;
        int maxf=0;
        for(int i=0;i<n;i++){
           mp[s[i]]++;
           maxf = max(maxf,mp[s[i]]);
           while((i-left+1)-maxf > k){
              mp[s[left]]--;
              left++;
           }
           res = max(res,i-left+1);
        }
    return res;
    }
};
