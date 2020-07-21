//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值
// 至多为 k。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1], k = 3
//输出: true 
//
// 示例 2: 
//
// 输入: nums = [1,0,1,1], k = 1
//输出: true 
//
// 示例 3: 
//
// 输入: nums = [1,2,3,1,2,3], k = 2
//输出: false 
// Related Topics 数组 哈希表 
// 👍 182 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> st; // 设一个set为窗口
        for (int i = 0; i < nums.size(); ++i) {
            if (!st.insert(nums[i]).second) return true; // 插入失败说明重复 否则完成插入
            if (st.size() == k + 1) st.erase(nums[i-k]); // 保证窗口长度<=k+1
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{1, 2, 3, 1};
    vector<int> data1{1, 0, 1, 1};
    vector<int> data2{1, 2, 3, 1, 2, 3};
    cout << s.containsNearbyDuplicate(data, 3) << endl;
    //输出: true
    cout << s.containsNearbyDuplicate(data1, 1) << endl;
    //输出: true
    cout << s.containsNearbyDuplicate(data2, 2) << endl;
    //输出: false
}