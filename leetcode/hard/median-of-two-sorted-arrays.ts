function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let totalLength = nums1.length + nums2.length;
    let finalArr: number[] = [];
    let num1Ptr = 0, num2Ptr = 0;
    if (totalLength === 0) {
        return 0;
    }

    for (let i = 1; i <= totalLength; i++) {
        if (
            ((num2Ptr >= nums2.length) && (num1Ptr <= nums1.length - 1)) || 
            nums1[num1Ptr] <= nums2[num2Ptr]
        ) {
            finalArr.push(nums1[num1Ptr]);
            num1Ptr++;
        } else {
            finalArr.push(nums2[num2Ptr]);
            num2Ptr++;
        }
        if (i > (totalLength / 2)) {
            break;
        }
    }

    if (totalLength % 2) {
        return finalArr[Math.floor(totalLength / 2)]; 
    } else {
        return (finalArr[totalLength / 2 - 1] + finalArr[totalLength / 2]) / 2;
    }
};