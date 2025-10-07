//筛选法又称筛法，是求不超过自然数N（N>1）的所有质数的一种方法。
//据说是古希腊的埃拉托斯特尼（Eratosthenes，约公元前274～194年） 发明的，又称埃拉托斯特尼筛子。
//具体做法是：先把N个自然数按次序排列起来。1不是质数，也不是合数，要划去。第二个数2是质数留下来，
//而把2后面所有能被2整除的数都划去。2后面第一个没划去的数是3，把3留下，再把3后面所有能被3整除的数都划去。
//3后面第一个没划去的数是5，把5留下，再把5后面所有能被5整除的数都划去。这样一直做下去，
//就会把不超过N的全部合数都筛掉，留下的就是不超过N的全部质数。
//因为希腊人是把数写在涂腊的板上，每要划去一个数，就在上面记以小点，寻求质数的工作完毕后，
//这许多小点就像一个筛子，所以就把埃拉托斯特尼的方法叫做“埃拉托斯特尼筛”，简称“筛法”。
//另一种解释是当时的数写在纸草上，每要划去一个数，就把这个数挖去 ，寻求质数的工作完毕后，这许多小洞就像一个筛子。

//用动态申请空间和位操作实现(较复杂)
#include <stdio.h>
#include <math.h>
#include <stdlib.h> //malloc
#include <string.h> //memset

//unsigned int的位数
const unsigned int intBitNum=sizeof(unsigned int)*8;

//统计这个整数里面有多少位是1（也就是有多少个是素数）
int count(unsigned int n) {
  int cnt=0;
  for (unsigned int x=n;x;x>>=1) {
    if (x&1) cnt++;
  }
  return cnt;
}

//素数的筛选
void sieve(unsigned int *p,unsigned int n) {
  //筛选只要做到n的平方根就足够！
  for (unsigned int i=2,k=(unsigned)sqrt(n);i<=k;i++) {
    if (p[i/intBitNum]&(1<<i%intBitNum)) //如果第i个整数是素数
      //将后面所有第i个整数的倍数置为合数
      for (unsigned int j=i*i;j<n;j+=i)
        p[j/intBitNum]&=~(1<<j%intBitNum); //将对应的整数位置位为0
  }
  return;
}

int main() {
  unsigned int n;
  scanf("%u",&n);
  n++;    //区间包含n

  unsigned int m;
  m=n/intBitNum; 
  if (n%intBitNum) m++;
 
  //从系统堆栈申请所需的空间
  unsigned int *p=(unsigned int *)malloc(m*sizeof(unsigned int));
  if (p==NULL) { //空间申请失败！
    printf("No enough memory.\n");
    return -1;
  }
  
  //所有位全部置为1
  memset(p,0xffU,m*sizeof(unsigned int));
 
  sieve(p,n); //进行素数的筛选
  
  //累加素数的个数
  unsigned int cnt=0;
  for (unsigned int i=0;i<m;i++) cnt+=count(p[i]);
  
  if (n%intBitNum) 
    cnt-=(m*intBitNum-n); //多分配的空间，必须扣除！
  printf("%d\n",cnt-2);   //0和1不是素数，必须扣除！
  
  free(p);  //释放前面申请的空间！
  
  return 0;
}


/*************************************************************
//程序输出结果形如：
//区间2～100000000共有5761455个素数。程序运行时间2.371000秒。
//
//而用直接判别方法统计区间素数个数的程序输出结果形如：
//区间2～100000000共有5761455个素数。程序运行时间82.321000秒。
**************************************************************/
