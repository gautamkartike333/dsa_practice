Prob Link:-"https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1"

CODE:-
    int nthRoot(int n, int m) {
        // Code here.
        int l=0,r=m,mid;
        while(l<=r){
            mid=r+((l-r)/2);
            double k=pow((double)mid,(double)n);
            
            if(k == (double)m)return mid;
            else if(k > (double)m)r=mid-1;
            else l=mid+1;
        }
    return -1;
        
    }

Striver's Code :-
        //return 1, if == m:
        //return 0, if < m:
        //return 2, if > m:
        int func(int mid, int n, int m) {
            long long ans = 1;
            for (int i = 1; i <= n; i++) {
                ans = ans * mid;
                if (ans > m) return 2;
            }
            if (ans == m) return 1;
            return 0;
        }

        int NthRoot(int n, int m) {
            //Use Binary search on the answer space:
            int low = 1, high = m;
            while (low <= high) {
                int mid = (low + high) / 2;
                int midN = func(mid, n, m);
                if (midN == 1) {
                    return mid;
                }
                else if (midN == 0) low = mid + 1;
                else high = mid - 1;
            }
            return -1;
        }
