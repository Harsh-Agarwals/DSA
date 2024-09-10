class Solution {
public:
    bool check(vector<int>& nums) {
        int n=0;
        while(nums[0]>=nums[nums.size()-1]) {
            int temp = nums[nums.size()-1];
            int i;
            for(i=nums.size()-1;i>=1;i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
            n++;
            if(n>nums.size()-1) {
                break;
            }
        }
        for(int j=0;j<nums.size()-1;j++) {
            if(nums[j]>nums[j+1]) {
                return false;
            } else {
                continue;
            }
        }
        return true;
    }
};