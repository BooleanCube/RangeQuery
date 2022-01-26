#include <bits/stdc++.h>
using namespace std;

void constructTree(int nums[], int  a) {
	for(int i=a; i<=2*a; i++) {
		int b = i;
		while(b>1) {
			b>>=1;
			nums[b] += nums[i];
			cout << b << " " << nums[b] << endl;
		}
	}
}

void updateTree(int nums[], int k, int w) {
	int a = sizeof(nums)/sizeof(nums[0])/2;
	int b = a+k-1;
	int v = nums[b];
	nums[b] = w;
	while(b>1) {
		b>>=1;
		nums[b] -= v;
		nums[b] += w;
	}
}

int getSumRange(int nums[], int k, int w, int sum) {
	if(k == w) return nums[k] + sum;
	if(k%2 == 1) { sum += nums[k]; k++; }
	if(w%2 == 0) { sum += nums[w]; w--; }
	return getSumRange(nums, k>>1, w>>1, sum);
}

int main() {
	int a, b; cin >> a >> b;
	int nums[2*a+1];
	for(int i=0; i<a; i++) cin >> nums[a+i];
	cout << endl;
	constructTree(nums, a);
	cout << "yes";
	for(int i=0; i<b; i++) {
		int q, k, w; cin >> q >> k >> w;
		cout << "yes";
		if(q == 1) updateTree(nums, k, w);
		else cout << getSumRange(nums, k, w, 0) << endl;
	}
}
