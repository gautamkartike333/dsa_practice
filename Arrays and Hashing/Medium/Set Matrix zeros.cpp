Prob Link:"https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2"

Optimal approach is very confusing type , so be careful:-

Better Approach:-
    CODE:-
        void markrow(vector<vector<int>>& matrix,int i,int m){

            for(int j=0;j<m;j++)
            if(matrix[i][j]!=0)
            matrix[i][j]=-10;
        }
        void markcol(vector<vector<int>>& matrix,int j,int n){

            for(int i=0;i<n;i++)
            if(matrix[i][j]!=0)
            matrix[i][j]=-10;
        }
        void setZeroes(vector<vector<int>>& matrix) {
            int n=matrix.size(),m=matrix[0].size();
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        markrow(matrix,i,m);
                        markcol(matrix,j,n);
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==-10)matrix[i][j]=0;
                }
                }
            
        }

Optimal Approach:-
    CODE:-
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();int m=matrix[0].size();
        // vector<int>row(n,0);vector<int>col(m,0);
        int col0=1;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        if(j!=0)
                        matrix[0][j]=0;
                        else col0=0;
                        matrix[i][0]=0;
                    }
                }
            }
        for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(matrix[0][j]==0 || matrix[i][0]==0)matrix[i][j]=0;
                }
            }
        if(matrix[0][0]==0){
            for(int i=0;i<m;i++)matrix[0][i]=0;
        }
        if(col0==0){
            for(int i=0;i<n;i++)matrix[i][0]=0;
        }
    }

