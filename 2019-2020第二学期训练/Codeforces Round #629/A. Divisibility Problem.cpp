#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b;scanf("%d%d",&a,&b);
	printf("%d\n",b-(a-1)%b-1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
