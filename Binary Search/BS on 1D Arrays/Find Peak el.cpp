Prob Link:-"https://leetcode.com/problems/find-peak-element/"

Hint:- see multiple peaks can be their , so understand this by a graph of 'M' shape make 'M' shaped graph in NOTEBOOK , now see nums[mid] can be at any of these lines , now reduce the halves acc to conditions ki kis line par aaya hai , or ab peak chahiye toh kise half ko eliminate karenge -> kaise karenge uske liye apna dimaag lagao ab .




























CODE:-
    int findPeakElement(vector<int> &arr) {
        int n = arr.size(); //Size of array.

        // Edge cases:
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            //If arr[mid] is the peak:
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            // If we are in the left:
            if (arr[mid] > arr[mid - 1]) low = mid + 1;

            // If we are in the right:
            // Or, arr[mid] is a common point:
            else high = mid - 1;
        }
        // Dummy return statement
        return -1;
    }
