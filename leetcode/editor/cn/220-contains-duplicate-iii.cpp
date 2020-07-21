//在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的
//绝对值也小于等于 ķ 。 
//
// 如果存在则返回 true，不存在返回 false。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1], k = 3, t = 0
//输出: true 
//
// 示例 2: 
//
// 输入: nums = [1,0,1,1], k = 1, t = 2
//输出: true 
//
// 示例 3: 
//
// 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
//输出: false 
// Related Topics 排序 Ordered Map 
// 👍 196 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (t < 0) return false;
        //t+1可能会溢出，所以要+ 1LL
        long long mod = t + 1LL;
        unordered_map<long long, long long> buck;
        for (int i = 0; i < nums.size(); i++) {
            long long nth = nums[i] / mod;
            //可能nums[i]为负数，比如-4 / 5 以及 -4 / 5都等于0，所以负数要向下移动一位
            if (nums[i] < 0) nth--;
            //这里要用find 不能直接[],因为可能本身存储的数字就为0
            if (buck.find(nth) != buck.end())
                return true;
            else if (buck.find(nth - 1) != buck.end() && abs(nums[i] - buck[nth - 1]) <= t)
                return true;
            else if (buck.find(nth + 1) != buck.end() && abs(nums[i] - buck[nth + 1]) <= t)
                return true;

            buck[nth] = nums[i];
            if (i >= k) {
                buck.erase(nums[i - k] / mod);
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
//    vector<int> data1{1, 0, 1, 1};
//    cout << s.containsNearbyAlmostDuplicate(data1, 1, 2) << endl;
//
//    vector<int> data2{1, 2, 3, 1};
//    cout << s.containsNearbyAlmostDuplicate(data2, 3, 0) << endl;
//
//    vector<int> data{1, 5, 9, 1, 5, 9};
//    cout << s.containsNearbyAlmostDuplicate(data, 2, 3) << endl;

    vector<int> data3{1, 3, 5, 7, 9};
    cout << s.containsNearbyAlmostDuplicate(data3, 4, 1) << endl;
}