/*
 * LeetCode 1. 两数之和（简单）
 * https://leetcode.cn/problems/two-sum/
 *
 * 题目：
 * 给定一个整数数组 nums 和一个整数目标值 target，找出数组中
 * 和为 target 的两个整数，并返回它们的数组下标。
 * 每种输入只会对应一个答案，不能使用两次相同的元素。
 * 可以按任意顺序返回答案。
 *
 * 示例 1：
 * 输入：nums = [2, 7, 11, 15], target = 9
 * 输出：[0, 1]
 * 解释：nums[0] + nums[1] == 9。
 *
 * 示例 2：
 * 输入：nums = [3, 2, 4], target = 6
 * 输出：[1, 2]
 *
 * 示例 3：
 * 输入：nums = [3, 3], target = 6
 * 输出：[0, 1]
 *
 * 约束：
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 只会存在一个有效答案。
 *
 * 进阶：能否实现时间复杂度小于 O(n^2) 的算法？
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 保存已经遍历过的元素：数值 -> 下标。
        unordered_map<int, int> seen;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int needed = target - nums[i];
            auto it = seen.find(needed);

            if (it != seen.end()) {
                return {it->second, i};
            }

            // 先查找再插入，避免使用两次当前元素。
            seen[nums[i]] = i;
        }

        return {}; // 题目保证存在答案，因此不会执行到这里。
    }
};
