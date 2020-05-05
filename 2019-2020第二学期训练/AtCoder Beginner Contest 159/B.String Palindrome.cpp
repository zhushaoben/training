#include<bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n/2;i++)if(s[i]!=s[n-i-1])return puts("No"),0;
	for(int i=0;i<n/4;i++){
		if(s[i]!=s[n/2-i-1]||s[(n+1)/2+i]!=s[n-i-1])return puts("No"),0;
	}
	puts("Yes");
	return 0;
}
