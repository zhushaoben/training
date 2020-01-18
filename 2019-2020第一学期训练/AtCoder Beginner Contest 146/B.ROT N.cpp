#include<bits/stdc++.h>
using namespace std;
char s[10005];
int main(){
	int k;scanf("%d%s",&k,s);
	for(int i=0;s[i];i++){
		putchar(((s[i]-'A'+k)%26)+'A');
	}
	return 0;
}
