#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define N 100010
int wa[N],wb[N],wv[N],ww[N];
int sa[N],lcp[N],rk[N],f[N][21];
char str[N];
inline bool cmp(int *r,int a,int b,int len){
    return r[a]==r[b]&&r[a+len]==r[b+len];
}
void construct_sa(int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;n++;
    for(i=0;i<m;i++) ww[i]=0;
    for(i=0;i<n;i++) ww[x[i]=str[i]]++;
    for(i=1;i<m;i++) ww[i]+=ww[i-1];
    for(i=n-1;i>=0;i--) sa[--ww[x[i]]]=i;
    for(j=p=1;p<n;j<<=1,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) ww[i]=0;
        for(i=0;i<n;i++) ww[wv[i]=x[y[i]]]++;
        for(i=1;i<m;i++) ww[i]+=ww[i-1];
        for(i=n-1;i>=0;i--) sa[--ww[wv[i]]]=y[i];
        for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void construct_lcp(int n){
    for(int i=0;i<=n;i++) rk[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
        int j=sa[rk[i]-1];
        if(h>0) h--;
        for(;j+h<n&&i+h<n;h++) if(str[i+h]!=str[j+h]) break;
        lcp[rk[i]-1]=h;
    }
}
void st(int n){
    for(int i=1;i<=n;i++) f[i][0]=lcp[i-1];
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
        }
    }
}
int query(int i,int j){
    i=rk[i];j=rk[j];
    if(i>j) swap(i,j);i++;
    int k=log(j-i+1)/log(2);
    return min(f[i][k],f[j-(1<<k)+1][k]);
}
int tmp[N],kkk;
bool vis[N];
int slove(int n){
    int ans=0,sum;
    kkk=0;
    memset(vis,0,sizeof(vis));
    for(int len=1;len<=n;len++){
        for(int i=0;i+len<=n;i+=len){
            int t=query(i,i+len);
            sum=t/len+1;
            int pos=i-(len-t%len);
            if(pos>=0&&t%len!=0) if(query(pos,pos+len)>=(len-t%len)) sum++;
            if(sum>ans) ans=sum;
        }
    }
    for(int len=1;len<=n;len++){
        for(int i=0;i+len<=n;i+=len){
            int t=query(i,i+len);
            sum=t/len+1;
            int pos=i-(len-t%len);
            if(pos>=0&&t%len!=0) if(query(pos,pos+len)>=(len-t%len)) sum++;
            if(sum==ans&&vis[len]==0){
                vis[len]=1;
                tmp[kkk++]=len;
            }
        }
    }
    return ans;
}
int main(){
    int cas=0;
    while(scanf("%s",str)==1){
        if(str[0]=='#') break;
        int len=strlen(str);
        construct_sa(len,200);
        construct_lcp(len);
        st(len);
        int ans=slove(len);
        printf("Case %d: ",++cas);
        int pos=0,leng=0,flag=0;
        for(int i=1;i<=len;i++){
            for(int j=0;j<kkk;j++){//???????????ans???
                int t=query(sa[i],sa[i]+tmp[j]);
                if(t/tmp[j]+1==ans){//????sa[i]???????
                    pos=sa[i];leng=tmp[j];flag=1;break;//?????
                }
            }
            if(flag) break;
        }
        for(int i=pos,j=0;j<leng*ans;j++,i++) printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
