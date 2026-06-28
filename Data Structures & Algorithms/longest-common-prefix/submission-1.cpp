class Solution {
public:
    bool isValid(string &temp,vector<string>& strs){
        int n = temp.size();
        for(int j=1;j<strs.size();j++){
            string val = strs[j];
            int i=0;
            while(i<n){
                if(temp[i]!=val[i]){
                    return false;
                }
                i++;
            }
        }
    return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string key=strs[0];
        for(int i=0;i<key.size();i++){
            string temp=key.substr(0,(key.size())-i);
            if(isValid(temp,strs)){
                return temp;
            }
        }
    return "";
    }
};