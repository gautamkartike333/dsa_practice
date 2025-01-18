Prob Link:"https://leetcode.com/problems/majority-element-ii/"

Brute: counting all elements

Better Approach: using hashing 

OPTIMAL SOLN:-
Extended Morre's voting algorithm

STEPS:-
    STEP-1: It has 4 var=>ct1,ct2,el1,el2
    STEP-2: If curr el !=el2 and ct1==0 then put el1=cur el and set ct1 for counting of el1 and vice versa with el2
    Step-3: increase counters accordingly
    Step-4: Rest all cases decrease both counters
    Step-4: At last dont forgot to check whether el1 and el2 are majority el or not by again counting them.
            Note:- We are checking if (ans.size()==2)break; -->ye kyu kar rahe hai iske baare me socho socho
    

vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ct1=0,ct2=0,el1,el2;
        for(int i=0;i<n;i++){
            if(ct1==0 && nums[i]!=el2){el1=nums[i];ct1=1;}
            else if(ct2==0 && nums[i]!=el1){el2=nums[i];ct2=1;}
            else if(nums[i]==el1)ct1++;
            else if(nums[i]==el2)ct2++;
            else{ct1--;ct2--;}
        }
        ct1=0;ct2=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==el1)ct1++;
            else if(nums[i]==el2)ct2++;
        }
        int ct=(n/3)+1;
        if(ct1 >= ct)ans.push_back(el1);
        if(ct2 >= ct)ans.push_back(el2);
        return ans;
      }