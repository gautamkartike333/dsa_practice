Prob Link: "https://leetcode.com/problems/search-a-2d-matrix-ii/description/"

Hint-1:- aap ye dekho ki kaise aap search space ko reduce kar sakte ho , or ek or cheej dhundo konsa patttern arrray me sorted hau , jaha se start karke aap search space ko chota kar sate ho 

    














Hint-2:- Aapke paas char starting positions hain mainly -> wo aap socho ab konsi , combine both hinsts and then think

























CODE:-
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n=matrix.size(),m=matrix[0].size();
            int row=0,col=m-1;
            while(row<n && col>=0){
                if(matrix[row][col]==target)return true;
                else if(matrix[row][col]<target)row++;
                else col--;
            }
        return false;
        }