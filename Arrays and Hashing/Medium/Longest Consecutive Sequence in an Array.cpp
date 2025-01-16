// Prob Link="https://www.naukri.com/code360/problems/longest-successive-elements_6811740?leftPanelTabValue=SUBMISSION"

Better Solution:-
  Steps:-
        For every element, we will check if this can be a part of the current sequence like the following:
      =>  If arr[i]-1 == lastSmaller: The last element in our sequence is labeled as 'lastSmaller' and the current element 'arr[i]' is exactly 'lastSmaller'+1. It indicates that 'arr[i]' is the next consecutive element. To incorporate it into the sequence, we update 'lastSmaller' with the value of 'arr[i]' and increment the length of the current sequence, denoted as 'cnt', by 1.
      
      =>  If arr[i] == lastSmaller: If the current element, arr[i], matches the last element of the sequence (represented by 'lastSmaller'), we can skip it since we have already included it before.
      
      =>  Otherwise, if lastSmaller != arr[i]: On satisfying this condition, we can conclude that the current element, arr[i] > lastSmaller+1. It indicates that arr[i] cannot be a part of the current sequence. So, we will start a new sequence from arr[i] by updating ‘lastSmaller’ with the value of arr[i]. And we will set the length of the current sequence(cnt) to 1.
      
Every time, inside the loop, we will compare ‘cnt’ and ‘longest’ and update ‘longest’ with the maximum value. longest = max(longest, cnt)

Finally, once the iteration is complete, we will have the answer stored in the variable ‘longest’.

CODE:-
        int longestSuccessiveElements(vector<int>&a) {
        int n = a.size();
        if (n == 0) return 0;

        //sort the array:
        sort(a.begin(), a.end());
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;

        //find longest sequence:
        for (int i = 0; i < n; i++) {
            if (a[i] - 1 == lastSmaller) {
                //a[i] is the next element of the
                //current sequence.
                cnt += 1;
                lastSmaller = a[i];
            }
            else if (a[i] != lastSmaller) {
                cnt = 1;
                lastSmaller = a[i];
            }
            longest = max(longest, cnt);
        }
        return longest;

    }

OPTIMAL SOLUTION:-
    using set 
        Step-1:-put all el in unordered_set
        Step-2:-while traversing set , check if us el se choti value i.e.(el-1) set me present h toh curr el aapke answer wale seq. ka first el nahi ho sakta =>more forward
        Step-3:-agar (el-1) set me present nahi h toh ye first el ho sakta h , ab check karo ki curr el ke aage kitne el present h seq. ke .. set.find(cur_el_value +1) aur len++ and update karte jao maxlen ko

    CODE:-
        int longestSuccessiveElements(vector<int>&arr) {
        int n=arr.size();
        int maxlen=1,len=0,lastnum=INT_MIN;
        unordered_set<int>sett;
        for(int i=0;i<n;i++)sett.insert(arr[i]);
        for(auto m:sett){
            if(sett.find(m-1) == sett.end()){
                len=1;
                int x=m+1;
                while (sett.find(x) != sett.end()) {
                len++;
                x = x + 1;
                }
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }