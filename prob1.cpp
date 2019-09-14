#include <iostream>
#include <vector>

/*
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
 */

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        cout << "hello world" << endl;
        int i, j, break_flag;
        i = j = break_flag = 0;

        for (i =0; i < nums.size(); i++) {
//            cout << nums[i] << " ";
            for (j = i+1; j < nums.size(); j++ ) {
                if (nums[i] + nums[j] == target) {
                    break_flag = 1;
                    break;
                }
            }
            if (break_flag == 1)
                break;
        }
//        cout << "first index: " << i << endl;
//        cout << "second index: " << j << endl;
        result.push_back(i);
        result.push_back(j);
        return(result);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution *sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result;
    result = sol->twoSum(nums, target);
    for (int i =0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}