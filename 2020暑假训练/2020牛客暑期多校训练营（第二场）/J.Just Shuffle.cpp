#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,S=1e4;
typedef long long ll;
void exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1,y=0;return;
    }
    ll t;
    exgcd(b,a%b,x,y);
    t=x,x=y,y=t-(a/b)*y;
}
struct A{
	int a[N],l;
	void Scan(){for(int i=1;i<=l;i++)scanf("%d",a+i);}
	void Print(){for(int i=1;i<=l;i++)printf("%d ",a[i]);}
	A operator *(const A &b)const{
		A c;c.l=l;
		for(int i=1;i<=l;i++)c.a[i]=b.a[a[i]];
		return c;
	}
}x,ans1;
class Bignum
{
    void mknum(const char *s, int len = -1)
    {
        sign = 0;
        if(*s == '-')
        {
            mknum(s+1);
            sign = 1;
            return;
        }
        int l;
        if(len == -1)
            l = strlen(s);
        else
            l = len;
        l = strlen(s);
        bits.clear();
        bits.resize(l);
        for(int i = l-1; i >= 0; i--)
            bits[l-i-1] = s[i] - '0';
        maintain();
    }
    void mknum(string &s)
    {
        mknum(s.c_str(), s.length());
    }
//    -------------
    void us_addto(Bignum &b)  // unsigned add to
    {
        int mlen = max(b.bits.size(), bits.size());
        int slen = bits.size();
        int olen = b.bits.size();
        bits.resize(mlen);
        for(int i = 0; i < mlen; i++)
        {
            int s = 0;
            if(i < slen)s += bits[i];
            if(i < olen)s += b.bits[i];
            bits[i] = s;
        }
        maintain();
    }
    class FFTer
    {
        class Complex
        {
        public:
            double real, image;
            Complex(double a = 0, double b = 0)
            {
                real = a;
                image = b;
            }
            Complex operator + (const Complex &o){return Complex(real+o.real, image+o.image);}
            Complex operator - (const Complex &o){return Complex(real-o.real, image-o.image);}
            Complex operator * (const Complex &o){return Complex(real*o.real-image*o.image, real*o.image+o.real*image);}
            Complex operator * (double k){return Complex(real*k, image*k);}
            Complex operator / (double k){return Complex(real/k, image/k);}
        };
        public:
        vector<Complex> a;  //系数向量
        int n;                //多项式次数上界
        FFTer(vector<int> &vec)
        {
            a.resize(vec.size());
            for(int i = 0; i < vec.size(); i++)
                a[i].real = vec[i];
            n = vec.size();
        }
        void transform()
        {
            int j = 0;
            int k;
            for(int i = 0; i < n; i++)
            {
                if(j > i)swap(a[i], a[j]);
                k = n;
                while(j & (k >>= 1))j &= ~k;
                j |= k;
            }
        }
        void FFT(bool IDFT = false)
        {
            const double Pi = IDFT?-acos(-1.0):acos(-1.0);
                            //IDFT与DFT选择方向相反（符号相反）
            transform();    //交换元素（翻转二进制位，具体看下面注释，再具体看算导
            for(int s = 1; s < n; s <<= 1)
            {    //算法导论上是fot s = 1 to lgn,考虑到精度问题改为上面那个...
                for(int t = 0; t < n; t += s<<1)
                {
                //合并[t, t+s-1]与 [t+s, t+2*s-1] (算导上以指数形式给出，注意到他的s....)
                //合并为[t, t+2*s-1] (看起来像是废话) (有示例图在算导上，画得很形象的)
                /*                一个更简单的示例图
                    (翻转过程)          翻转             合并
                    00    ->    00        0-|--|---------------------------
                                      |  |                    
                    01    ->    10        1-|--|---\ /---------------------
                                      |     |    X             
                    10    ->    01        2-|--|---/ \---------------------
                                      |  |          
                    11    ->    11        3-|--|---------------------------
                */
                    double x = Pi/s;
                    Complex omgn(cos(x), sin(x));
                    Complex omg(1.0, 0.0);    //单位向量
                    for(int m = 0; m < s; m++)
                    {            //旋转
                        int a1 = m+t;
                        int a2 = m+t+s;   //取两边系数向量的系数
                        //算导上管这个叫公共子表达式消除
                            //(其实就是一个变量计算一次然后保存下来用多次...嗯算导总是这么有逼格)
                        Complex comm = omg * a[a2];
                        a[a2] = a[a1] - comm;
                        a[a1] = a[a1] + comm;  //这两个顺序不要反了
                        omg = omg * omgn;
                    }
                }
            }
            if(IDFT)
                for(int i = 0; i < n; i++)
                    a[i] = a[i] / n;
        }
        void mul(FFTer &o)
        {
            int s = 1;
            while(s < n + o.n)s <<= 1;
            n = o.n = s;
            a.resize(s);
            o.a.resize(s);

            FFT(false);
            o.FFT(false);
            for(int i = 0; i < n; i++)
                a[i] = a[i] * o.a[i];
            FFT(true);
        }
    };
    void us_multo(Bignum &b)
    {
        FFTer x(bits);
        FFTer y(b.bits);
        x.mul(y);
        bits.clear();
        bits.resize(x.a.size());
        for(int i = 0; i < x.n; i++)
            bits[i] = (int)(x.a[i].real+0.5);
        maintain();
    }
    void us_multo_simu(Bignum &b)
    {
        vector<int> r;
        r.resize(max(length(),b.length())<<1);
        for(int i = 0; i < length(); i++)
            for(int j = 0; j < b.length(); j++)
                r[i+j] += bits[i] * b.bits[j];
        *(&(this -> bits)) = r;
        maintain();
    }
    void us_subto(Bignum &b) // abs(self) >= abs(other)
    {
        int mlen = length();
        int olen = b.length();
        for(int i = 0; i < mlen; i++)
        {
            int s = bits[i];
            if(i < olen)s -= b.bits[i];
            bits[i] = s;
            if(bits[i] < 0)
            {
                bits[i] += 10;
                bits[i+1] -= 1;
            }
        }
        for(int i = bits.size() - 1; !bits[i] && i >= 1; i--)bits.pop_back();
        if(bits.size() == 1 && bits[0] == 0)sign = 0;
    }
    void us_divto(Bignum &b)
    {
        if(length() == 1 && bits[0] == 0)return;
        Bignum L("0");
        L.sign = 0;
        Bignum R(*this);
        R.sign = 0;
        Bignum two("2");
        R *= two;
        Bignum one("1");
        one.sign = 0;
        while(L + one != R)
        {
            Bignum M = L+R;
            M.divto2();
            Bignum t = M*b;
            if(t > *this)
            {
                R = M;
            }else if(t < *this)
            {
                L = M;
            }else
            {
                *this = M;
                L = M;
                break;
            }
        }
        *this = L;
    }
public:
    int sign;
    vector<int> bits;
    int length()
    {
        return bits.size();
    }
    void maintain()
    {
        for(int i = 0; i < bits.size(); i++)
        {
            if(i + 1 < bits.size())
                bits[i+1] += bits[i]/10;
            else if(bits[i] > 9)
                bits.push_back(bits[i]/10);
            bits[i] %= 10;
        }
        if(bits.size() == 0)
        {
            bits.push_back(0);
            sign = 0;
        }
        for(int i = bits.size() - 1; !bits[i] && i >= 1; i--)bits.pop_back();
    }

