Prob link: "https://leetcode.com/problems/search-a-2d-matrix/description/"

Hint:- use normal binary search , -> bas thoda sa dimaag lagana padega -> socho-socho?
T.C. - O( log(n+m) )





















CODE:-
            bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n=matrix.size(),
                m=matrix[0].size();

            int l=0,r=m*n-1,mid;

            while(l<=r){   
                mid=l+((r-l)/2);
                int row=mid/m,
                    col=mid%m;
                
                if(matrix[row][col]==target)return true;
                else if(matrix[row][col]>target)r=mid-1;
                else l=mid+1;
            
            }
                return false;
            }