class Solution {
public:
    bool validCheck(vector<char>nums){
        set<char>st;
        int cnt=0;
        for(auto it:nums){
           if(it == '.'){
            continue;
           }
           if(st.find(it)!=st.end()){
            return false;
           }
           st.insert(it);
        }
        return true;
    }
    bool subGridCheck(vector<vector<char>>& board){
        for(int s=0;s<9;s++){
            set<char>st;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int r = (s/3)*3+i;
                    int c = (s%3)*3+j;
                    if(board[r][c]=='.'){
                        continue;
                    }
                    if(st.find(board[r][c])!=st.end()){
                        return false;
                    }
                    st.insert(board[r][c]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!validCheck(board[i])){
                return false;
            }
        }
        vector<vector<char>>cols;
        for(int i=0;i<9;i++){
            vector<char>temp;
            for(int j=0;j<9;j++){
                temp.push_back(board[j][i]);
            }
            cols.push_back(temp);
        }
        for(int i=0;i<9;i++){
            if(!validCheck(cols[i])){
                return false;
            }
        }
        if(!subGridCheck(board)){
            return false;
        }
        return true;
    }
};
