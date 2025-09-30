class Solution {
public:
    bool itcan(vector<int> arr,int m,int k,int D){
        int counter=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=D){
                counter++;
            }
            if(counter ==k){
                m--;
                counter=0;
                if(m==0){
                    break;
                }
            }
            if(arr[i]>D){
                counter=0;
            }
        }
        return m==0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int size=(long long int )m*(long long int )k;
        if(bloomDay.size()<size)   return -1; 

        int start= *min_element(bloomDay.begin(),bloomDay.end());
        int end= *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int day=mid;
            if(itcan(bloomDay,m,k,day)){
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};