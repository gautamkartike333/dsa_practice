Prob Link : "https://leetcode.com/problems/koko-eating-bananas/description/"



Hints :- BS on Answers -> bas itna hi hai hint -> socho socho ?



























CODE:-  
        bool poss(vector<int>& piles,int mid, int h, int n){
            long long ct=0;
            for(int i=0;i<n;i++){
                ct += ceil(((double)piles[i])/mid);
            }
            return ct<=h;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int n=piles.size();int maxel=INT_MIN;
            for(int i=0;i<n;i++)maxel=max(maxel,piles[i]);
            long long l=1,r=maxel,mid;
            
            while(l<=r){
                mid=l+((r-l)/2);
                if(poss(piles,mid,h,n))r=mid-1;
                else l=mid+1;
            }
            return l;
        }