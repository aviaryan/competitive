function lengthOfLongestSubstring(s: string): number {
  type CharMap = { [key: number]: boolean };
  let answer = 0;
  let j;

  for (let i = 0; i < s.length; i++) {
    let charMap: CharMap = {};
    for (j = i; j < s.length; j++) {
      const code = s.charCodeAt(j);
      if (charMap[code]) {
        answer = Math.max(answer, j - i);
        break;
      } else {
        charMap[code] = true;
      }
    }
    if (j === s.length) {
      answer = Math.max(answer, j - i);
    }
  }

  return answer;
}
