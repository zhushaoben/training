#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
char s[maxn];
int n,k;
void P(){
	printf("%d\n",n);
	for(int i=0;s[i];i++){
		printf("%c",s[i%k]);
	}
}
int work(){
	scanf("%d%d%s",&n,&k,s);
	bool fl=0;
	for(int i=k;s[i];i++){
		if(s[i]<s[i%k])return P(),0;
		else if(s[i]>s[i%k]){fl=1;break;}
	}
	if(fl)for(int i=k-1;~k;i--){
		if(s[i]!='9'){s[i]++;break;}
		else s[i]='0';
	}
	P();
	return 0;
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
