#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define rE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node{
    double x,y;
}b[100005];
node O;
double r;
double po(double x){
    return x*x;
}
double jl(node x,node y){
    return sqrt(po(x.x-y.x)+po(x.y-y.y));
}
bool in(node x){
    if(jl(O,x)<=r) return true;
    return false;
}
node solve(double a,double b,double c,double d,double e,double f){
    double y=(f*a-c*d)/(b*d-e*a);
    double x=(f*b-c*e)/(a*e-b*d);
    return (node){x,y};
}
int main(){
    int n;
    cin>>n;
    FOR(i,1,n)cin>>b[i].x>>b[i].y;
    random_shuffle(b+1,b+n+1);
    FOR(i,1,n){
        if(!in(b[i])){
             O.x=b[i].x;O.y=b[i].y;r=0;
            FOR(j,1,i-1){
                if(!in(b[j])){
                    O.x=(b[i].x+b[j].x)/2;
                    O.y=(b[i].y+b[j].y)/2;
                    r=jl(O,b[i]);
                    FOR(k,1,j-1){
                        if(!in(b[k])){
                            O=solve(b[i].x-b[j].x,b[i].y-b[j].y,(po(b[j].x)+po(b[j].y)-po(b[i].x)-po(b[i].y))/2,
                            b[i].x-b[k].x,b[i].y-b[k].y,(po(b[k].x)+po(b[k].y)-po(b[i].x)-po(b[i].y))/2 );
                            r=jl(b[i],O);
                        }
                    }
            
                }
            }
        }
    }
    printf("%.10lf",r);
}
