Prob Link:"https://leetcode.com/problems/kth-missing-positive-number/description/"


Hint-1:- find the nearest neighbours of missing el. which are present in array
















Hint-2:- Agar array me koi no. missing nahi hota tab kya scene hota analysis karo .









CODE:-

 int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,r=n-1,mid;
        while(l <= r){
            mid = l + (r-l) / 2;
            if(arr[mid]-(mid+1)<k) l=mid+1;
            else r=mid-1;
        }
        return k+r+1;
    }