#include "bits/stdc++.h"

using namespace std;


struct coordinates {
    long int x, y;
};
 
 
/* Following two functions are needed for library function qsort().
   Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
 
// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b) {
    coordinates *p1 = (coordinates *)a,  *p2 = (coordinates *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b) {
    coordinates *p1 = (coordinates *)a,   *p2 = (coordinates *)b;
    return (p1->y - p2->y);
}
 
// A utility function to find the distance between two points
double dist(coordinates p1, coordinates p2) {
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
vector<coordinates> bruteForce(coordinates P[], int n) {
    double min = (double)FLT_MAX;
    vector <coordinates> ret;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min) {
                min = dist(P[i], P[j]);
                ret.push_back(P[i]);
                ret.push_back(P[j]);
            }
    return ret;
}
 
// A utility function to find minimum of two float values
double min(double x, double y) {
    return (x < y)? x : y;
}
 
 
// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
vector<coordinates> stripClosest(coordinates strip[], int size, double d) {
    double min = d;  // Initialize the minimum distance as d
 	vector<coordinates> ret;
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min) {
                min = dist(strip[i], strip[j]);
                ret.push_back(strip[i]);
                ret.push_back(strip[j]);
            }
 
    return ret;
}
 
// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates
vector<coordinates> closestUtil(coordinates Px[], coordinates Py[], int n) {
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);
 
    // Find the middle point
    int mid = n/2;
    coordinates midPoint = Px[mid];
 
 
    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    coordinates Pyl[mid+1];   // y sorted points on left of vertical line
    coordinates Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++) {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
 
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    vector<coordinates> tmp;
    vector<coordinates> tmp1;
    vector<coordinates> tmp2;
    tmp1 = closestUtil(Px, Pyl, mid);
    double dl = dist(tmp1[0], tmp1[1]);
    tmp2 = closestUtil(Px + mid, Pyr, n-mid);
    double dr = dist(tmp2[0], tmp2[1]);
 
    // Find the smaller of two distances
    double d = min(dl, dr);
    tmp = (dl < dr)? tmp1:tmp2;

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    coordinates strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
 
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    vector<coordinates> tmp3 = stripClosest(strip, j, d);
    // cout << tmp3[0].x << tmp3[0].y << tmp3[1].x << tmp3[1].y << endl;
    // cout << "h" << endl;
    if (tmp3.size() == 0)
        return tmp;
    vector<coordinates> f2 =  (d <  dist(tmp3[0], tmp3[1]))? tmp:tmp3;
    return f2;
}
 
// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
vector<coordinates> find_closest(vector < coordinates > P, int n) {
    coordinates Px[n];
    coordinates Py[n];
    for (int i = 0; i < n; i++) {
        Px[i] = P[i];
        Py[i] = P[i];
    }
 
    qsort(Px, n, sizeof(coordinates), compareX);
    qsort(Py, n, sizeof(coordinates), compareY);
 
    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(Px, Py, n);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector < coordinates > points(n);
		for (int i = 0; i < n; ++i) {
			cin >> points[i].x >> points[i].y;
		}
		
		double ans = 0;
		vector < coordinates >return_point; 

		for (int i = 0; i < n/2; ++i) {
			return_point = find_closest(points, n-2*i);
            ans += sqrt((return_point[0].x-return_point[1].x)*(return_point[0].x-return_point[1].x) + (return_point[0].y-return_point[1].y)*(return_point[0].y-return_point[1].y));
			for (int j = 0; j < points.size(); ++j) {
				if (points[j].x == return_point[0].x && points[j].y == return_point[0].y) {
					swap(points[j], points.back());
					points.pop_back();
					break;
				}
			}
			for (int j = 0; j < points.size(); ++j) {
				if (points[j].x == return_point[1].x && points[j].y == return_point[1].y) {
					swap(points[j], points.back());
					points.pop_back();
					break;
				}
			}
			//ans += dist(return_point[0], return_point[1]);
		}

        cout << ans << endl;
	}

	return 0;
}
