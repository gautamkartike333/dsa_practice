Ques Link : "https://leetcode.com/problems/largest-rectangle-in-histogram/description/"

Follow-up Ques :-try to do ques in O(2N) only not in O(5N) or more -> dont pre-compute nse and pse-> saath ke saath nikalo.

Hint :- 
1 - har ek element ka nse and pse nikal lo 





















Hint - 2 : 
-> ab agar aap o(2n) me karna chahate ho toh , sath ke sath nse and pse nikalte chalna hoga , pse toh bahut 
easy hai sath ke sath nikalna , jese normal pre-compute karte the ese hi same 
-> toh bas ab nse ke baare me sochna hai , sath ke sath kese nikalein?





























CODE:-
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<int>st;
            int area=0;
            for(int i=0;i<n;i++){
                while(!st.empty() && (heights[st.top()]>heights[i]) ){
                    int curri=st.top();st.pop();
                    int nse=i;int pse=st.empty()?-1:st.top();
                    area=max(area , (heights[curri]*(nse-pse-1)) );
                }
                st.push(i);
            }
    
            while(!st.empty()){
                int curri=st.top();st.pop();
                int nse=n;int pse=st.empty()?-1:st.top();
                area=max(area , (heights[curri]*(nse-pse-1)) );
            }
            return area;
        }
    };