Prob link: "https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1"

Hint:- Do it in O(n.log(m))


















CODE:-
            int rowWithMax1s(vector<vector<int>> &arr) {
                int maxones=-1;
                int n=arr.size(),m=arr[0].size();
                int maxi=-1;
                // cout<<"n="<<n<<" m="<<m<<endl;
                for(int i=0;i<n;i++){
                    if(arr[i][0]==1)return i;
                    if(arr[i][m-1]==0)continue;
                    
                    int l=0,r=m-1,mid;
                    while(l<=r){
                        mid=l+((r-l)/2);
                        if(arr[i][mid]==1)r=mid-1;
                        else l=mid+1;
                    }
                    if(m-l>maxones){maxi=i;}
                    maxones=max(maxones,m-l);
                }
                return maxi;
            }