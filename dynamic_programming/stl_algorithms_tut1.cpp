#include "iostream" 
// #include "stdafx.h"
#include "vector"
#include "algorithm"
// #include "sort"
#include "map"
#include "set"
// #include "limits"
#include<bits/stdc++.h> 

using namespace std;

bool cmpFun(int x, int y) {
	return x > y;
}


void vectorDemo() {
	vector<int> A = {11,2,3,14};

	cout << A[1] << endl;

	sort(A.begin(), A.end());
	// 2,3,11,14

	bool present = binary_search(A.begin(), A.end(), 3); // True
	present = binary_search(A.begin(), A.end(), 4); // False

	A.push_back(100); // 2,3,11,14,100
	present = binary_search(A.begin(), A.end(), 100);

	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);

	A.push_back(123);

	// 2,3,11,14,100,100,100,100,100,123

	vector<int>::iterator it = lower_bound(A.begin(),
		A.end(), 100); // >=
	vector<int>::iterator it2 = upper_bound(A.begin(),
		A.end(), 100); // >

	cout << *it << " " << *it2 << endl;

	cout << it2 - it << endl; //4

	// sorting in decreasing order
	sort(A.begin(), A.end(), cmpFun);

	vector<int>::iterator it3;

	for(it3=A.begin();it3 != A.end(); it3++) {
		cout << *it3 << " ";
	}

	cout << endl;



}


void vectorDemoEnchanced() {
	vector<int> A = {11,2,3,14};

	cout << A[1] << endl;

	sort(A.begin(), A.end());
	// 2,3,11,14

	bool present = binary_search(A.begin(), A.end(), 3); // True
	present = binary_search(A.begin(), A.end(), 4); // False

	A.push_back(100); // 2,3,11,14,100
	present = binary_search(A.begin(), A.end(), 100);

	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);

	A.push_back(123);

	// 2,3,11,14,100,100,100,100,100,123

	auto it = lower_bound(A.begin(),
		A.end(), 100); // >=
	auto it2 = upper_bound(A.begin(),
		A.end(), 100); // >

	cout << *it << " " << *it2 << endl;

	cout << it2 - it << endl; //4

	// sorting in decreasing order
	sort(A.begin(), A.end(), cmpFun);

	

	// for(it3=A.begin();it3 != A.end(); it3++) {
	// 	cout << *it3 << " ";
	// }

	// cout << endl;
	for(int x : A) {
		cout << x << " ";
	}
	cout << endl;

	// to iterate over the vector and modify it
	// at the same time
	for(int &x : A) {
		x++;
	}
	cout << endl;

	for(int x : A) {
		cout << x << " ";
	}
	cout << endl;





}


void setDemo() {

	// set is much more powerful than a vector
	// because any new number takes O(log N) time
	// to insert and the set is always sorted which
	// means that I have the capability to find the 
	// next greater element in the set wrt the current 
	// element in just O(log N) time. 

	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(-1);
	s.insert(-10); 

	// in a set, values are always sorted
	//insertion = O(log N)

	for(int x : s) {
		cout << x << " ";
	}
	cout << endl;

	// -10, -1, 1, 2

	auto it = s.find(-1);

	if(it == s.end()) {
		cout << "not found\n";
	}
	else {
		cout << "found\n";
		cout << *it << endl;
	}

	// since s is always sorted, no need to specify
	// the sorted space, hence s has upper_bound()
	// built into itself.
	auto it2 = s.upper_bound(-1);
	auto it3 = s.upper_bound(0);

	cout << *it2 << " " << *it3 << endl;

	s.erase(1);

	for(int x : s) {
		cout << x << " ";
	}
	cout << endl;

	auto it4 = s.upper_bound(2);
	if(it4 == s.end()) {
		cout << "oops, can't find something like that" << endl;

	}




}

void mapDemo() {
	map<int, int> A;
	A[1] = 10;
	A[2] = -1;
	A[3] = 10243535;
	A[5315325] = -11;
	// and so on
	// we can map any value to any value
	map<char, int> cnt;

	string x = "ravi ranjan";

	for(char c : x) {
		cnt[c]++;
	}

	cout << cnt['a'] << " " << cnt['r'] << endl;
	// map also has elements sorted.
	// here also we can find an element greater
	// than a given element by cnt.find(key) and also
	// erase an element, both in logN time.



}


void powerOfStl() {

	// problem statement :
	// we have intervals in our data structure
	// [x,y]

	// [2,3]
	// [10,20]
	// [30,400]
	// [401,450]
	// also we don't have overlapping patterns
	// We need to return the interval in which 
	// our query number is present

	set < pair<int, int> > S;
	S.insert({10,20});
	S.insert({2,3});
	S.insert({401, 450});
	S.insert({30, 400});

	// here too the pairs inside the set will be sorted
	// sorting criteria :-

	// {a,b} < {c,d}:if a < c or a == c and b < d

	for(pair<int, int> x : S) {
		cout << x.first << " " << x.second << endl;
	}

	// [2,3], [10,20], [30, 400], [401,450]


	// corner cases : 
	// if the iterator returns the first interval itself. 
	// 	then, an interval before it does not exist
	// if the iterator returns S.end(), which means the element is 
	// 	present in the interval just before it, and we get that 
	// in our code automatically, so no need of any extralines of code.




	// int point = 50;
	int point = 401;
	// int point = 400; 
	// int point = 2;
	

	auto it = S.upper_bound({point, INT_MAX});
	
	if(it == S.begin()) {
		cout << "not present in any of the intervals" << endl;
		return;
	}
	it--;
	pair<int, int> current = *it;

	if(current.first <= point && point <= current.second) {
		cout << "yes present in the interval: " << current.first 
			<< "," << current.second << endl;
	}
	else 
		cout << "not present in any of the intervals" << endl;


	
}

int main() {

	// vectorDemo();

	// vectorDemoEnchanced();

	// setDemo();

	// mapDemo();
	
	powerOfStl();

	return 0;
}