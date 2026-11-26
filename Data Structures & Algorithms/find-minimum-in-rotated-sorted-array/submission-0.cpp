class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(low<=mid){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return low;
    }
};
