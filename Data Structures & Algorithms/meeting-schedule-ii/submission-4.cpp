/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start;
        vector<int>end;
        int n=intervals.size();
        if(n==0)return 0;
        for(int i=0;i<n;i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        int count=1;
        int maxcount=1;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=1;
        int j=0;
        while(i < n && j < n){
            if(start[i] < end[j]){
                i++;
                count++;
            }
            else {
                j++;
                count--;
            }
            maxcount=max(maxcount,count);
        }
      return maxcount;
    }
};
