class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = m;
        while(low<=high){
            int i = low + (high-low)/2;
            int j = (m+n+1)/2 - i;
            int left1 = (i==0) ? INT_MIN : nums1[i-1];
            int right1 = (i==m) ? INT_MAX : nums1[i];
            int left2 = (j==0) ? INT_MIN : nums2[j-1];
            int right2 = (j==n) ? INT_MAX : nums2[j];
            if(left1 <= right2 && left2 <= right1) {

                // Odd total elements
                if((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Even total elements
                return (max(left1, left2) + 
                        (double)min(right1, right2)) / 2.0;
            }

            // Too many elements taken from nums1
            else if(left1 > right2) {
                high = i - 1;
            }

            // Too few elements taken from nums1
            else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};
