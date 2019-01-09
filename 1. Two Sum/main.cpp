#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if(m.find(target-nums[i]) != m.end()) {
                return vector<int>{ m[target-nums[i]], i};
            }
            m[nums[i]] = i;
        }
    }


int main()
{
    vector<int> a{1,2,3,7,11,15};
    vector<int> aa = twoSum(a,9);
    for(auto it = aa.begin(); it != aa.end();++it)
        cout<<*it<<endl;
    return 0;
}
