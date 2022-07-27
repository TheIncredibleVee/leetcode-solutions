class Solution {
public:
//     int uprBound(vector<int> &arr, int n, int key){
//         if(key > arr[n-1]){
//             return n;
//         }
//         if(key < arr[0]){
//             return 0;
//         }
//         int low = 0;
//         int high = n - 1;
//         while(low <= high){
//             int mid = (low + high) / 2;
//             if(arr[mid] <= key){
//                 low = mid + 1;
//             }else{
//                 high = mid - 1;
//             }
//         }
//         return low;
//     }
    
//     int lrBound(vector<int> &arr, int n, int key){
//         if(key > arr[n-1]){
//             return n;
//         }
//         if(key < arr[0]){
//             return 0;
//         }
//         int low = 0;
//         int high = n - 1;
//         while(low < high){
//             int mid = (low + high) / 2;
//             if(arr[mid] < key){
//                 low = mid + 1;
//             }else{
//                 high = mid - 1;
//             }
//         }
//         return low;
//     }
    
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         if(n == 0 ){
//             return m%2==0?((double)nums2[m/2] + (double)nums2[(m/2) -1])/2.0: nums2[m/2];
//         }
//         if(m == 0 ){
//             return n%2==0?((double)nums1[n/2] + (double)nums1[(n/2) -1])/2.0: nums1[n/2];
//         }
//         int low = min(nums1[0], nums2[0]);
//         int high = max(nums1[n-1], nums2[m-1]);
//         int med = (n + m + 1) / 2;
//         while(low <= high){
//             int mid = (low + high) / 2;
//             int cnt = uprBound(nums1, n, mid) + uprBound(nums2, m, mid);
//             cout<<low<<"\t"<<high<<"\t"<<mid<<"\t"<<cnt<<endl;
//             if(cnt >= med){
//                 high = mid - 1;
//             }else{
//                 low = mid + 1;
//             }
//         }
//         cout<<low<<endl;
//         if((m + n) % 2 ==0){
//             double res = low;
//             int pota  = uprBound(nums1, n, low) ;
//             int potb = uprBound(nums2, n, low) ;
//             cout<<pota<<"\t"<<potb<<endl;
//             if (pota == n && potb == m){
//                  res = res + min(nums1[pota-1], nums2[potb-1]);
//                  res = res/ 2.0;
//             }
//             else if(pota >= n || nums1[pota] <= low){
//                 res += nums2[potb];
//                 res = res / 2.0;
//             }else if(potb >= m || nums2[potb] <= low){
//                 res += nums1[pota];
//                 res = res / 2.0;
//             }
//             else{
//                 res = res + min(nums1[pota], nums2[potb]);
//                 res = res / 2.0;
//             }
//             return res;
//         }
//         return (double)low;
//     }
    
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = n;
        int total = (n+m+1);
        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = (total/2) - mid1;
            
            int l1 = mid1 == 0 ? INT_MIN: nums1[mid1 - 1 ];
            int l2 = mid2 == 0 ? INT_MIN: nums2[mid2 - 1 ];
            int r1 = mid1 == n ? INT_MAX: nums1[mid1];
            int r2 = mid2 == m ? INT_MAX: nums2[mid2];
            // cout<<low<<"\t"<<high<<"\t"<<mid1<<"\t"<<mid2<<"\t"<<l1<<"\t"<<l2<<"\t"<<r1<<"\t"<<r2<<endl;
            if(l1 <= r2 && l2 <= r1){
                if(total % 2 == 0){
                    return max(l1, l2);
                }
                else{
                    return ((double)max(l1,l2)+(double)min(r1,r2))/2.0;
                }
            }
            if(l1 > r2){
                high = mid1 - 1;
            }else{
                low = mid1 + 1;
            }
        }
        return 0.0;
    }  
};