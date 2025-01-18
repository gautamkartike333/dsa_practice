Prob Link:"https://www.interviewbit.com/problems/subarray-with-given-xor/"

CODE:
        int Solution::solve(vector<int> &A, int B) {
            int n1=A.size();
            map<int,int>mapp;int ct=0;
            int xorr=0;mapp[0]++;
            for(int i=0;i<n1;i++){
                xorr=xorr^A[i];
                // cout<<"i="<<i<<"xorr="<<xorr<<endl;
                if(mapp.find(B^xorr) != mapp.end()){ct=ct+mapp[(B^xorr)];}
                mapp[xorr]++;
                // sett.insert(xorr);
            }
            // for(auto it:sett){cout<<it<<" , ";}
            return ct;
            
        }