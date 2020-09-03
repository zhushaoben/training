#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1;
int main(){
	int n,x,t;scanf("%d%d%d",&n,&x,&t);
	printf("%d",((n-1)/x+1)*t);
	return 0;
}
