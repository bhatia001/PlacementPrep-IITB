#include "iostream"
#include "unordered_map"
#include "map"

using namespace std;

void unordered_mapDemo() {

	map<char, int> M;
	unordered_map<char, int> U;

	string s = "ravi ranjan";

	for(char c : M) M[c]++; // O(NlogN), N = |s|

	// insertion in unordered map takes O(1)
	// insertion in map takes O(log N)
		// add(key, value)
		// erase(key)
	for(char c : U) U[c]++; // O(N)
}

int main() {

	// unordered_mapDemo();

	// problem solving :
	// Question :- Partition the array such that both 
	// havles have same sum, position of one element 
	// can be changed at max.

	//  solution :-

	// initialize an empty vector of size n
	vector<long long> A(n+5,0);

	long long S = 0;
	// put values inside that vector and find sum of 
	// all elements
	for(int i=0;i<n;i++) { cin >> A[i]; S += A[i]; }


	// initialize 2 maps 
	map<long long , long long> first;

	// first map contains the first element
	first[A[0]]++;

	// second map contains the rest of the elements
	for(int i=1;i<n;i++) second[A[i]]++;

	// iterate over the all the possible first i's
	// if sum till ith index == overall sum / 2, 
	// we are done


	// if sum till ith index < overall sum / 2, 

	// find the element in the right half to 
	//bring to left half by S/2 - sum

	// else do the opposite of above 	
	long long sdash = 0;
	for(int i=0;i<n;i++) {
		sdash += A[i];

		if(sdash == S/2) {
			cout << "yes" << endl;
			return;
		}
		else if(sdash > S/2) {
			long long x = sdash - S/2;
			if(first[x] > 0) {
				cout << "yes" << endl;
				return;
			}
		}
		else {
			long long y = S/2 - sdash;
			if(second[x] > 0) {
				cout << "yes" << endl;
				return;
			}
		}

		// i+1 th element should be added into 
		// the first map and removed from the second
		// map to maintain the two maps' authenticity
		first[i+1]++;
		second[i+1]--;
	}
	
	cout << "No" << endl;
	return 0;
}
