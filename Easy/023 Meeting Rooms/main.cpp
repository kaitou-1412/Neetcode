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
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(), intervals.end());
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i-1]->end > intervals[i]->start) {
                return false;
            }
        }
        return true;
    }