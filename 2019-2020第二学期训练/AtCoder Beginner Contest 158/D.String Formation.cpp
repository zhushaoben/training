#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
char s[N*3];
int main(){
	int d=0,S=N-1,t,m,op,f;char s1[2];
	scanf("%s%d",s+N,&m);for(t=N;s[t];t++);
	for(int i=0;i<m;i++){
		scanf("%d",&op);
		if(op==1)d^=1;
		else{
			scanf("%d%s",&f,s1),f--;
			if(f^d)s[t++]=s1[0];
			else s[S--]=s1[0];
		}
	}
	if(d)for(int i=t-1;i>S;i--)putchar(s[i]);
	else for(int i=S+1;i<t;i++)putchar(s[i]);
	return 0;
}
