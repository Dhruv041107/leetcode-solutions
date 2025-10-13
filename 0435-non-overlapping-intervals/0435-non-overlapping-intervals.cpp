class Solution {
public:
    bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int cnt=1;
        int lastTime=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=lastTime){
                cnt++;
                lastTime=intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};