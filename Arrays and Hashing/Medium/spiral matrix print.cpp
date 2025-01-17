Prob Link:-"https://leetcode.com/problems/spiral-matrix/description/"

Only 1 solution(brute/better/optimal)

    STEPS:-
        Step-1:make top,bottom , left,right var 
        Step-2:Upar wali row ko print karne ke liye left se right loop chalado,(top++; karna mat bhuliye)
               Right wali col ko print karne ke liye top se bottom tak loop chalado,(right--; karna mat bhuliye)
               Bottom wali row ko print karne ke liye right se left tak loop chalado,(bottom--; karna mat bhuliye)
               Left wali col print karne ke liye bottom se top tak loop chalado.(left++; karna mat bhuliye)
        => Har step par check if(top>bottom || left>right)break;



    CODE:-
         vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();int n=matrix[0].size();
        vector<int>ans;
        int top=0,bottom=m-1,left=0,right=n-1;
        
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++)ans.push_back(matrix[top][i]);
                top++;
            for(int i=top;i<=bottom;i++)ans.push_back(matrix[i][right]);
                right--;
            if(top>bottom || left>right)break;
            for(int i=right;i>=left;i--)ans.push_back(matrix[bottom][i]);
                bottom--;
            if(top>bottom || left>right)break;
            for(int i=bottom;i>=top;i--)ans.push_back(matrix[i][left]);
                left++;
            
        }
        return ans;
    }