#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

void constructTree(int  a) {
	for(int i=a; i<=2*a; i++) {
		int b = i;
		while(b>1) {
			b>>=1;
			nums[b] += nums[i];
		}
	}
}

void updateTree(int k, int w) {
	int a = nums.size()/2;
	int b = a+k-1;
	nums[b] = w;
	while(b>1) {
		b = b>>1;
		nums[b] -= nums[b];
		nums[b] += w;
	}
}

int getSumRange(int k, int w, int sum) {
	if(k == w) return sum;
	if(k%2 == 1) { sum += k; k++; }
	if(w%2 == 0) { sum += w; w--; }
	else getSumRange(k>>1, w>>1, sum);
}

int main() {
	cout << "yes";
	int a, b; cin >> a >> b;
	for(int i=0; i<a; i++) cin >> nums[a+i];
	constructTree(a);
	cout << "yes";
	for(int i=0; i<b; i++) {
		int q, k, w; cin >> q >> k >> w;
		cout << "yes";
		if(q == 1) updateTree(k, w);
		else cout << getSumRange(k, w, 0) << endl;
	}
	cout << "\n";
}
