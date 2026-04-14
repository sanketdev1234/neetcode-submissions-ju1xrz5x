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
        
        sort(intervals.begin(),intervals.end(),  [](Interval &a, Interval &b) {
                 return a.start < b.start;
             });
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int maxPlatforms = 0;
        int n=intervals.size();
        for(int i = 0; i < n; i++) {
            int at = intervals[i].start;
            int dt = intervals[i].end;
            
            
            if(!pq.empty() && at >= pq.top()) {
                pq.pop();
            }
            
            pq.push(dt);
            maxPlatforms = max(maxPlatforms, (int)pq.size());
        }
        
        return maxPlatforms;
    }
};
