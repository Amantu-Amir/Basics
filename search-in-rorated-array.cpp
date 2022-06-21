class Solution {
public:
    int getBreakPoint(vector<int>& nums){
        int L=0, R=nums.size()-1, mid=0;
        while(L<=R){
            mid=(L+R)/2;
            if(nums[0]<=nums[mid]){
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        return L;
    }
    
    int search(int L, int R, vector<int>& v, int target){
        while(L<=R){
            int mid=L+(R-L)/2;
            if(v[mid]==target){
                return mid;
            }
            if(v[mid]>target){
                R=mid-1;
            }
            else{
                L=mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int idx=getBreakPoint(nums);
        int left=search(0, idx-1, nums, target);
        int right=search(idx, nums.size()-1, nums, target);
        if(left==-1 and right==-1){
            return -1;
        }
        if(left!=-1){
            return left;
        }
        return right;
    }
};



