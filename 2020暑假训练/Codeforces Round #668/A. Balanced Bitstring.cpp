#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
char s[N];
int work(){
	int n,k;scanf("%d%d%s",&n,&k,s);
	for(int i=0;i<k;i++){
		for(int j=i+k;j<n;j+=k){
			if((s[i]^s[j])==1)return puts("NO"),0;
			if(s[i]=='?')s[i]=s[j];
		}
	}
	int a=0,b=0;
	for(int i=0;i<k;i++){
		if(s[i]=='0')a++;
		if(s[i]=='1')b++;
	}
	if(a>k/2||b>k/2)puts("NO");
	else puts("YES");
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
