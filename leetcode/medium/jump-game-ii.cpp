#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jumpOtherSolution(vector<int>& nums) {
      int n = nums.size(), jumpDistance, tempMin;
      int stepsToReachFrom[n];
      stepsToReachFrom[n - 1] = 0;
      for (int i = n - 2; i >= 0; i--) {
        jumpDistance = nums[i];
        tempMin = 1000000;
        for (int j = i+1; j <= min(i+jumpDistance, n-1); j++) {
          tempMin = min(tempMin, stepsToReachFrom[j]);
        }
        stepsToReachFrom[i] = tempMin + 1;
      }
      return stepsToReachFrom[0];
    }

    int jump(vector<int>& nums) {
      int n = nums.size();
      int minPossible = -1, maxPossible = -1, newMaxPossible = -1;
      int ans = 0;
      if (n == 1) return 0;
      while (true) {
        if (minPossible == -1) {
          // init state
          minPossible = 1;
          maxPossible = nums[0];
          ans++;
        } else {
          newMaxPossible = -1;
          for (int i = minPossible; i <= maxPossible; i++) {
            newMaxPossible = max(nums[i] + i, newMaxPossible);
          }
          minPossible = maxPossible + 1;
          maxPossible = newMaxPossible;
          ans++;
        }
        if (maxPossible >= n - 1) {
          break;
        }
      }
      return ans;
    }
};


int main() {
  Solution sol;
  vector<int> nums = {2,3,1,1,4};
  int ret = sol.jump(nums);
	printf("hey %d\n", ret);
	return 0;
}
