Prob Link:"https://leetcode.com/problems/merge-sorted-array/"

Approach-1
    T.C.= 2*O(M+N)
    S.C.= O(M+N)

    Steps:
        Step-1: putting l pointer at nums1 0th index, and r pointer at nums2 0th index
        Step-2: if(l pointer's el > r pointer's el)swap, else move forward
                IF some el are left then , push them to ans array/vector

        you will get desired result

    CODE:
            void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                int i=0,j=0;
                vector<int>temp;
                while(i<m && j<n){
                    if(nums1[i]>nums2[j]){temp.push_back(nums2[j++]);}
                    else if(nums1[i]<nums2[j]){temp.push_back(nums1[i++]);}
                    else{temp.push_back(nums1[i++]);}
                }
                while(i<m){temp.push_back(nums1[i++]);}
                while(j<n){temp.push_back(nums2[j++]);}
            nums1=temp;
            }

Approach-2: put l pointer at last index of arr1 , and r pointer at starting index of arr2

    T.C.: O(min(n, m)) + O(n*logn) + O(m*logm)
    S.C.:O(1)

    Step-1: If l pointers el > r pointer then swap else l--;r++
            aage ka khud soch le 

Approach-3: Ye approach shell sort se derived hai
            gap = ceil(m+n/2)
            Step-1: put l at 0 and r at l+gap if(el at l>r)swap            
            Step-2: gap=gap/2
                    Repeat until gap==1 implemented && gap>0

            CODE:
            void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
                if (arr1[ind1] > arr2[ind2]) {
                    swap(arr1[ind1], arr2[ind2]);
                }
            }

            void merge(long long arr1[], long long arr2[], int n, int m) {
                // len of the imaginary single array:
                int len = n + m;

                // Initial gap:
                int gap = (len / 2) + (len % 2);

                while (gap > 0) {
                    // Place 2 pointers:
                    int left = 0;
                    int right = left + gap;
                    while (right < len) {
                        // case 1: left in arr1[]
                        //and right in arr2[]:
                        if (left < n && right >= n) {
                            swapIfGreater(arr1, arr2, left, right - n);
                        }
                        // case 2: both pointers in arr2[]:
                        else if (left >= n) {
                            swapIfGreater(arr2, arr2, left - n, right - n);
                        }
                        // case 3: both pointers in arr1[]:
                        else {
                            swapIfGreater(arr1, arr1, left, right);
                        }
                        left++, right++;
                    }
                    // break if iteration gap=1 is completed:
                    if (gap == 1) break;

                    // Otherwise, calculate new gap:
                    gap = (gap / 2) + (gap % 2);
                }
            }