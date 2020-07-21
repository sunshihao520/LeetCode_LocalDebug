//给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。 
//
// 
//
// 示例 1: 
//
// 输入: [3,0,1]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [9,6,4,2,3,5,7,0,1]
//输出: 8
// 
//
// 
//
// 说明: 
//你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现? 
// Related Topics 位运算 数组 数学 
// 👍 285 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void swap(int & a,int&b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        nums.push_back(-1);
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 0 && nums[i] <= n && nums[nums[i] ] != nums[i]) {
                swap(nums[i], nums[nums[i] ]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i )
                return i ;
        }
        return n ;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{9,6,4,2,3,5,7,0,1};
    int ans = s.missingNumber(data);
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout << ans << endl;
}