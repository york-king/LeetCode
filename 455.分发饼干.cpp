/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        unsigned int child_num = g.size();
        unsigned int cracker_num = s.size();

        //从小到大排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;
        int pos = 0;
        for (size_t i = 0; i < child_num; i++)
        {
            for (size_t j = pos; j < cracker_num; j++)
            {
                if (s[j] >= g[i])
                {
                    res++;
                    pos = j+1;
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

