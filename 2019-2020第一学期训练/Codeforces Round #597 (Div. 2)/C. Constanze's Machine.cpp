#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
char s[100005];
int f[100005];
int main(){
	scanf("%s",s+2);int n=strlen(s+2);
	f[0]=f[1]=1;
	for(int i=2;s[i];i++){
		if(s[i]=='m'||s[i]=='w'){puts("0");return 0;}
		f[i]=f[i-1];
		if((s[i]=='u'&&s[i-1]=='u')||(s[i]=='n'&&s[i-1]=='n'))(f[i]+=(f[i-2]))%=mo;
	}
	printf("%d",f[n+1]);
	return 0;
}
