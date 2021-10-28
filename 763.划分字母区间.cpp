/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode-cn.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.34%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    83.4K
 * Total Submissions: 109.2K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：S = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S的长度在[1, 500]之间。
 * S只包含小写字母 'a' 到 'z' 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();
        int last[26] = {0};
        for (int i = 0; i < len; i++)
        {
            last[s[i] - 'a'] = i;
        }
        vector<int> res;
        int end = 0;
        int start = 0;
        for (int i = 0; i < len; i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                res.push_back(end + 1 - start);
                start = end + 1;
            }
            
        }
        return res;
    }
};
// @lc code=end

