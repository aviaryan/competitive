function lengthOfLongestSubstring(s: string): number {
  type CharMap = { [key: number]: boolean };
  let answer = 0;
  let j, lastLeftJ = 0;
  let charMap: CharMap = {};

  for (let i = 0; i < s.length; i++) {
    for (j = Math.max(i, lastLeftJ); j < s.length; j++) {
      const code = s.charCodeAt(j);
      if (charMap[code]) {
        answer = Math.max(answer, j - i);
        // update the 'i' and keep going from current "j"
        // since we know non repeating string till before that
        charMap[s.charCodeAt(i)] = false;
        lastLeftJ = j;
        break;
      } else {
        charMap[code] = true;
      }
    }
    if (j === s.length) {
      answer = Math.max(answer, j - i);
      lastLeftJ = 0; // reset it
    }
  }

  return answer;
};