class Solution {
public:
    int search(vector<int> &v, int target) {
        int L=0,R=v.size()-1;
        while(L<=R){
            int mid=L+(R-L)/2;
            if(v[mid]==target){
                return mid;
            }
            if(v[mid]>v[L] or mid==L){
                if(target<v[mid] and target>=v[L]){
                    R=mid-1;
                }
                else{
                    L=mid+1;
                }
            }
            else{
                if(target>v[mid] and target<=v[R]){
                    L=mid+1;
                }
                else{
                    R=mid-1;
                }
            }
        }
        return -1;
    }
};

