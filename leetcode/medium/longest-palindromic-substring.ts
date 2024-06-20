function longestPalindrome(s: string): string {
  const size = s.length;
  let longest = s.charAt(0);
  let leftSide, rightSide: number;

  for (let i = 0; i < size; i++) {
    // 1st strat, take cur character and next and check palindrome
    rightSide = i + 1;
    leftSide = i;
    // skip some easy cases where a longer palindrome can't be formed
    if ((size - rightSide) * 2 + 2 <= longest.length) {
      break; // can start breaking as winner ain't coming
    }
    // 1st strat continue
    while (true) {
      if (rightSide >= size) {
        break; // can only reach here on first loop
      }
      if (s.charAt(leftSide) === s.charAt(rightSide)) {
        leftSide--;
        rightSide++;
      } else {
        const palindromeLen = rightSide - leftSide - 1; // this combo failed, so -1
        if (palindromeLen > longest.length) {
          longest = s.substring(leftSide + 1, rightSide - 1 + 1);
        }
        break;
      }

      if (leftSide < 0 || rightSide >= size) {
        // if going out of bounds, save previous palindrome
        leftSide++;
        rightSide--;
        const palindromeLen = rightSide - leftSide + 1;
        if (palindromeLen > longest.length) {
          longest = s.substring(leftSide, rightSide + 1);
        }
        break;
      }
    }
    // 2nd strat, take curChar as middle and move on both sides
    rightSide = i + 1;
    leftSide = i - 1;
    while (true) {
      if (leftSide < 0 || rightSide >= size) {
        break; // can only reach here on first loop
      }
      if (s.charAt(leftSide) === s.charAt(rightSide)) {
        leftSide--;
        rightSide++;
      } else {
        const palindromeLen = rightSide - leftSide - 1; // this combo failed, so -1
        if (palindromeLen > longest.length) {
          longest = s.substring(leftSide + 1, rightSide - 1 + 1);
        }
        break;
      }

      if (leftSide < 0 || rightSide >= size) {
        // if going out of bounds, save previous palindrome
        leftSide++;
        rightSide--;
        const palindromeLen = rightSide - leftSide + 1;
        if (palindromeLen > longest.length) {
          longest = s.substring(leftSide, rightSide + 1);
        }
        break;
      }
    }
  }

  return longest;
}
