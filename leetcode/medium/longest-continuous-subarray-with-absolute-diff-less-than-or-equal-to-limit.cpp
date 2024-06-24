#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      int tempDiff, ans = 1, j = 1;
      int minInSeq, maxInSeq;
      map<int, int> dataMap;
      int temp;

      for (int i = 0; i < nums.size(); i++) {
        // can't get better now, so exit
        if (ans >= (nums.size() - i)) {
          break;
        }
        // add to map if not present or more left-side value present
        if (dataMap.find(nums[i]) != dataMap.end()) {
          temp = dataMap[nums[i]];
          if (temp < i) {
            dataMap[nums[i]] = i;
          }
        } else {
          dataMap[nums[i]] = i;
        }

        for (; j < nums.size(); j++) {
          minInSeq = dataMap.begin()->first;
          maxInSeq = prev(dataMap.end())->first;
          // check if nums[j] can't work, then break
          tempDiff = max(abs(nums[j] - minInSeq), abs(maxInSeq - nums[j]));
          // save ans and clean up stuff
          if (tempDiff > limit) {
            ans = max(j - i, ans);
            // printf("%d %d..%d %d..%d\n", j - i, nums[i], nums[j], i, j);
            if (dataMap.find(nums[i]) != dataMap.end()) {
              temp = dataMap[nums[i]];
              if (temp == i) {
                // delete 'i' item if it is right-most for that value
                dataMap.erase(nums[i]);
              }
            }
            break;
          }
          if (dataMap.find(nums[j]) != dataMap.end()) {
            temp = dataMap[nums[j]];
            if (temp < j) {
              dataMap[nums[j]] = j;
            }
          } else {
            dataMap[nums[j]] = j;
          }
        }
        if (j == nums.size()) {
          ans = max(j - i, ans);
          // can't get better than this as we reached till end now, so future solutions will be worse
          break;
        }
      }

      return ans;
    }
};

int main() {
  Solution sol;
  // vector<int> nums = {8,2,4,7};
  vector<int> nums = {7,40,10,10,40,39,96,21,54,73,33,17,2,72,5,76,28,73,59,22,100,91,80,66,5,49,26,45,13,27,74,87,56,76,25,64,14,86,50,38,65,64,3,42,79,52,37,3,21,26,42,73,18,44,55,28,35,87};
  int ret = sol.longestSubarray(nums, 63);
	printf("hey %d\n", ret);
	return 0;
}

// [10,1,2,4,7,2]
// 5
// Ans - 4

// [7,40,10,10,40,39,96,21,54,73,33,17,2,72,5,76,28,73,59,22,100,91,80,66,5,49,26,45,13,27,74,87,56,76,25,64,14,86,50,38,65,64,3,42,79,52,37,3,21,26,42,73,18,44,55,28,35,87]
