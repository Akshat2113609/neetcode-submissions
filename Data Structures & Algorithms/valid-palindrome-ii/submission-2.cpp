class Solution {
public:
    bool isAlphaNum(char c){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c<='0'&&c>='9')){
            return true;
        }
        return false;
    }
    bool validPalindrome(string s) {
        int cnt=0;
        string processed="";
        for(auto& it:s){
            if(isAlphaNum(it)){
                processed+=it;
            }
        }
        int low=0;
        int high=static_cast<int>(processed.size())-1;
        while(low<high){
            if(processed[low]!=processed[high]){
               string skipL = processed.substr(low+1,high-low);
               string skipR = processed.substr(low,high-low);
               cout<<"skipL: "<<skipL<<endl;
               cout<<"skipR: "<<skipR<<endl;
               string rskipL = skipL;
               reverse(skipL.begin(),skipL.end());
               string rskipR = skipR;
               reverse(skipR.begin(),skipR.end());
               if(skipL!=rskipL && skipR!=rskipR){
                 return false;
               }
            }
            low++;
            high--;
        }
        return true;
    }
};