    Bignum(string &s)
    {
        Bignum();
        mknum(s);
    }
    Bignum(const char *s)
    {
        Bignum();
        mknum(s);
    }
    Bignum(int n)
    {
        Bignum();
        char buf[15];
        sprintf(buf, "%d", n);
        mknum(buf);
    }
    Bignum()
    {
        sign = 0;
        bits.push_back(0);
    }
    Bignum(const Bignum& b) 
    {
        copy(b);
    }
    void copy(const Bignum& b)
    {
        sign = b.sign;
        bits = b.bits;
    }

// ------------------------------------------
    bool us_cmp(Bignum &b)   //无符号的比较
    {
        if(length() != b.length())return false;
        int l = length();
        for(int i = 0; i < l; i++)
            if(bits[i] != b.bits[i])
                return false;
        return true;
    }
    bool us_larger(Bignum &b)
    {
        if(length() > b.length())return true;
        else if(length() < b.length())return false;
        int l = length();
        for(int i = l-1; i >= 0; i--)
            if(bits[i] > b.bits[i])
                return true;
            else if(bits[i] < b.bits[i])
                return false;
        return false;
    }
    bool operator== (Bignum &o)
    {
        if(sign != o.sign)
            return false;
        return us_cmp(o);
    }
    bool operator!= (Bignum &o)
    {
        return !(*this == o);
    }
    bool operator> (Bignum &o)
    {
        if(sign == 0 && o.sign == 1)return true;
        if(sign == 1 && o.sign == 0)return false;
        if(sign == o.sign && sign)return !us_larger(o);
        return us_larger(o);
    }
    bool operator< (Bignum &o)
    {
        return !(*this == o || *this > o);   //小于就是不等于也不大于 
    }
    bool operator<= (Bignum &o)
    {
        return *this < o || *this == o;
    }
    bool operator>= (Bignum &o)
    {
        return *this > o || *this == o;
    }

// -------------------------------
    Bignum& operator+= (Bignum &o)
    {
        if(!sign && !o.sign)
        {
            us_addto(o);
            sign = 0;
        }
        else if(sign && o.sign)
        {
            us_addto(o);
            sign = 1;
        }
        else if(sign && !o.sign)
        {
            if(o.us_larger(*this))
            {
                Bignum t(o);
                t.us_subto(*this);
                *this = t;
                sign = 0;
            }else
            {
                us_subto(o);
                sign = 1;
                if(bits.size() == 1 && bits[0] == 0)sign = 0;
            }
        }else if(!sign && o.sign)
        {
            if(us_larger(o))
            {
                us_subto(o);
                sign = 0;
            }else
            {
                Bignum t(o);
                t.us_subto(*this);
                *this = t;
                sign = 1;
                if(bits.size() == 1 && bits[0] == 0)sign = 0;
            }
        }
        return *this;
    }
    Bignum operator+ (Bignum &o)
    {
        Bignum t(*this);
        t += o;
        return t;
    }

// ------------------------------
    Bignum& operator*= (Bignum &o)
    {
        if(length() + o.length() > 800)
            us_multo(o);                 //FFT
        else
            us_multo_simu(o);             //simulate
        if(sign == o.sign)sign = 0;
        else sign = 1;
        return *this;
    }
    Bignum operator* (Bignum &o)
    {
        Bignum t(*this);
        t *= o;
        return t;
    }
// -------------------------------
    Bignum& operator-= (Bignum &o)
    {
        if(!sign && !o.sign) 
        {
            if(us_larger(o))
            {
                us_subto(o);
                sign = 0;
            }
            else
            {
                Bignum t(o);
                t.us_subto(*this);
                *this = t;
                sign = 1;
                if(bits.size() == 1 && bits[0] == 0)sign = 0;
            }
        }else if(sign && o.sign)
        {
            if(us_larger(o))
            {
                us_subto(o);
                sign = 1;
                if(bits.size() == 1 && bits[0] == 0)sign = 0;
            }else
            {
                Bignum t(o);
                t.us_subto(*this);
                *this = t;
                sign = 0;
            }
        }else if(!sign && o.sign)
        {
            us_addto(o);
            sign = 0;
        }else if(sign && !o.sign)
        {
            us_addto(o);
            sign = 1;
        }
        return *this;
    }
    Bignum operator- (Bignum &o)
    {
        Bignum t(*this);
        t -= o;
        return t;
    }
// ---------------------------------
    Bignum& divto2()
    {
        if(!bits.size())return *this;
        bits[0] >>= 1;
        int i;
        for(i = 1; i < bits.size(); i++)
        {
            if(bits[i] & 1)bits[i-1] += 5;
            bits[i] >>= 1;
        }
        if(bits[i-1] == 0)bits.pop_back();
        return *this;
    }
    Bignum& operator/= (Bignum &o)
    {
        us_divto(o);
        if(sign == o.sign)sign = 0;
        else sign = 1;
        return *this;
    }
    Bignum operator/ (Bignum &o)
    {
        Bignum t(*this);
        t /= o;
        return t;
    }
// ---------------------------------
    Bignum abs()
    {
        Bignum t(*this);
        t.sign = 0;
        return t;
    }


