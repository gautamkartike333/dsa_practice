Prob Link:-"https://leetcode.com/problems/pascals-triangle/description/"

(variation-1)
to find out element in a pascal's triangle , formula= r-1Cc-1
    =(r-1)!/((c-1)!(r-c)!)

    CODE:-
        int nCr(int n, int r) {
            long long res = 1;

            // calculating nCr:
            for (int i = 0; i < r; i++) {
                res = res * (n - i);
                res = res / (i + 1);
            }
            return res;
        }

        int pascalTriangle(int r, int c) {
            int element = nCr(r - 1, c - 1);
            return element;
        }

(variation-2)
FOR PRINTING FULL ROW:-
    (This u have to understand from video if u want O(N) solution )

(variation-3)
FOR PRINTING FULL PASCAL'S TRIANGLE
    (use code to print every row from variation-2 ques)
        vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); //inserting the 1st element

        //calculate the rest of the elements:
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> pascalTriangle(int n) {
        vector<vector<int>> ans;

        //store the entire pascal's triangle:
        for (int row = 1; row <= n; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }