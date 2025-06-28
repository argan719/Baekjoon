#include<iostream>
using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;

	int n;
	
	int count = 0;
	while (a != b) {
		if (a > b) { count = -2; break;}
		else if (b % 10 == 1) {    
			b = b / 10;
			count += 1;
		}
		else if (b % 2 == 0) {   
			b = b / 2;
			count += 1;
		}
        else { count =-2; break;}
	}
	cout << count + 1;
}