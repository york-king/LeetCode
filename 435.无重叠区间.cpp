/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int num = intervals.size();
        if (num <= 1)
        {
            return 0;
        }
        
        //lambda表达式 以区间的较大值从小到大 排序
        sort(intervals.begin(), intervals.end(), [] (vector<int> a, vector<int> b) { return a[1] < b[1]; } );

        //前一个区间的最大值
        int pre = intervals[0][1];
        int res = 0;
        for (int i = 1; i < num; i++)
        {
            //前一个区间最大值与现在区间有重合 则加1
            if (pre > intervals[i][0])
            {
                res++;
                continue;
            }
            
            pre = intervals[i][1];
        }
        
        return res;
    }
};
// @lc code=end

