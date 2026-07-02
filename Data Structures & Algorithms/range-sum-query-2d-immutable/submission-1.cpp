class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       mat = vector<vector<int>>(n+1,vector<int>(m+1,0));

       for(int i=0;i<n;i++){
        int pref = 0;
        for(int j=0;j<m;j++){
            pref+=matrix[i][j];
            mat[i+1][j+1]=pref+mat[i][j+1];
        }
       }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int nr1=row1+1;
        int nr2=row2+1;
        int nc1=col1+1;
        int nc2=col2+1;
        int bottomRight = mat[nr2][nc2];
        int above = mat[nr1-1][nc2];
        int left = mat[nr2][nc1-1];
        int topLeft = mat[nr1-1][nc1-1];
        return bottomRight - above - left + topLeft;

    }
};