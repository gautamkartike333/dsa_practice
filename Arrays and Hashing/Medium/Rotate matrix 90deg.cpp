Prob Link:"https://leetcode.com/problems/rotate-image/"

 void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                ans[j][i]=matrix[n-1-i][j];
            }
        }
    matrix=ans;
    }

Space optimization:-
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            reverse(matrix[i].begin(),matrix[i].end());
        }
    
    }