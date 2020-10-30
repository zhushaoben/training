#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ans1[N],ans2[N],si;
void work(int l,int r){
	if(l + 1 == r) {ans1[++si] = l,ans2[si] = r;return;}
	int mid = (l+r) >> 1;
	work(mid+1, r);
	work(l, mid);
	for(int i=l,j=1; i<=mid; i++,j++) {
		ans1[++si] = i;
		ans2[si] = mid + j;
	}
}
int main(){
	int n;scanf("%d",&n);
	if(n == 1) return printf("0\n"),0;
	if(n == 2) return printf("1\n1 2\n"),0;
	int w = 1;
	while(w < n) w <<= 1;w>>=1;
	work(n - w + 1, n);
	work(1, w);
	printf("%d\n", si);
	for(int i=1; i<=si; i++) printf("%d %d\n", ans1[i], ans2[i]);
}
