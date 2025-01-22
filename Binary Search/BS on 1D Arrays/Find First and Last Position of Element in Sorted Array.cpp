Prob Link:"https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/"

Code:-
    class Solution {
public:
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == x){ans = mid;high=mid-1;}
        else if (arr[mid] > x) {
            
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int upperBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if(arr[mid] == x){ans = mid;low=mid+1;}
        else if (arr[mid] > x) {
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


vector<int> searchRange(vector<int>& nums, int target) {

int n=nums.size();
	int f = lowerBound(nums, n, target);
	int c = upperBound(nums, n, target);

vector<int>temp={f,c};
return temp;
    }
};

One more optimal approach:-
    Step-1: Pehle first occurence nikalo uss given number ki by binary search then last occurence
    Step-2: return last-first+1
    First occurence kaise niklegi? ->jab arr[mid]==target ho tab high ko peeche le aao , but dont forgot to save the index mid first baaki sab same 
    First occurence kaise niklegi? ->jab arr[mid]==target ho tab low ko aage badha do , kyuki aage hi toh milega target if arr[mid] target ke barabar hai toh..

//agar length puche toh 
    return (last -first +1)