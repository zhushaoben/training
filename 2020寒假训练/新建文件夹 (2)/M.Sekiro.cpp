#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,k;scanf("%d%d",&n,&k);
	if(k>50){printf("%d\n",n?1:0);return;}
	while(k--)n=(n>>1)+(n&1);
	printf("%d\n",n);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
