#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;
typedef vector<double>::size_type dbl_vec_size;

struct some {
	string name;
	double a;
};

int main(){
	vector<double> arr;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);
	dbl_vec_size var = arr.size();

	cout << var << endl;

	sort(arr.begin(), arr.end());

	cout << arr[0] << arr[1] << arr[2] << endl;

	arr.clear();
	cout << "size after clear " << arr.size() << endl;

	struct some j1, j2;
	j1.name = "avi", j2.name = "annat";

	cout << "dictionary ordering strings : avi > annat " << (j1.name > j2.name) << endl;

	// precision
	cout << setprecision(3) << 2.4343 << endl;

	return 0;
}
