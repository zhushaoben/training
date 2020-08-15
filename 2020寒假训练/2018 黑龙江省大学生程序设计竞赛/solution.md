$$
首先枚举 2n 的全排列，那么相邻两个配对一下就是答案了，但这样每种配对方式会被算两次，因此答案为：\\

 \frac{(2n)!}{n!2^{n}} \\

考虑到 (2n)!=1 \times 2 \times 3 \times \cdots \times n \times (n+1) \times (n+2) \times \cdots \times (2n)\\

对于所有偶数，都提出一个 2，则 (2n)!=2^n \cdot n! \cdot \prod_{i=1}^{n}(2i-1)\\

即 \frac{(2n)!}{n!2^{n}}=\prod_{i=1}^{n}(2i-1)\\

考虑到模 2^{64}，也就是 (2x)^t 到达一定程度后就成了 0\\

因此可以构造多项式 F_n(x)=\prod_{i=1}^{n}(2i-1+2x)，答案为 F(0)，同时它的次数小于 64\\

考虑倍增，假设现在知道了 F_n(x)，目标要求 F_{2n}(x)，即：\\

 \begin{aligned} F_{2n}(x)=F_n(x) \cdot F_{n}(n+x) \end{aligned} \\

由于已经知道了 F_n(x)=\sum_{i=0}^{63}f_ix^i，因此：\\

 \begin{aligned} F_{n}(n+x) =&\sum_{i=0}^{63}f_i (x+n)^i \\ =&\sum_{i=0}^{63} f_i \sum_{j=0}^{i} {i \choose j} n^{i-j}x^j \\ =&\sum_{j=0}^{63}x^j \sum_{i=j}^{63} {i \choose j} n^{i-j} f_i \end{aligned}\\
 
 然后就多项式快速幂就好了
$$