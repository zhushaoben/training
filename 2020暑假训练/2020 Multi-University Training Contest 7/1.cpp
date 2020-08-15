#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100003;
int main()
{
	for(int i=0; i<=25; i++) printf("%2d ", i); puts("");
	for(int i=1; i<=25; i++) {
		printf("%2d ",i);
		for(int j=1; j<=25; j++) {
			printf("%2d ",__gcd(i, j)>1 ? 1 : 0);
		}
		puts("");
	}
}

