#include<bits/stdc++.h>
using namespace std;
int ans[]={0,1,1,2,2};
void work(){
	int a,b;scanf("%d%d",&a,&b);
	a=abs(a-b);
	printf("%d\n",a/5+ans[a%5]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
