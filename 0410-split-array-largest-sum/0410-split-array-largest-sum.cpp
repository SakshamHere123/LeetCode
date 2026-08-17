class Solution {
public:

    int cntpart(vector<int>& nums, int& maxSum){
        int partions = 1;
        int subsum = 0;

        for(int num : nums){
            if(subsum + num<=maxSum){
                subsum += num;
            }else{
                partions++;
                subsum = num;
            }
        }
        return partions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low + (high - low)/2;
            int partions = cntpart(nums,mid);
            if(partions>k){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return low;
    }
};