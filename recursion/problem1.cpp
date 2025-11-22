#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

void getPerms(vector<string>& nums, int idx, vector<vector<string>>& ans) {
    if(idx == nums.size()){
        ans.push_back({nums});
        return;
    }

    for(int i=idx; i<nums.size(); i++) {
        swap(nums[idx], nums[i]);
        getPerms(nums, idx+1, ans);

        swap(nums[idx], nums[i]);
    }
}

vector<vector<string>>
    permute(vector<string>& nums) {
        vector<vector<string>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }

int main() {
    vector<string> nums = {"a", "b", "c"};
    vector<vector<string>> ans = permute(nums);

    for(const auto& perm : ans) {
        for(const auto& str : perm) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
