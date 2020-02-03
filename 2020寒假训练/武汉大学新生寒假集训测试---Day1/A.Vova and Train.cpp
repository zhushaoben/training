#include<bits/stdc++.h>
using namespace std;
void work(){
	int L,v,l,r;scanf("%d%d%d%d",&L,&v,&l,&r);
	printf("%d\n",L/v-r/v+(l-1)/v);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
