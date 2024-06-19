/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    let l1Copy = l1;
    let l2Copy = l2;

    let firstPointer: ListNode;
    let curPointer: ListNode | null = null;
    let carry = 0;

    while (true) {
        if (!l1Copy && !l2Copy && !carry) {
            break;
        }
        let sum = (l1Copy ? l1Copy.val : 0) + (l2Copy ? l2Copy.val : 0) + carry;
        if (sum > 9) {
            sum = sum % 10;
            carry = 1;
        } else {
            carry = 0;
        }
        const listItem = { val: sum, next: null } as ListNode;
        if (!curPointer) {
            curPointer = listItem;
            firstPointer = listItem;
        } else {
            curPointer.next = listItem;
            curPointer = listItem;
        }
        l1Copy = l1Copy ? l1Copy.next : null;
        l2Copy = l2Copy ? l2Copy.next : null;
    }

    return firstPointer;
};
