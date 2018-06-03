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

void bucketSort(vector<int>& v);
void bucketSort(vector<int>& v, int bucketNumber);
int main() {
	vector<int> v;
	for (int i = 1; i < 5; i++) {
		cout << "Case #" << i << ":" << endl;
		cout << "Before sort:" << endl;
		genTestCase(v, i);
		printFirstKNum(v, 20);

		cout << "After sort:" << endl;
		unsigned long long startTime = (unsigned long long)clock();
		bucketSort(v, 100);
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

void bucketSort(vector<int>& v, int bucketNumber) {
	int n = v.size();
	vector<vector<int>> bucket(bucketNumber, vector<int>());
	for (int i = 0; i < n; i++) {
		int b = v[i] % bucketNumber;
		// insert to this bucket, keep sorted as insertion sort
		bucket[b].push_back(v[i]);
		for (int j = bucket[b].size() - 1; j > 0 && bucket[b][j] < bucket[b][j - 1]; j--)
			swap(bucket[b][j], bucket[b][j - 1]);
	}
	// merge each non-empty bucket
	int vl = 0;
	for (int b = 0; b < bucketNumber; b++) {
		int bl = bucket[b].size();
		if (bl == 0)
			continue;
		vector<int> temp(vl+bl);
		int indv = 0, indb = 0, indt = 0;
		while (indv < vl && indb < bl) {
			if (v[indv] <= bucket[b][indb])
				temp[indt++] = v[indv++];
			else
				temp[indt++] = bucket[b][indb++];
		}
		while(indv<vl)
			temp[indt++] = v[indv++];
		while(indb<bl)
			temp[indt++] = bucket[b][indb++];
		for (int i = 0; i < bl + vl; i++) {
			v[i] = temp[i];
		}
		vl += bl;
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