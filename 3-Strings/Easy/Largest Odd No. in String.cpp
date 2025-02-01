Prob Link : "https://leetcode.com/problems/largest-odd-number-in-string/description/"

CODE:- 
        string largestOddNumber(string num) {
            int n=num.size();
            if(num[n-1]%2 ==1)return num;
            for(int i=n-1;i>=0;i--){
                //if odd no. is found
                if(num[i]%2==1){
                    string ans = num.substr(0,i+1);
                    return ans;
                }
            }
        return "";
        }