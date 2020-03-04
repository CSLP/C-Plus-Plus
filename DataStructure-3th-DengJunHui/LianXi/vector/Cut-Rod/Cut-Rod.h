//钢条切割问题
#include<math.h>
int * price(int *p,int n)
{
    for(unsigned i=0;i<n;++i)
    {
        p[i]=i+rand()%30;
    }
    return p;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int  simpleRe(int *p,int n)
{
    if(n==0) return 0;
    int q=-1; 
    for(int i=1;i<=n;i++)
        q=max(q,p[i]+simpleRe(p,n-i));
    return q;
}
int dpReTopDownMemoized(int *p,int *m,int n)//自顶向下带备忘的动态规划方法递归。其实是好理解，本质上递的过程依然没有求解，归的过程才求解
{
    if(m[n]>=0) return m[n];
    int q;
    if(n==0) 
        q=0;
    else
    {
        q=-1;
        for(int i=1;i<=n;++i)
            q=max(q,p[i]+dpReTopDownMemoized(p,m,n-i));
    }
    m[n]=q;
    return q;
}
int sequ=0;
int deReTopDownMemoizedExtended(int *p,int *m,int *s,int n) //扩展板，给出收益值得同时给出切割方案，及从左到右的各段的长度
{
    if(m[n]>=0) return m[n];
    int q=-1;
    if(n==0)
       q=0;
    else
    {
        for(int i=1;i<=n;++i)
        {
            int temp=q;
            q=max(q,p[i]+deReTopDownMemoizedExtended(p,m,s,n-i));
            if(q!=temp) s[sequ]=i; 
        }
    }
    m[n]=q;
    sequ++;
    return q;
}

int dpBottomUp(int *p,int *s,int n) //自底向上的动态规划方法,无需递归,直接抓本质，直接从下到上回归，就无须递的过程了
{
    int sequ=0;
    int *m=new int[n];
    m[0]=0;
    for(int i=1;i<=n;i++)
    {
        int q=-1;
        for(int j=1;j<=i;++j)
        {
            int temp=q;
            q=max(q,p[j]+m[i-j]);
            if(q!=temp) s[sequ]=j;
        }
        sequ++;
        m[i]=q;
    }
    return m[n];
}
