class ListNode():
	def __init__(self, x):
		self.val = x
		self.next = None


def merge(lists):
	final_list = ListNode(-1)
	remaining = len(lists)

	while remaining > 0:
		min_val = 1000000
		# smallest_list = None
		list_pos = -1
		ct = 0
		# loop finds the smallest value in all lists
		for ls in lists:
			if ls is None:  # skip if list already completely scanned
				continue
			if ls.val < min_val:
				# smallest_list = ls
				min_val = ls.val
				list_pos = ct
			ct += 1
		# set value
		temp = final_list
		while temp.next != None:
			temp = temp.next
		temp.next = ListNode(min_val)
		# delete the already taken value
		# print(min_val, lists[list_pos])
		if lists[list_pos]:
			lists[list_pos] = lists[list_pos].next
		# list over?
		if lists[list_pos] is None:
			remaining -= 1

	return final_list.next


def printlist(ln):
	temp = ln
	while temp != None:
		print(temp.val)
		temp = temp.next


if __name__ == '__main__':
	l1 = ListNode(1)
	l1.next = ListNode(4)
	l1.next.next = ListNode(5)

	l2 = ListNode(2)
	l2.next = ListNode(6)

	l3 = ListNode(1)
	l3.next = ListNode(3)
	l3.next.next = ListNode(4)

	merged = merge([l1, l2, l3])

	printlist(merged)

