/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.61%)
 * Likes:    1147
 * Dislikes: 0
 * Total Accepted:    224.9K
 * Total Submissions: 401.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 首先使用哈希表存储每个数字对应的所有可能的字母，然后进行回溯操作。
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.empty()){
            return combinations;
        }
        unordered_map<char, string> phoneMap{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string combination;
        backtrace(combinations, phongMap, digits, 0, combination);
        return combinations;
    }
    void backtrace(vector<string>& combinations, const unordered_map<char, string>& phoneMap,
                    const string& digits, int index, string& combination)
    {
        if(index == digits.length()){
            combinations.push_back(combination);
        } else{
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for(auto letter : letters){
                combination.push_back(letter);
                backtrace(combinations, phoneMap, digits, index + 1,combination);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end
/*
时间复杂度：O(3^m * 4^n)O，其中 m 是输入中对应 3 个字母的数字个数（包括数字 2、3、4、5、6、8），n 是输入中对应 4 个字母的数字个数（包括数字 7、9），m+n 是输入数字的总个数。当输入包含 m 个对应 3 个字母的数字和 n 个对应 4 个字母的数字时，不同的字母组合一共有 3^m*4^n种，需要遍历每一种字母组合。

空间复杂度：O(m+n)，其中 m 是输入中对应 3个字母的数字个数，n 是输入中对应 4 个字母的数字个数，m+n 是输入数字的总个数。除了返回值以外，空间复杂度主要取决于哈希表以及回溯过程中的递归调用层数，哈希表的大小与输入无关，可以看成常数，递归调用层数最大为 m+n。
*/
