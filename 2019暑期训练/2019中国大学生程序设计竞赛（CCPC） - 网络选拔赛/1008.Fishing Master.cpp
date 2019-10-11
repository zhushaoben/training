#include<bits/stdc++.h>
using namespace std;
int a[100010];
int k;
bool cmp(int a, int b) {
	return a % k > b % k;
}
void work(){
	int n;
	scanf("%d%d", &n, &k);
	long long ans = k;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		ans += a[i];
		cnt += a[i] / k;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i < n - cnt; i++) {
		ans += k - a[i] % k;
	}
	printf("%lld\n", ans);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
	return 0;
}
