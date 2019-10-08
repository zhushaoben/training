#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char s[maxn],s1[maxn];
void work(){
	scanf("%s%s",s,s1);
	int l=strlen(s),l1=strlen(s1),w,w1;
	for(int i=l1-1;i>=0;i--){
		if(s1[i]=='1'){
			w=l1-i;
			break;
		}
	}
	for(int i=l-w;i>=0;i--){
		if(s[i]=='1'){
			w1=l-i;
			break;
		}
	}
	printf("%d\n",w1-w);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
