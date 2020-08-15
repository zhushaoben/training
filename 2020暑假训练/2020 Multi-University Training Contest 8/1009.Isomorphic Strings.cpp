#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" "<<x<<endl;

const int N=5e6+5;
const double eps=1e-9;
const int INF=1e18;

char ss[N];

int minRepresent(char *s,int len)
{
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0) k++;
        else{
            if(t<0) j=max(j+k+1,i+1);
            else i=max(i+k+1,j+1);
            k=0;
        }
    }
    return min(i,j);
}

int n;
char str[N];
char snow[N];
vector<int> f;

bool checked(int l)
{
    for(int i=0;i<n;i+=l){
        for(int j=i;j<i+l;j++) ss[j-i]=str[j];
        int str=minRepresent(ss,l);
        if(i==0){
            for(int j=0;j<l;j++) snow[j]=ss[(j+str)%l];
        }
        else {
            for(int j=0;j<l;j++) if(snow[j]!=ss[(j+str)%l]) return 0;
        }
    }
    return 1;
}
int num[26];
void solve()
{
    scanf("%d%s",&n,str);
    for(int i=0;i<26;i++)num[i]=0;
    for(int i=0;str[i];i++)num[str[i]-'a']++;
    f.clear();
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
        	bool fl=1;int k=n/i;
        	for(int j=0;j<26;j++)if(num[j]%k)fl=0;
            if(fl)f.push_back(i);
            if(i*i!=n){
				fl=1;
        		for(int j=0;j<26;j++)if(num[j]%i)fl=0;
        		if(fl)f.push_back(k);
			}
        }
    }
    for(auto v:f){
        if(v!=n&&checked(v)){
            puts("Yes");
            return ;
        }
    }
    puts("No");
}

signed main(){
    int t;scanf("%d",&t);
    while(t--) solve();
    return 0;
}
