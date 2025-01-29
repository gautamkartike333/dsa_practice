Prob Link:-"https://www.naukri.com/code360/problems/allocate-books_1090540?leftPanelTabValue=PROBLEM"

Hint:-
    Hint-1: hame bas jo books bachhon me allot ho rahi hain , unme difference kam se kam karna hai
    
Steps:-
    Step-1:- min no of pages kitne honge , socho socho and max pages kitne allot ho sakte h -> socho socho?
    Step-2:- uske baad tph apko bas wahi binary search ka mid el valid hai ya nhi ye check karna h ki ye mid no. of pages allot ho sakte hain ya nahi ?




























CODE:-

        bool possible(vector<int>arr,int mid,int m,int n){
            int sum=0,ct=1;
            for(int i=0;i<n;i++){
                sum += arr[i];
                if(sum>mid){
                    ct++;
                    sum=arr[i];
                }
                // if(ct==m)return true; --------> ye line isiliye nahi aaegi bcoz agar jyada no of students ko book allot ho rahi hai maanlo toh ye toh ct==m hote hi return true kardega , but book toh sift 'm' no. of sudents ko allot honi chahiye , na ki more than 'm'
            }
            return ct<=m;
        }

        int findPages(vector<int>& arr, int n, int m) {
            // Write your code here.
            int maxel=INT_MIN,sum=0;
            if(m>n)return -1;
            for(int i=0;i<n;i++){
                maxel=max(maxel,arr[i]);
                sum+=arr[i];
            }
            // cout<<"maxel="<<maxel<<" sum="<<sum<<endl;
            int l=maxel,r=sum,mid,ans=INT_MAX;
            while(l<=r){
                mid=l+((r-l)/2);
                if(possible(arr,mid,m,n)){
                    ans=min(ans,mid);
                    r=mid-1;}
                else l=mid+1;
            }
            return ans;
        }