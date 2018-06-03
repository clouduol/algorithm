#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

void genTestCase(vector<int>& v, int k);
void genTestCase1(vector<int>& v);
void genTestCase2(vector<int>& v);
void genTestCase3(vector<int>& v);
void genTestCase4(vector<int>& v);

bool check(vector<int>& v, int& errind);

void printFirstKNum(vector<int>&v, int k);

// v[1..n] are valid numbers, v[0] is useless
void heapSort(vector<int>& v);
void initHeap(vector<int>& v);
void popFirst(vector<int>& v, int n);
int main() {
	vector<int> v;
	for (int i = 1; i < 5; i++) {
		cout << "Case #" << i << ":" << endl;
		cout << "Before sort:" << endl;
		genTestCase(v, i);
		// let v[1] to be the first number
		v.push_back(0);
		for (int i = v.size() - 1; i > 0; i--) {
			v[i] = v[i - 1];
		}
		v[0] = -1;
		printFirstKNum(v, 20);

		cout << "After sort:" << endl;
		unsigned long long startTime = (unsigned long long)clock();
		heapSort(v);
		unsigned long long endTime = (unsigned long long)clock();
		printFirstKNum(v, 20);
		cout << "Sort time:" << (endTime - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
		int errind;
		if (!check(v, errind)) {
			cout << "Error happened!!!\t" << "error index:" << errind << endl;
			cout << v[errind - 1] << "\t" << v[errind] << endl;
		}
		else {
			cout << "Check passed!" << endl;
		}
		cout << endl;
	}
}

void heapSort(vector<int>& v) {
	initHeap(v);
	//cout << "init heap completely" << endl;
	int n = v.size() - 1;
	for (int i = n; i >= 1; i--) {
		popFirst(v, i);
	}

	return;
}

void initHeap(vector<int>& v) {
	int n = v.size() - 1;
	for (int i = n / 2; i >= 1; i--) {
		// down to find the right position
		int c = 2 * i;
		while (c <= n) {
			if (c<n)
				c = v[c]>v[c + 1] ? c : c + 1;
			if (v[c/2] >= v[c])
				break;
			swap(v[c / 2], v[c]);
			c *= 2;
		}
	}

	return;
}

void popFirst(vector<int>& v, int n) {
	swap(v[1], v[n]);
	n--;
	// down to find the right position
	int c = 2;
	while (c <= n) {
		if (c<n)
			c = v[c]>v[c + 1] ? c : c + 1;
		if (v[c / 2] >= v[c])
			break;
		swap(v[c / 2], v[c]);
		c *= 2;
	}

	return;
}


// 1,2 fucntional test
// 3 edge test
// 4 special input test
void genTestCase(vector<int>& v, int k) {
	v.clear();
	switch (k) {
	case 1:
		genTestCase1(v);
		break;
	case 2:
		genTestCase2(v);
		break;
	case 3:
		genTestCase3(v);
		break;
	case 4:
		genTestCase4(v);
		break;
	default:
		genTestCase4(v);
	}

	return;
}

// functional test, small
void genTestCase1(vector<int>& v) {
	int count = 100;
	int max = 50;
	int min = 1;
	int range = max - min + 1;
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < count; i++) {
		int next = rand() % range + min;
		v.push_back(next);
	}
	return;
}

// functional test, large
void genTestCase2(vector<int>& v) {
	int count = 10000;
	int max = 1000;
	int min = 1;
	int range = max - min + 1;
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < count; i++) {
		int next = rand() % range + min;
		v.push_back(next);
	}
	return;
}

// functional test, edge
void genTestCase3(vector<int>& v) {
	int count = 100;
	int number = 5;
	for (int i = 0; i < count; i++) {
		v.push_back(number);
	}
	return;
}

// special test
void genTestCase4(vector<int>& v) {
	return;
}

bool check(vector<int>& v, int& errind) {
	bool sorted = true;
	errind = -1;
	int len = v.size();
	for (int i = 1; i < len; i++) {
		if (v[i] < v[i - 1]) {
			sorted = false;
			errind = i;
			break;
		}
	}

	return sorted;
}

void printFirstKNum(vector<int>&v, int k) {
	for (int i = 0; i < k && i<v.size(); i++) {
		cout << v[i] << "\t";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	return;
}