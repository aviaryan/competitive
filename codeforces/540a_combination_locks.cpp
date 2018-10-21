Problem Statement: McDuck keeps his most treasured savings in a home safe with a combination lock. Each time he wants to put there the treasures that he's earned fair and square, he has to open the lock.The combination lock is represented by n rotating disks with digits from 0 to 9 written on them. Scrooge McDuck has to turn some disks so that the combination of digits on the disks forms a secret combination. In one move, he can rotate one disk one digit forwards or backwards. In particular, in one move he can go from digit 0 to digit 9 and vice versa. What minimum number of actions does he need for that?
	
Solution:The answer is the sum of all the changes needed over the number if disks i.e. (n).Also for each disk we can go either forward or backward, so in order to minimise the number of moves we will select that combination which will give less number of moves.
For Example: Let's say we have to change  form 1->7. So the first possibility is moving forward form 1->2->3->4->5->6->7 which gives the number of moves as 6.But if we move backward form 1->0->9->8->7 then no. of moves=4. Thus we will move backward and add 4 to answer.This can be easily visualised if you have visualised the lock system being talked about in the question.

#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
using namespace std;
typedef long long int ll;


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	string s1, s2;
	int ans=0, z;
	cin >> s1 >> s2;
	for (int i=0; i<t; i++)
		ans += min( abs(s1[i]-s2[i]) , 10-abs(s1[i]-s2[i]) );   // ans is minimum of forward & backward moves where 										10-abs(s1[i]-s2[i]) gives the no. of backward moves.
	cout << ans << endl;

	return 0;
}
