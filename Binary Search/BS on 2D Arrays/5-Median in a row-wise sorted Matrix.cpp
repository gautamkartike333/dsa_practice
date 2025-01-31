Prob Link: "https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1"



Hint:- arr[mid] se chote elements count karlo pure matrix me , agar wo (no. of el)/2 ke equal hain , toh usase agla wala median hoga -> try to reduce complexity of the alog. of finding how many nos. in matrix are smaller than arr[mid]



























CODE:-  
        int count(vector<int>mat,int m,int x){
            int low=0,high=m-1,mid;
            
            while(low<=high){
                mid=low+((high-low)/2);
                
                if(mat[mid]>x)high=mid-1;
                else low=mid+1;
            }
            return low;
        }
        
        int countsmallno(vector<vector<int>> &mat,int n,int m,int x){
            int ct=0;
            for(int i=0;i<n;i++){
                ct += count(mat[i],m,x);    
            }
            return ct;
        }
        int median(vector<vector<int>> &mat) {
            // code here
            int n=mat.size(),m=mat[0].size();
            int low=INT_MAX,high=INT_MIN;
            for(int i=0;i<n;i++){
                low =min( low,mat[i][0]);
                high=max(high,mat[i][m-1]);
            }
            
            int mid;int req=(m*n)/2;
            while(low<=high){
                mid=low+((high-low)/2);
                int smallno=countsmallno(mat,n,m,mid);
                if(smallno<=req)low=mid+1;
                else high=mid-1;
            }
        return low;
        }