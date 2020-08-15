#include<bits/stdc++.h>
using namespace std;
char s[200];
int main(){
	int k,l;scanf("%d%s",&k,s),l=strlen(s);
	if(l>k)s[k]=s[k+1]=s[k+2]='.',s[k+3]=0;
	puts(s);
	return 0;
}
