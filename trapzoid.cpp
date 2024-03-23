#include <iostream>
using namespace std;
int main() {
	int width, height;
	double test;
	//used as an indicator if the program should add space or not
	int space = 0;
	cout << "enter width: "; cin >> width;
	cout << "enter height: "; cin >> height;
	// to check if it is possible to draw a trapzoid
	test = width / height;
	if (test >= 2) {
		// height is the number of lines will be drawn
		for (int i{ height }; i >= 0; i--) {
			//width is the number of stars will be drawn
			for (int stars = width; stars >= 0; stars--) {
				cout << '*';
			}
			cout << "\n";
			//to add spaces after new line 
			for (int j = 0; j <= space; j++) {
				cout << ' ';
			}
			//we delete two stars after every line completed
			width -= 2;
			//number of spaces increase when stars decrease
			space += 1;
		}
	}
}
