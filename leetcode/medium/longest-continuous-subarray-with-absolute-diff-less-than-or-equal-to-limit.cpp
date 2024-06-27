#include <bits/stdc++.h>
using namespace std;

class Solution2 {
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

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      int tempDiff, ans = 1, j = 1;
      int minInSeq, maxInSeq, prevEqualMinPos, prevEqualMaxPos, curItem;
      stack<pair<int,int>> minStack;
      stack<pair<int,int>> maxStack;

      for (int i = 0; i < nums.size(); i++) {
        curItem = nums[i];
        // if (minStack.empty() || (minStack.top().first > nums[i])) {
        //   minStack.push(make_pair(nums[i], i));
        // }
        // if (maxStack.empty() || (maxStack.top().first < nums[i])) {
        //   maxStack.push(make_pair(nums[i], i));
        // }
        if (i >= j) j = i + 1;

        for (; j < nums.size(); j++) {
          if (minStack.empty()) {
            minStack.push(make_pair(nums[j], j));
          }
          if (maxStack.empty()) {
            maxStack.push(make_pair(nums[j], j));
          }
          minInSeq = minStack.top().first;
          maxInSeq = maxStack.top().first;
          // check if nums[j] can't work, then break
          tempDiff = max(
            max(abs(minInSeq - maxInSeq), abs(curItem - nums[j])),
            max(abs(nums[j] - minInSeq), abs(maxInSeq - nums[j]))
          );
          // save ans and clean up stack
          if (tempDiff > limit) {
            printf("%d %d..%d %d..%d\n", j - i, nums[i], nums[j], i, j);
            ans = max(j - i, ans);
            // clean up stack
            while (true) {
              if (!minStack.empty() && (minStack.top().second <= (i+1))) {
                minStack.pop();
              } else if (!maxStack.empty() && (maxStack.top().second <= (i+1))) {
                maxStack.pop();
              } else {
                break;
              }
            }
            break;
          }
          if (i == 25) {
            printf("25: %d %d %d\n", nums[j], minInSeq, maxInSeq);
          }
          // if nums[j] works, update values
          if (nums[j] < minInSeq) {
            minStack.push(make_pair(nums[j], j));
          } else if (nums[j] == minInSeq) {
            prevEqualMinPos = minStack.top().second;
            minStack.top().second = j;
            minStack.push(make_pair(nums[j], prevEqualMinPos));
          }
          if (nums[j] > maxInSeq) {
            maxStack.push(make_pair(nums[j], j));
          } else if (nums[j] == maxInSeq) {
            prevEqualMaxPos = maxStack.top().second;
            maxStack.top().second = j;
            maxStack.push(make_pair(nums[j], prevEqualMaxPos));
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
