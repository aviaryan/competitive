#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "Hello world !";
	cout << " no endl , same line - Enter string" << endl;
	string name;

	cin >> name;

	cout << "Hello " << name << endl;

	cout << "Your name length is " << name.size() << endl;

	string hashes(10, '#');
	cout << hashes << endl;


	return 0;
}
