#include <iostream>
#include <vector>

using namespace std;
typedef vector<double>::size_type dbl_vec_size;
typedef vector<double> vecd;

vecd fun(int a, int b){
    vecd arr;
    arr.push_back(a);
    arr.push_back(b);
    return arr;
}

struct some {
    int a;
    char b;
};

main(){
    vector<double> a;
    a = fun(2,3);
    cout << a.size() << endl;

    vector<struct some> lol;
    struct some temp;
    temp.a = 2, temp.b = 65;

    lol.push_back(temp); // 1st
    temp.b = 66;
    lol.push_back(temp); // 2nd
    cout << lol[1].b << endl;

    vector<struct some>::iterator someit; // iterator , just like pointer
    someit = lol.begin();
    cout << "iterator " << someit->a << endl;
}