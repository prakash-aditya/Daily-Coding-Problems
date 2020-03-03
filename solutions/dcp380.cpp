// take (dividend, divison) as arguments and return (quotient, remainder) without using the division operator.
// Additional: Can you achieve it in O(log n) complexity?

#include <iostream>
#include <utility>
using namespace std;

pair<int, int> divide (int dividend, int divisor) {
	int remainder = dividend % divisor;
	dividend = dividend - remainder;
	int quotient = 0;
	while(dividend) {
		dividend = dividend - divisor;
		quotient++;
	}
	return make_pair(quotient, remainder);
}

pair<int, int> divide_logn(int dividend, int divisor) {
	int remainder = dividend % divisor;
	int quotient = 0;
	dividend = dividend - remainder;
	int factor = 1;
	while(dividend) {
		while(dividend >= divisor && dividend >= factor*divisor*2) {
			factor *= 2;
			int div = factor * divisor;
			dividend -= div; 
			//do the work
			quotient += factor;
		}
		while(factor>0 && dividend < factor*divisor*2) {
			factor /= 2;	
		}
		if(dividend == divisor) {
			dividend -= divisor;
			//do the last work
			quotient += 1;
		}
	}
	
	return make_pair(quotient, remainder);
}	

int main() {
	cout<<"Enter dividend and divisor"<<endl;
	int dividend, divisor;
	cin>>dividend>>divisor;
	pair<int, int> res = divide_logn(dividend, divisor);
	cout<<"Quotient: "<<res.first<<endl;
	cout<<"Remainder:"<<res.second<<endl;

	return 0;
}

