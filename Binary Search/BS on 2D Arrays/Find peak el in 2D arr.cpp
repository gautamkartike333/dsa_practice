Prob Link: "https://leetcode.com/problems/find-a-peak-element-ii/description/"

Hint:- 
    row me bs lagake mid pe , uss col me maxel dhundo -> check that maxel is peak or not if ->yes then return both indices , else reduce the halves


























CODE:- 
            int maxelind(vector<vector<int>>& mat,int mid, int n, int m){
                int maxel=INT_MIN,maxi=-1;  
                for(int i=0;i<n;i++){
                    if(mat[i][mid]>maxel){
                        maxi=i;
                        maxel=mat[i][mid];
                    }
                }
            return maxi;
            }
            vector<int> findPeakGrid(vector<vector<int>>& mat) {
                int n=mat.size(),m=mat[0].size();
                int l=0,r=m-1,mid;
                
                while(l<=r){
                    mid=l+((r-l)/2);
                    int row=maxelind(mat,mid,n,m);

                    int left= mid-1>=0 ? mat[row][mid-1] : -1;
                    int right= mid+1<=m-1 ? mat[row][mid+1] : -1;
                    if(mat[row][mid]>left && mat[row][mid]>right){return {row,mid};}
                    else if(mat[row][mid]<left )r=mid-1;
                    else l=mid+1;
                }
            return {-1,-1};
            }