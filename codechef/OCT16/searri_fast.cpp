#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n, d, k;


int compare(const void * a, const void * b){
	const pair<int,int> *ia = (const pair<int,int> *) a;
	const pair<int,int> *ib = (const pair<int,int> *) b;
	return ( ia->first - ib->first );
}

void addToString1(string * s, int i, int j){
	char buff[16];
	snprintf(buff, sizeof(buff), "1 %d %d\n", i+1, j+1);
	(*s).append(buff);
}

void addToString2(string * s, int i){
	char buff[10];
	snprintf(buff, sizeof(buff), "2 %d\n", i+1);
	(*s).append(buff);
}

void updatePos(pair<int,int> * sarr, int size, int val, int np){
	int l = 0, r = size-1, mid;
	while (l <= r){
		mid = (l+r)/2;
		if (sarr[mid].first < val)
			l = mid+1;
		else if (sarr[mid].first > val)
			r = mid-1;
		else {
			sarr[mid].second = np;
			break;
		}
	}
}

double createAns(int * arr, bool * isRemoved, int a, double r){
	double ans = 0;
	double ap = a;
	for (int i=0; i<n; i++){
		if (!isRemoved[i])
			ans += abs( (double) arr[i] - ap );
		ap += r;
	}
	return ans;
}


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> d;
	int arr[n], cpy[n];
	string output = "";
	ll sum = 0;
	// get input
	for (i=0; i<n; i++){
		cin >> arr[i];
		cpy[i] = arr[i];
		sum += (ll) arr[i];
	}
	// first delete
	sort(cpy, cpy+n);
	ll avg = sum / (ll) n;
	ll nc = n;
	int sp = 0, ep = n-1, dc=d;
	multiset<int> deleted;
	while (dc--){
		if (abs(cpy[sp]-avg) > abs(cpy[ep]-avg)){
			deleted.insert(cpy[sp]);
			sum -= cpy[sp];
			sp++; nc--;
			avg = sum / nc;
		} else {
			// cout << "dbg" << cpy[ep] << endl;
			deleted.insert(cpy[ep]);
			sum -= cpy[ep];
			ep--; nc--;
			avg = sum / nc;
		}
	}
	// find possible R
	// FAULT: not actual array deletes are reflected . eg -> in case of duplicates
	int prev;
	ll csum=0;
	for (i=0; i<n; i++){
		if (deleted.find(cpy[i]) == deleted.end()){
			prev = cpy[i];
			break;
		}
	}
	for (i=i+1; i<n; i++){
		if (deleted.find(cpy[i]) == deleted.end()){
			csum += (ll) (cpy[i] - prev);
			prev = cpy[i];
		}
	}
	ll possible_r = csum / (ll) (n-1);
	// reflect delete
	// TODO: go from mid to optimize dupl deletes
	bool isRemoved[n];
	fill_n(isRemoved, n, false);
	multiset <int>::iterator sit;
	for (i=0; i<n; i++){
		sit = deleted.find(arr[i]);
		if (sit != deleted.end()){
			deleted.erase(sit);
			isRemoved[i] = true;
			addToString2(&output, i);
		}
	}
	// swaps
	// find type of seq
	int up=0, down=0;
	csum = 0;
	for (i=0; i<n; i++){
		if (!isRemoved[i]){
			prev = arr[i];
			csum += (ll) arr[i];
			break;
		}
	}
	for (i=i+1; i<n; i++){
		if (!isRemoved[i]){
			if (arr[i] >= prev)
				up++;
			else
				down++;
			prev = arr[i];
			csum += (ll) arr[i];
		}
	}
	// real swapping
	ll possible_a = csum / (ll) (n-d); // TODO: not perfect
	possible_a -= possible_r * ((n-d)/2);
	// TODO: rank based hyper swaps
	// create elements array
	pair<int,int> sarr[n]; int pt = 0;
	for (i=0; i<n; i++)
		if (!isRemoved[i])
			sarr[pt++] = make_pair(arr[i], i);
	qsort(sarr, pt, sizeof(pair<int,int>), compare);
	// real swapping
	int min_id, min, max_id, max, lptr = 0, rptr = pt-1;
	sp = 0; ep = n-1;
	int kc = k;
	if (up >= down){
		while (kc > 0){
			while (isRemoved[sp]) sp++;
			while (isRemoved[ep]) ep--;
			
			min_id = sarr[lptr++].second;
			if (min_id != sp){
				addToString1(&output, min_id, sp);
				updatePos(sarr, pt, arr[sp], min_id); swap(arr[min_id], arr[sp]); swap(isRemoved[min_id], isRemoved[sp]); sp++; kc--;
			} else {
				sp++;
			}

			if (sp >= ep || kc==0) break;

			max_id = sarr[rptr--].second;
			if (max_id != ep){
				addToString1(&output, max_id, ep);
				updatePos(sarr, pt, arr[ep], max_id); swap(arr[max_id], arr[ep]); swap(isRemoved[max_id], isRemoved[ep]); ep--; kc--;
			} else {
				ep--;
			}
		}
	} else {
		while (kc > 0){
			while (isRemoved[sp]) sp++;
			while (isRemoved[ep]) ep--;

			max_id = sarr[rptr--].second;
			if (max_id != sp){
				addToString1(&output, max_id, sp);
				updatePos(sarr, pt, arr[sp], max_id); swap(arr[max_id], arr[sp]); swap(isRemoved[max_id], isRemoved[sp]); sp++; kc--;
			} else {
				sp++;
			}

			if (sp >= ep || kc==0) break;

			min_id = sarr[lptr++].second;
			if (min_id != ep){
				addToString1(&output, min_id, ep);
				updatePos(sarr, pt, arr[ep], min_id); swap(arr[min_id], arr[ep]); swap(isRemoved[min_id], isRemoved[ep]); ep--; kc--;
			} else {
				ep--;
			}
		}
	}
	// get a and r
	// get r
	csum=0;
	int a_start, left_black_end = 0;
	for (i=0; i<n; i++){
		if (!isRemoved[i]){
			prev = arr[i];
			a_start = prev;
			break;
		}
		left_black_end++;
	}
	for (i=i+1; i<n; i++){
		if (!isRemoved[i]){
			csum += (ll) (arr[i] - prev);
			prev = arr[i];
		}
	}
	// right black end
	int black_end = 0;
	for (i=n-1; i>=0; i--)
		if (isRemoved[i])
			black_end++;
		else
			break;

	// cout << "dbg" << black_end << endl;
	double r_space, temp_ans;
	r_space = (double) csum / (double) (n - 1 - black_end - left_black_end);
	// r_space = (double) (sarr[pt-1].first - sarr[0].first) / (double) (n - 1 - black_end - left_black_end);
	double min_so_far = createAns(arr, isRemoved, a_start, r_space);
	// optimize answer through brute force
	double l_rspace = r_space - 0.35 * r_space;
	double r_rspace = r_space + 0.35 * r_space;
	double incr = (r_rspace - l_rspace) / 4000.0;
	for (double ip = l_rspace; ip <= r_rspace; ip += incr){
		temp_ans = createAns(arr, isRemoved, a_start, ip);
		if (temp_ans < min_so_far){
			min_so_far = temp_ans;
			r_space = ip;
		}
	}

	cout << a_start << " " << r_space << "\n" << output << -1 << endl;

	return 0;
}