class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int low = 0;
       int n = nums.size();
       int high = n-1;
       unordered_map<int,int>mpp;
       for(int i=0;i<n;i++){
        int curr = nums[i];
        int rem = target-curr;
        if(mpp.find(rem)!=mpp.end()){
            return {i,mpp[rem]};
        }
        mpp[curr]=i;
       }
       
    
       return {low,high};
    }
};