class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> sol;
      map<int, int> minusMap;
      for (int i = 0; i < nums.size(); i++) {
        minusMap[target - nums[i]] = i;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (minusMap.find(nums[i]) != minusMap.end()) {
          if (minusMap[nums[i]] == i) {
            continue;
          }
          sol.push_back(i);
          sol.push_back(minusMap[nums[i]]);
          return sol;
        }
      }
      return sol;
    }
};