#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,a=0,b=0,c=1;scanf("%d",&n);
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			if(!a)a=i;
			else if(!b)b=i;
			else if(a==b)b*=i;
			else c*=i;
			n/=i;
		}
	}
	c*=n;
	if(a&&b&&c!=1&&a!=c&&a!=b&&b!=c)printf("YES\n%d %d %d\n",a,b,c);
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
