/*
This problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

#include<iostream>
using namespace std;

void makeRgb(char arr[], int n){
    int beg = 0, end = n-1;
	
	//ignore the begenning r's
	while(arr[beg]=='r') beg++;
	//ignore the last b's
	while(arr[end]=='b') end--;

	//now traverse the remaining array and if encounter r then throw it to the beginning
	//and if encontered b then throw it to the end,  the remaining g's will remain in middle.
	for(int i=beg; i<=end; i++){
		if(arr[i]=='r'){
			char temp = arr[i];
			arr[i] = arr[beg];
			arr[beg] = temp;
			beg++;
			i--;
		}
		else if(arr[i]=='b'){
			char temp = arr[i];
			arr[i] = arr[end];
			arr[end] = temp;
			end--;
			i--;
		}
		else{
		    continue;
		}
	}
}

int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
	makeRgb(arr, n);
	
	for(int i=0; i<n ; i++){
	    std::cout << arr[i] << " ";
	}
}