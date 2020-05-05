#include<bits/stdc++.h>
using namespace std;
char s[200];
void work(){
	scanf("%s",s);
	for(int i=0;s[i];i++){
		s[i]-='a';
		s[i]=(s[i]+3)%26;
		s[i]+='a';
	}
	printf("%s",s);
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
