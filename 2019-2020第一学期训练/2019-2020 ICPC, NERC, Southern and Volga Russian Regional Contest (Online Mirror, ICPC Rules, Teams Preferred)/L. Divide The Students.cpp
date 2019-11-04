#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",max((a+b+c-1)/3+1,max((max(a,c)-1)/2+1,min(a,c))));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
