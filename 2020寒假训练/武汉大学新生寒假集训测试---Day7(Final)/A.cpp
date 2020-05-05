#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char s[maxn],ans1[3];
int main(){
	int n,ans=0;scanf("%d%s",&n,s);
	for(int i='A';i<='Z';i++){
		for(int j='A';j<='Z';j++){
			int w=0;
			for(int k=1;s[k];k++){
				if(s[k]==j&&s[k-1]==i)w++;
			}
			if(w>ans)ans=w,ans1[0]=i,ans1[1]=j;
		}
	}
	puts(ans1);
	return 0;
} 
