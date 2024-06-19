function minDays(bloomDay: number[], m: number, k: number): number {
  if (m * k > bloomDay.length) {
    return -1;
  }
  // get max maturity value
  let max = 0;
  for (let i = 0; i < bloomDay.length; i++) {
    if (bloomDay[i] > max) {
      max = bloomDay[i];
    }
  }
  // binary search and brute till from 1 to max
  let leftSide = 0; // if you start from 1 and rightSide is 2, then it never checks 1
  let rightSide = max;
  let checkNumber = 0;
  // binary search
  while (true) {
    checkNumber = Math.ceil((leftSide + rightSide) / 2);
    let bouqetCount = 0;
    let adjFlowerCounter = 0;
    for (let i = 0; i < bloomDay.length; i++) {
      if (bloomDay[i] <= checkNumber) {
        adjFlowerCounter++;
        if (adjFlowerCounter === k) {
          bouqetCount++;
          if (bouqetCount === m) {
            break;
          }
          adjFlowerCounter = 0;
        }
      } else {
        adjFlowerCounter = 0;
      }
    }
    if (bouqetCount === m) {
      if (rightSide === checkNumber) {
        // already rightSide is this, so we will move in loop, return it
        break;
      }
      rightSide = checkNumber;
    } else {
      leftSide = checkNumber;
    }
    if (leftSide >= rightSide) {
      break;
    }
  }
  return checkNumber;
}
