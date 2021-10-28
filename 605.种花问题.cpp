/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = flowerbed.size();

        //需种的花小于等于0
        if (n <= 0) return true;
        
        //可种植的花
        int res = 0;

        int pre = 0;
        int las = 0;
        for (int i = 0; i < num; i++)
        {
            //如果下标为最后一个值
            if (i == num - 1)
            {
                if (flowerbed[i] == 0 && las == 0) res++;
                break;
            }

            pre = flowerbed[i];
            las = flowerbed[i + 1];

            //若前一个(pre)为1，则下一个(las)必然为0，跳过1个
            if (pre == 1)
            {
                i++;
                continue;
            }
            //若后一个(las)为1，则在下一个必然为0，需要跳过2个
            if (las == 1)
            {
                i += 2;
                continue;
            }
            

            //相邻的两个为0，设置前一个为1，后一个为0
            res++;
            //跳过一个
            i++;
        }
        
        return res >= n;
    }
};
// @lc code=end