    Bignum sqrt()
    {
        Bignum L("0"), R(*this);
        Bignum one("1");
        Bignum m, t;
        while(L + one != R)
        {
            m = L+R;
            m.divto2();
            Bignum t = m*m;
            if(t == *this)return m;
            else if(t > *this)R = m;
            else L = m;
        }
        return L;
    }

    //若e <= 0则会返回1
    //底数（也就是this）是负数的话会根据次数决定符号
    Bignum pow(Bignum &e)
    {
        if(e.sign)return 1;
        Bignum ans("1");
        Bignum base(*this);
        Bignum zero("0");
        Bignum exp(e);
        while(exp > zero)
        {
            if(exp.bits[0] & 1)
            {
                ans *= base;
            }
            base *= base;
            exp.divto2();
        }
        if(sign && e.bits[0] & 1)ans.sign = 1;
        return ans;
    }

    //注意，如果本数小于底数返回1...
    Bignum log(Bignum &base)
    {
        if(sign)return 0;
        if(length() == 1 && bits[0] == 1)return 0;
        if(*this <= base)return 1;
        Bignum one("1");

        Bignum r("1");
        Bignum c("0");
        while(r < *this)
        {
            r *= base;
            c += one;
        }
        if(r != *this)c -= one; 
        return c;
    }
    Bignum lg()
    {
        Bignum ten("10");
        return log(ten);
    }

