#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
	int m, k, n;
	cin >> m >> k >> n;

	int tmp, i, j, steps=0, workdone, solved=0;
	int arr[n];
	bool m_states[100001] = {0};
	queue<int> q;

	for (i=0; i<n; i++) scanf("%d", arr+i);

	m_states[m] = 1;
	q.push(m);
	int qsize, q0;

	for (steps=1;;steps++){
		workdone = 0;
		qsize = q.size();
		for (i=0; i<qsize; i++){
			q0 = q.front();
			for (j=0; j<n; j++){
				tmp = ((ull) q0 * (ull) arr[j]) % 100000;
				if (!m_states[tmp]){
					q.push(tmp);
					m_states[tmp] = 1;
					workdone = 1;
					if (tmp == k){
						//printf("%d", q0);
						solved = 1;
						break;
					}
				}
			}
			if (solved==1)
				break;
			q.pop();
		}
		if (solved==1){
			printf("%d", steps);
			break;
		}
		else if (workdone == 0){
			printf("-1");
			break;
		}
	}

	return 0;
}