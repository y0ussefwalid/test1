#include <iostream>
using namespace std;
int main() {
	int width, height;
	double test;
	int space = 0;
	cout << "enter width: "; cin >> width;
	cout << "enter height: "; cin >> height;
	test = width / height;
	if (test >= 2) {
		for (int i{ height }; i >= 0; i--) {
			for (int stars = width; stars >= 0; stars--) {
				cout << '*';
			}
			cout << "\n";
			for (int j = 0; j <= space; j++) {
				cout << ' ';
			}
			width -= 2;
			space += 1;
		}
	}
}