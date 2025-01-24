Prob Link: "https://www.geeksforgeeks.org/problems/square-root/0"

by binary search on answers:-

CODE:-
    int floorSqrt(int n) {
        // Your code goes here
        int l=0,r=n,mid;
        while(l<=r){
            mid=r+((l-r)/2);
            if(mid*mid==n)return mid;
            else if(mid*mid>n){r=mid-1;}
            else {l=mid+1;}
        }
    return r;
        
    }