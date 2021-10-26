// main.cpp 主程序入口
#include <string>
#include <iostream>
#include <vector>

using namespace std;

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
            if (i == num - 1 && flowerbed[i] == 0 && las == 0) res++;

            pre = flowerbed[i];
            las = flowerbed[i + 1];

            //若相邻的有个为1，则下一个必然为0，跳过
            if (pre == 1 || las == 1)
            {
                i++;
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



int main()
{
    cout << "main start" << endl;

    vector<int> vec = {1,0,0,0,1};
    Solution s;
    bool i = s.canPlaceFlowers(vec, 2);
    cout << i << endl;
    return 0;
}