    Bignum factorial()
    {
        Bignum r("1");
        Bignum zero("0");
        Bignum one("1");
        Bignum t(*this);
        while(t > zero)
        {
            r *= t;
            t -= one;
        }
        return r;
    }

// -----------------------------------    
    friend istream& operator>>(istream &is, Bignum &b)
    {
        string s;
        is >> s;
        b.mknum(s);
        return is;
    }
    friend ostream& operator<<(ostream &os, Bignum b)
    {
        if(b.sign)os << '-';
        for(int i = b.bits.size()-1; i >= 0; i--)os << b.bits[i];
        return os;
    }

    string to_string()
    {
        int sz = length();
        string s;
        if(sign)
            s.resize(sz+1);
        else
            s.resize(sz);
        int i = 0;
        if(sign)s[i++] = '-';
        for(int j = sz-1; i < sz+sign; i++, j--)
            s[i] = bits[j] + '0';
        return s;
    }    
}S1,ans,tmp,a0,a1=1,a2=2,w;
bool vis[N];
int v[N],si,k;
void power(Bignum b){
	ans1.l=x.l;
	for(int i=1;i<=ans1.l;i++)ans1.a[i]=i;
	while(b!=a0){
		w=b/a2*a2;
		if(b-w==a1)ans1=ans1*x;
		x=x*x;b/=a2;
	}
}
int main(){
	scanf("%d%d",&x.l,&k);
	x.Scan();
	for(int i=1;i<=x.l;i++){
		if(vis[i])continue;
		int u=x.a[i],w=0;
		do{
			vis[u]=1,w++;
			u=x.a[u];
		}while(!vis[u]);
		v[si++]=w;
	}
	ll x1,y,a=1,b=k;
	for(int i=0;i<si;i++)(a*=v[i])%=k;
	exgcd(a,b,x1,y);
	S1=1,ans=1;
	for(int i=0;i<si;i++)tmp=v[i],S1=S1*tmp;
	ans=S1,tmp=k,ans/=tmp;
	w=x1;w*=ans;
	if(y<0)tmp=-y,tmp=S1-w-tmp;
	else tmp=y,tmp=S1-w+tmp;
	power(tmp);
	ans1.Print();
	return 0;
}
