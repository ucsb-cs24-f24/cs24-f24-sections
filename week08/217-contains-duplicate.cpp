#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> vals;
        for(int i = 0; i < nums.size(); i++){
            if(vals.find(nums[i]) != vals.end()){
                return true;
            }
            vals.insert(nums[i]);
        }
        return false;
    }
};