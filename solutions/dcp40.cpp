/*
Given an array of integers where every integer occurs three times except 
for one integer, which only occurs once, find and return the non-duplicated integer.
*/


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    //take input
	    for(int i=0; i<n;i++){
	        cin>>arr[i];
	    }
	    //initialise two variables
	    int ones=0;  //ones keep xor of elements once appeared 
	    int twos = 0;//twos keep xor of elements appeared twice
	    
	    for(int i=0; i<n; i++){
	        twos = twos | ones & arr[i];
	        ones = ones ^ arr[i];
	        //when both have common bits that means element appeared thrice
	        //remove the common bits from twos and ones
	        int not_three = ~(twos & ones);
	        twos = twos & not_three;
	        ones = ones & not_three;
	    }
	    
	    cout<<ones<<endl;
	}
	return 0;
}