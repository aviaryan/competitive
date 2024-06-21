#include <string>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
      int n = customers.size();
      vector<int> lossSums(n);
      lossSums[0] = 0;
      for (int i = 0; i < n; i++) {
        if (grumpy[i] == 1) {
          lossSums[i] = customers[i];
        }
        if (i > 0) {
          lossSums[i] += lossSums[i - 1];
        }
      }
      // find where to be not grumpy by seeing where loss is max
      int pointToUseTechnique = 0;
      int maxGainsToBeMade = 0;
      for (int i = 0; i < n; i++) {
        int gainAtThisPoint = lossSums[min(i + minutes - 1, n - 1)] - (i == 0 ? 0 : lossSums[i - 1]);
        if (gainAtThisPoint > maxGainsToBeMade) {
          pointToUseTechnique = i;
          maxGainsToBeMade = gainAtThisPoint;
        }
      }
      // find final satisfied customers
      int satis = 0;
      for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0) {
          satis += customers[i];
        } else if (i >= pointToUseTechnique && (i <= (pointToUseTechnique + minutes - 1))) {
          satis += customers[i];
        }
      }
      return satis;
    }
};

int main() {
  Solution sol;
  vector<int> customers = {1,0,1,2,1,1,7,5};
  vector<int> grumpy = {0,1,0,1,0,1,0,1};
  int ret = sol.maxSatisfied(customers, grumpy, 3);
	printf("hey %d\n", ret);
	return 0;
}
