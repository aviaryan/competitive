function reverse(x: number): number {
  let final = 0;
  let rem = 0;
  const minNum = -(2 ** 31);
  const maxNum = 2 ** 31 - 1;

  while (true) {
    rem = x % 10;
    final = 10 * final + rem;
    x = (x - rem) / 10;
    if (x === 0) {
      break;
    }
  }
  if (final < minNum || final > maxNum) {
    return 0;
  }
  return final;
}
