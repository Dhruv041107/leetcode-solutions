class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s=0;
        int n=arr.size();
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(s==e){
                return arr[s];
            }
            if(mid-1>=0 && arr[mid]!= arr[mid-1] && mid+1<n && arr[mid]!= arr[mid+1]){
                return arr[mid];
            }
            if(arr[mid]==arr[mid-1]){
                int index=mid-1;
                if(index&1){
                    e=mid-2;
                }
                else{
                    s=mid+1;
                }
            }
            else if(arr[mid]==arr[mid+1]){
                if(mid&1){
                    e=mid-1;
                }
                else{
                    s=mid+2;
                }
            }
        }
        return -1;
    }
};