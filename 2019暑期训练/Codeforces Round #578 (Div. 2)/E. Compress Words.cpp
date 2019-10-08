#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
char now[maxn],s[maxn];
int nex[maxn];int len1;
void kmp(char* s , char* t){
    int  len2;
    len2 = strlen(t);
    int i , j = 0 , tm = nex[0] = -1;
    while(j<len2-1){
        if(tm<0||t[j]==t[tm])
            nex[++j] = ++tm;
        else tm = nex[tm];
    }
    for( j=0,i=len1-len2 ; i < len1 && j < len2 ; )
    {
        if(j<0||s[i]==t[j]) i++,j++;
        else j = nex[j];
    }
    while(j<len2)now[len1++]=t[j++];
}
int main(){
	int n;scanf("%d",&n);
	scanf("%s",now);len1=strlen(now);
	for(int i=1;i<n;i++){
		scanf("%s",s);
		kmp(now,s); 
	}
	printf("%s",now);
	return 0;
}
