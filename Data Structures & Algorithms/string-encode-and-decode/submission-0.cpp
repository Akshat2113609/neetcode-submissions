class Solution {
public:

    string encode(vector<string>& strs) {
        string enc="";
        for(auto &it:strs){
            enc+=to_string(it.length())+"#"+it;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string>dec;
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            dec.push_back(s.substr(i,len));
            i+=len;
        }
    return dec;
    }
};
