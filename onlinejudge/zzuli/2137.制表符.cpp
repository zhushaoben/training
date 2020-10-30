#include<bits/stdc++.h>
using namespace std;
char s[100];
void work(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;s[j];j++){
			if(s[j]=='-'&&s[j+1]=='>'){for(int l=0;l<k;l++)putchar(' ');j++;}
			else putchar(s[j]);
		}
		puts("");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
