#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
	int n,k,fl;scanf("%d%d%s",&n,&k,s);
	printf("%s",s);
	for(int i=1;i<=n;i++){
		fl=1;
		for(int j=0;j+i<n;j++)
		if(s[j]!=s[(j+i)%n]){fl=0;break;}
		if(fl){fl=i;break;}
	}
	for(int i=1;i<k;i++)printf("%s",s+n-fl);
	return 0;
} 
