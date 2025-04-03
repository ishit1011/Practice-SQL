class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> lrMaxValArr(n),rlMaxValArr(n);
        for(int i=1; i<nums.size(); i++){
            lrMaxValArr[i] = max(lrMaxValArr[i-1],nums[i-1]);
            rlMaxValArr[n-1-i] = max(rlMaxValArr[n-i],nums[n-i]);
        }
        long long ans = 0;
        for(int j=1; j<n-1; j++){
            ans = max(ans,(long long)(lrMaxValArr[j]-nums[j]) * rlMaxValArr[j]);
        }
        
        return ans;
    }
};