#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> sol;
      unordered_map<char, vector<char>> charMap;
      charMap['2'] = {'a', 'b', 'c'};
      charMap['3'] = {'d', 'e', 'f'};
      charMap['4'] = {'g', 'h', 'i'};
      charMap['5'] = {'j', 'k', 'l'};
      charMap['6'] = {'m', 'n', 'o'};
      charMap['7'] = {'p', 'q', 'r', 's'};
      charMap['8'] = {'t', 'u', 'v'};
      charMap['9'] = {'w', 'x', 'y', 'z'};
      solve(charMap, sol, digits, "");
      return sol;
    }

    void solve(unordered_map<char, vector<char>> & charMap, vector<string> & sol, string remainingDigitString, string curString) {
      if (remainingDigitString.length() == 0) {
        if (curString.length() != 0) {
          sol.push_back(curString);
        }
        return;
      }
      string nextStr = remainingDigitString.substr(1, remainingDigitString.length() - 1);
      char firstChar = remainingDigitString[0];
      solve(charMap, sol, nextStr, curString + charMap[firstChar][0]);
      solve(charMap, sol, nextStr, curString + charMap[firstChar][1]);
      solve(charMap, sol, nextStr, curString + charMap[firstChar][2]);
      if (charMap[firstChar].size() == 4) {
        solve(charMap, sol, nextStr, curString + charMap[firstChar][3]);
      }
    }
};

int main() {
  Solution sol;
  vector<string> ret = sol.letterCombinations("23");
	printf("hey %d\n", ret.size());
	return 0;
}
