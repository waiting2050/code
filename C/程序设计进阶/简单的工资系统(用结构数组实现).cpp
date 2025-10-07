/***********************************************************************************************************
//开发一个简单的工资系统：
//   1)输入、显示工资信息(包括：员工号—字符串、姓名、性别、出生日期、岗位工资、补贴总额、代扣总额)；
//   2)输出应发工资(总额)的最高、最低和平均值；
//   3)按员工号排序后输出信息；
//   4)按员工号查找并输出其信息，也可删除查到的员工。
//要求:
//   1)具有良好的风格和简单的界面；
//   2)利用函数来实现各模块；
//   3)用结构数组实现。
//程序仍然存在的问题：用户不按要求的数据格式(数据顺序、类型和长度等)输入数据会导致程序出现不可预料的错误。
//编写者：王灿辉，编写时间：2010-12-26
//版本及维护信息：略
************************************************************************************************************/

#include <stdio.h>
#include <string.h>   //strchr,strcmp,strcpy等函数需要
#include <conio.h>    //getch函数需要
#include <ctype.h>    //toupper,isdigit,isascii等函数（宏）需要
#include <stdlib.h>   //exit,atoi等函数需要
#include <time.h>     //time,localtime等函数需要

//#define DEBUG       //调试状态开关

#define FILE_NAME "g:\\temp\\Employee.dat"  //存放员工信息的文件名

#define NO_LEN 4          //员工号长度
#define NAME_LEN 8        //姓名长度
#define NUM 5000          //最大员工数
#define S_NUM 40          //选择菜单表头的星号数目
#define MAX_MENU 255      //功能选择菜单的最大行数
#define E_NUM 72          //输出员工信息表头等号的数目
#define YMD_LEN 10        //形如'2010-12-31'的日期字符串的最大长度
#define MAX_SALARY 99999  //岗位工资、补贴总额、代扣总额等允许的最大值
#define MIN_AGE 17        //可以参加工作的最小年龄
#define MAX_AGE 65        //可以参加工作的最大年龄

//定义性别(枚举)类型
enum SexType {female,male};

//定义出生日期(结构)类型
typedef struct BirthdayType {
  int year,month,day;     //出生日期的年、月、日
} Birthday;

//员工工资结构(类型)的定义。必须放在前面，因为后面的函数原型都要用到。
struct EmpType {
  char no[NO_LEN+1];      //员工号(一般情况下均为字符串，不能设为int类型)
  char name[NAME_LEN+1];  //姓名(不能设为和员工号相同的长度，不合理) 
  enum SexType sex;       //性别
  Birthday birthday;      //出生日期
  double gwgz;            //岗位工资(可以用拼音命名，但必须有中文注解，这也很常用)
  double btze;            //补贴总额
  double dkze;            //代扣总额
  double yfgz;            //应发工资(总额)=岗位工资+补贴总额-代扣总额
};
//不能在这里直接声明“存放员工工资信息的数组”，否则该数组将成为全局变量(数组)，这是不好的编程方法。
//也可以写成：double gwgz,btze,dkze,yfgz;但这样对写注解不利。甚至可以写成：double salary[4]; 但同样不好。
//如果将char no[NO_LEN+1];定义成char *no;可以吗？如果不可以存在什么问题？

//读入员工信息文件中的数据并将其存入结构数组e，文件不存在则自动建立。
//参数n存放允许的最大员工数。返回读入的员工数
int readFromFile(struct EmpType e[],int n);
//显示表头的n个字符(ch)(inline:内联函数，加快运行速度)
inline void show_table_head(int n,char ch);
//显示系统当前日期和时间
void show_time(void);
//返回系统当前日期的年份值
int get_cur_year(void);
//显示功能选择菜单
//入口参数：存放允许用户选择的所有(大写)字符，格式形如：“A,B,C,D,Q”
void show_menu(char *);
//获得用户的选择，返回值：用户按下的字符(大写)
char get_choice(void);
//跳过本行剩余的其他字符和<回车>键
inline void eatline(void);
//将形如'2010-12-31'的日期字符串分解为年月日存入出生日期结构(类型)并返回该结构
//使用const(不可修改)限定符，以避免对入口参数字符串的无意修改
Birthday brkYMD(const char *ymd);
//获得指定年、月对应的天数
int getDaynumOfMonth(int year,int month);
//确认员工工资信息数组e中第n个员工的员工号是否合法？
//合法返回true，不合法返回false
bool isValidNo(struct EmpType e[],int n);
//确认员工工资信息数组e中第n个员工的工资信息是否合法？
//数据合法返回true，数据不合法返回false
bool isValidData(struct EmpType e[],int n);
//将员工工资信息数组e中第n个员工的工资信息存入员工信息文件中。
void writeToFile(FILE *fp,struct EmpType e[],int n);
//输入员工工资信息至结构数组e，当前已经输入的员工数为i
//返回加上本次输入后当前已经输入的员工总数(<=NUM)
int input(struct EmpType e[],int n);
//输出员工工资信息数组e中第n个员工的工资信息。
inline void output_one(struct EmpType e[],int n);
//输出员工工资信息。入口参数：员工工资信息数组e，员工数n
void output(struct EmpType e[],int n);
//输出员工工资统计信息。入口参数：员工工资信息数组e，员工数n
void calc(struct EmpType e[],int n);
//按照order的值('A':升序,'D':降序)比较员工号，返回true或false
bool cmp_no(struct EmpType e[],int n,char order);
//按照order的值('A':升序,'D':降序)比较员工的姓名，返回true或false
bool cmp_name(struct EmpType e[],int n,char order);
//按照order的值('A':升序,'D':降序)比较员工的性别，返回true或false
bool cmp_sex(struct EmpType e[],int n,char order);
//按照order的值('A':升序,'D':降序)比较员工的年龄，返回true或false
bool cmp_day(struct EmpType e[],int n,char order);
//按照order的值('A':升序,'D':降序)比较员工的应发工资，返回true或false
bool cmp_salary(struct EmpType e[],int n,char order);
//按员工号等进行排序(冒泡排序)。
//入口参数：员工工资信息数组e，员工数n，cmp比较函数的函数指针，order('A':升序,'D':降序)
void sort(struct EmpType e[],int n,bool (*cmp)(struct EmpType [],int,char),char order);
//显示排序选择菜单
void show_sort_menu(void);
//按员工号等进行排序(冒泡排序)。入口参数：员工工资信息数组e，员工数n
void sort_all(struct EmpType e[],int n);
//返回员工号no对应的下标，不存在返回-1
//入口参数：员工工资信息数组e，员工数n，no待查找的员工号
int get_index(struct EmpType e[],int n,const char *no);
//按员工号进行查找。入口参数：员工工资信息数组e，员工数n
void search(struct EmpType e[],int n);
//按员工号删除员工信息。返回删除后剩下员工的总数
//入口参数：员工工资信息数组e，员工数n
int delete_emp(struct EmpType e[],int n);
//用结构数组的当前员工信息更新文件中原有的数据
void flushFile(struct EmpType e[],int n);

//输出表头的信息
#define output_table_head \
printf("%6s%-9s%-5s%11s%10s%10s%10s%10s\n","员工号"," 姓名","性别","出生日期","岗位工资","补贴总额","代扣总额","应发工资")
//输出员工的信息：员工号、姓名、性别
#define output_no_name_sex(fp,emp,index) \
fprintf(fp,"%-6s%-9s%-5s",emp[index].no,emp[index].name,(emp[index].sex==male?"男":"女"))
//输出出生日期
#define output_birthday(fp,bd) fprintf(fp," %4d.%02d.%02d",bd.year,bd.month,bd.day);
//输出员工的信息：岗位工资、补贴总额、代扣总额、应发工资(总额)
#define output_salary(fp,emp,index) \
fprintf(fp,"%10.2lf%10.2lf%10.2lf%10.2lf\n",emp[index].gwgz,emp[index].btze,emp[index].dkze,emp[index].yfgz)

int main() {
  struct EmpType emp[NUM];  //存放员工工资信息的数组
  //结构(大)数组很容易导致堆栈溢出，解决办法：修改IDE的配置，或者改为static数组。
  int eNum=0;               //当前已经输入的员工总数(最好不要定义成全局变量)
  char choice;              //用户按下的字符(大写)
  
  eNum=readFromFile(emp,NUM);    //读入员工信息文件中的数据
  
  while ((choice=get_choice())!='Q') {
    if (choice!='I'&&!eNum) {
      printf("\a\n还没有员工信息，不能使用该功能，请先输入员工信息！\n\n");
      continue;
    }
    switch (choice) {
    case 'I':
      eNum=input(emp,eNum);       //输入员工工资信息
      if (eNum) output(emp,eNum); //输出员工工资信息
      break;
    case 'O':
      output(emp,eNum);           //输出员工工资信息
      break;
    case 'T':
      calc(emp,eNum);             //输出员工工资统计信息
      break;
    case 'S':
      sort_all(emp,eNum);         //按员工号等进行排序
      output(emp,eNum);           //输出员工工资信息
      break;
    case 'F':
      search(emp,eNum);           //按员工号进行查找
      break;
    case 'D':
      eNum=delete_emp(emp,eNum);  //删除员工信息
      flushFile(emp,eNum);        //将修改后的员工信息写入文件
      break;
    }
  }
}

//用结构数组的当前员工信息更新文件中原有的数据
void flushFile(struct EmpType e[],int n) {
  FILE *fp=fopen(FILE_NAME,"w");
  //改写打开员工信息文件，此时不继续判断是否打开失败，除非很特殊的情况才会出问题。
  for (int i=0;i<n;i++)
    writeToFile(fp,e,i);   //将员工工资信息数组e中第i个员工的工资信息存入员工信息文件中
  fclose(fp);
}

//读入员工信息文件中的数据并将其存入结构数组e，文件不存在则自动建立。
//参数n存放允许的最大员工数。返回读入的员工数
int readFromFile(struct EmpType e[],int n) {
  int i=0;      //读入的员工数
  char sex[3];  //保存性别(男或女)
  
  FILE *fp;
  if ((fp=fopen(FILE_NAME,"a+"))==NULL) {
    fprintf(stderr,"\a\n打开员工信息文件:%s出错！\n\n",FILE_NAME);
    exit(-1);
  }
  
  //由于只能通过程序本身提供的功能保存数据，所以不需要对数据的完整性等再次进行检验。
  while(i<NUM && fscanf(fp,"%s%s%s",e[i].no,e[i].name,sex)==3) {
    fscanf(fp,"%4d.%2d.%2d",&e[i].birthday.year,&e[i].birthday.month,&e[i].birthday.day);
    fscanf(fp,"%lf%lf%lf%lf",&e[i].gwgz,&e[i].btze,&e[i].dkze,&e[i].yfgz);
    if (!strcmp(sex,"男")) e[i].sex=male;
    else                   e[i].sex=female;
    
#ifdef DEBUG
    output_one(e,i);
#endif
    
    i++;
  }
  
  if (fclose(fp)) {
    fprintf(stderr,"\a\n关闭员工信息文件:%s出错！\n\n",FILE_NAME);
    exit(-2);
  }
  
  return i;
}

/**********************************************************
//显示表头的n个字符(ch)
//用递归函数实现(仅用于演示递归函数，实际不这么使用)
void show_table_head(int n,char ch) {
  if (n<1) return;
  putchar(ch); 
  if (n==1) putchar('\n');
  if (n>1) show_table_head(n-1,ch);
}
***********************************************************/
//显示表头的n个字符(ch)(inline:内联函数，加快运行速度)
inline void show_table_head(int n,char ch) {
if (n<1) return;
for (int i=0;i<n;i++)
putchar(ch); 
putchar('\n');
}

//显示系统当前日期和时间
void show_time(void) {
  struct tm *local;
  long long t;
  static char wday[][3]={"日","一","二","三","四","五","六"};
  
  time(&t);
  local = localtime(&t);  //返回结构指针
  
  printf("现在是: %d.%02d.%02d(星期%s) ",local->tm_year+1900,++local->tm_mon,local->tm_mday,wday[local->tm_wday]);
  printf(" %02d:%02d:%02d\n",local->tm_hour,local->tm_min,local->tm_sec);
} 
/****************************************************************************************************************************
struct tm {
int tm_sec;   //秒 - 取值区间为[0,59]
int tm_min;   //分 - 取值区间为[0,59] 
int tm_hour;  //时 - 取值区间为[0,23] 
int tm_mday;  //一个月中的日期 - 取值区间为[1,31]
int tm_mon;   //月份（从一月开始，0代表一月） - 取值区间为[0,11]
int tm_year;  //年份，其值等于实际年份减去1900
int tm_wday;  //星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推
int tm_yday;  //从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推
int tm_isdst; //夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。
}; 
*****************************************************************************************************************************/

//返回系统当前日期的年份值
int get_cur_year(void) {
  struct tm *local;
  long long t;
  time(&t);
  local = localtime(&t);
  return (local->tm_year+1900);
}

//显示功能选择菜单
//入口参数：存放允许用户选择的所有(大写)字符，格式形如：“A,B,C,D,Q”
void show_menu(char *select_str) {
  //存放功能选择菜单，要求：每行的第一个字符必须为选择字符，最后一行一般是“Q:退出系统”！
  const static char *menu[]={
      "I:输入员工工资信息",
      "O:输出员工工资信息",
      "T:输出员工工资统计信息",
      "S:按员工号等排序后输出员工工资信息",
      "F:按员工号查找并输出其工资信息",
      "D:按员工号查找并删除其工资信息",
      "Q:退出系统"
  };
  
  show_table_head(S_NUM,'*');   //显示E_NUM个'*'
  int j;
  for (int i=0,j=0;i<sizeof(menu)/sizeof(menu[0]);i++) {
    printf("%-4s%-*s*\n","*",S_NUM-5,menu[i]);
    if (i>0) select_str[j++]=',';
    select_str[j++]=toupper(menu[i][0]);
  }
  select_str[j++]='\0';
  
  show_table_head(S_NUM,'*');   //显示E_NUM个'*'
  
  printf("请选择(%s):",select_str);
}

//获得用户的选择，返回值：用户按下的字符(大写)
char get_choice(void) {
  char select_str[MAX_MENU*2];
  //存放允许用户选择的所有(大写)字符，格式形如：“A,B,C,D,Q”
  char choice;
  while (1) {
    show_menu(select_str);        //显示功能选择菜单
    choice=toupper(getch());      //非缓冲无回显输入
    putchar(choice);              //回显刚输入的字符
    //下述语句可以基本实现和前面2行语句相同的功能
    //choice=toupper(getche());   //非缓冲有回显输入
    putchar('\n');
    if (strchr(select_str,choice)&&choice!=',') break;
    printf("\a\n选择错误，请重新选择......\n\n");
  }
  return choice;
}

//跳过本行剩余的其他字符和<回车>键
inline void eatline(void) {
  while (getchar()!='\n')
    continue;
}

//将形如'2010-12-31'的日期字符串分解为年月日存入出生日期结构(类型)并返回该结构
Birthday brkYMD(const char *ymd) {
  char *p=strchr(ymd,'-');  //存放第1个'-'的位置
  char *q=strchr(p+1,'-');  //存放第2个'-'的位置
  
  //分解为年月日存入变量y、m、d
  char y[YMD_LEN+1],m[YMD_LEN+1],d[YMD_LEN+1];  //存放年月日的字符串
  strcpy(y,ymd);  y[p-ymd]='\0';
  strcpy(m,p+1);  m[q-p-1]='\0';
  strcpy(d,q+1);
  
  //转化为整型并存入结构中
  Birthday tmp;
  tmp.year=atoi(y);
  tmp.month=atoi(m);
  tmp.day=atoi(d);
  
  return tmp;
}

//确认员工工资信息数组e中第n个员工的员工号是否合法？
//合法返回true，不合法返回false
bool isValidNo(struct EmpType e[],int n) {
  //员工号是员工信息的唯一标识，不允许重复。
  //员工号格式规定：{1--9}+{0--9}+{0--9}+{0--9}+......
  //即：第1位为1--9之间的数字，后面的字符可以是任意数字
  if (strlen(e[n].no)!=NO_LEN) {
    printf("\n员工号\"%s\"长度必须为：%d！\n",e[n].no,NO_LEN);
    return false;
  }
  unsigned int i;
  for (i=0;i<(unsigned int)n;i++) {
    if (!strcmp(e[i].no,e[n].no)) {
      printf("\n员工号是员工信息的唯一标识，不允许重复！员工号\"%s\"已经存在。\n",e[n].no);
      return false;
    }
  }
  if (!isdigit(e[n].no[0]) || e[n].no[0]=='0') {
    printf("\n员工号第1位必须为1--9之间的数字！\n");
    return false;
  }
  for (i=1;i<strlen(e[n].no);i++)
    if (!isdigit(e[n].no[i])) {
      printf("\n员工号从第2位开始必须为0--9之间的数字！\n");
      return false;
    }
    return true;
}

//获得指定年、月对应的天数
int getDaynumOfMonth(int year,int month) {
  int day_num[]={31,-1,31,30,31,30,31,31,30,31,30,31};
  if (month<1 || month>12) return -1;
  if (month!=2)  return day_num[month-1];
  else return ((year%4==0 && year%100!=0)||(year%400==0)?29:28);
}

//确认员工工资信息数组e中第n个员工的工资信息是否合法？
//数据合法返回true，数据不合法返回false
bool isValidData(struct EmpType e[],int n) {
  
  if (!isValidNo(e,n)) return false;    //员工号有误
  
  for (unsigned int i=0;i<strlen(e[n].name);i++){
    if (isascii(e[n].name[i])) {
      printf("\n员工姓名必须都是汉字！\n");
      return false;
    }
  }
  if (strlen(e[n].name)<4) {
    printf("\n姓名必须是2个以上的汉字！\n");
    return false;
  }
  
  //对出生日期只进行比较简单的检验
  if (e[n].birthday.month<1 || e[n].birthday.month>12) {
    printf("\n出生日期的月份错误，只能在1--12之间！\n");
    return false;
  }
  int days=getDaynumOfMonth(e[n].birthday.year,e[n].birthday.month);
  if (e[n].birthday.day>days) {
    printf("\n出生日期的日期错误，%d年%d月只有%d天！\n",e[n].birthday.year,e[n].birthday.month,days);
    return false;
  }
  int age=get_cur_year()-e[n].birthday.year;  //计算年龄
  if (age<MIN_AGE || age>MAX_AGE) {           //不考虑男女退休年龄的区别等
    printf("\n年龄(%d)应该在%d---%d之间！\n",age,MIN_AGE,MAX_AGE);
    return false;
  }
  
  if (e[n].gwgz<=0 || e[n].gwgz>MAX_SALARY) {
    printf("\n岗位工资有误，值应该大于0，不大于%d！\n",MAX_SALARY);
    return false;
  }
  if (e[n].btze<=0 || e[n].btze>MAX_SALARY) {
    printf("\n补贴总额有误，值应该大于0，不大于%d！\n",MAX_SALARY);
    return false;
  }
  if (e[n].dkze<=0 || e[n].dkze>MAX_SALARY) {
    printf("\n代扣总额有误，值应该大于0，不大于%d！\n",MAX_SALARY);
    return false;
  }
  
  return true;
}

//将员工工资信息数组e中第n个员工的工资信息存入员工信息文件中。
void writeToFile(FILE *fp,struct EmpType e[],int n) {
  output_no_name_sex(fp,e,n);
  output_birthday(fp,e[n].birthday);
  output_salary(fp,e,n);
}

//输入员工工资信息至结构数组e，当前已经输入的员工数为i
//返回加上本次输入后当前已经输入的员工总数(<=NUM)
int input(struct EmpType e[],int i) {
  char sex[3];            //保存性别(男或女)
  char str_bd[YMD_LEN+1]; //保存出生日期的字符串
  bool isValidSex=true;   //性别是否合法的标志
  
  FILE *fp=fopen(FILE_NAME,"a+");
  //打开员工信息文件，此时不继续判断是否打开失败，除非很特殊的情况才会出问题。
  
  printf("\n请输入不超过%d名员工的\n员工号、姓名、性别、出生日期、岗位工资、补贴总额、代扣总额。\n\n",NUM-i);
  printf("在行首按<Ctrl>+Z、<回车>和<回车>结束输入！\n");
  
  while (i<NUM && scanf("%s%s%s%s%lf%lf%lf",e[i].no,e[i].name,sex,str_bd,&e[i].gwgz,&e[i].btze,&e[i].dkze)==7) {
    e[i].birthday=brkYMD(str_bd);
    e[i].yfgz=e[i].gwgz+e[i].btze-e[i].dkze;    //计算应发工资
    
#ifdef DEBUG
    output_one(e,i);
#endif
    
    if (!strcmp(sex,"男"))
      e[i].sex=male;
    else if (!strcmp(sex,"女")) 
      e[i].sex=female;
    else {
      isValidSex=false;
      printf("\a\n性别只能是\"男\"或\"女\"！\n");
    }
    if (isValidSex && isValidData(e,i)) {
      writeToFile(fp,e,i);   //将员工工资信息数组e中第i个员工的工资信息存入员工信息文件中
      i++;                   //刚输入的员工数据合法，当前已经输入的员工总数+1
    }
    else 
      printf("\a刚输入的员工数据有错，数据没有被保存！\n\n");
  }
  eatline();    //跳过本行剩余的其他字符和<回车>键
  
#ifdef DEBUG
  printf("当前已经输入的员工总数为：%d\n\n",i);
#endif
  
  fclose(fp);   //关闭员工信息文件，同样不做错误判断。
  return i;
}

//输出员工工资信息数组e中第n个员工的工资信息。
inline void output_one(struct EmpType e[],int n) {
  output_no_name_sex(stdout,e,n);
  output_birthday(stdout,e[n].birthday);
  output_salary(stdout,e,n);
}

//输出员工工资信息。入口参数：员工工资信息数组e，员工数n
void output(struct EmpType e[],int n) {
  printf("\n现有员工总数为：%d\n\n",n);
  output_table_head;
  show_table_head(E_NUM,'=');   //输出E_NUM个'='
  for(int i=0;i<n;i++) {
    output_one(e,i);
  }
  show_table_head(E_NUM,'=');   //输出E_NUM个'='
  putchar('\n');
}

//输出员工工资统计信息。入口参数：员工工资信息数组e，员工数n
void calc(struct EmpType e[],int n) {
  double sum=0,sum_male=0,sum_female=0;
  //所有员工应发工资总额，男性员工应发工资总额，女性员工应发工资总额
  double max,min;           //应发工资的最高和最低
  int c_male=0,c_female=0;  //存放男、女性员工的人数
  max=min=e[0].yfgz;
  for(int i=0;i<n;i++) {
    if (max<e[i].yfgz) max=e[i].yfgz;
    if (min>e[i].yfgz) min=e[i].yfgz;
    sum+=e[i].yfgz;
    if (e[i].sex==male) {
      sum_male+=e[i].yfgz;
      c_male++;
    }
    else {
      sum_female+=e[i].yfgz;
      c_female++;
    }
  }
  printf("\n应发工资最高为：%.2lf，最低为：%.2lf，所有员工应发工资总额为：%.2lf\n",max,min,sum);
  printf("\n男性员工人数为：%d，女性员工人数为：%d\n",c_male,c_female);
  printf("\n应发工资平均值为：%.2lf(其中：男性平均值为：%.2lf，女性平均值为：%.2lf)\n\n",sum/n,sum_male/c_male,sum_female/c_female);
}

//按照order的值('A':升序,'D':降序)比较员工号，返回true或false
bool cmp_no(struct EmpType e[],int n,char order) {
  if (order=='A'&& strcmp(e[n].no,e[n+1].no)>0) return true;
  if (order=='D'&& strcmp(e[n].no,e[n+1].no)<0) return true;
  return false;
}

//按照order的值('A':升序,'D':降序)比较员工的姓名，返回true或false
bool cmp_name(struct EmpType e[],int n,char order) {
  if (order=='A'&& strcmp(e[n].name,e[n+1].name)>0) return true;
  if (order=='D'&& strcmp(e[n].name,e[n+1].name)<0) return true;
  return false;
}

//按照order的值('A':升序,'D':降序)比较员工的性别，返回true或false
bool cmp_sex(struct EmpType e[],int n,char order) {
  if (order=='A'&& e[n].sex>e[n+1].sex) return true;
  if (order=='D'&& e[n].sex<e[n+1].sex) return true;
  return false;
}

//按照order的值('A':升序,'D':降序)比较员工的年龄，返回true或false
bool cmp_day(struct EmpType e[],int n,char order) {
  if (order=='A'){
    if (e[n].birthday.year<e[n+1].birthday.year) return true;
    if (e[n].birthday.year==e[n+1].birthday.year && e[n].birthday.month<e[n+1].birthday.month) return true;
    if (e[n].birthday.year==e[n+1].birthday.year && e[n].birthday.month==e[n+1].birthday.month &&
      e[n].birthday.day<e[n+1].birthday.day) return true;
  }
  if (order=='D') {
    if (e[n].birthday.year>e[n+1].birthday.year) return true;
    if (e[n].birthday.year==e[n+1].birthday.year && e[n].birthday.month>e[n+1].birthday.month) return true;
    if (e[n].birthday.year==e[n+1].birthday.year && e[n].birthday.month==e[n+1].birthday.month &&
      e[n].birthday.day<e[n+1].birthday.day) return true;
  }
  return false;
}

//按照order的值('A':升序,'D':降序)比较员工的应发工资，返回true或false
bool cmp_salary(struct EmpType e[],int n,char order) {
  if (order=='A'&& e[n].yfgz>e[n+1].yfgz) return true;
  if (order=='D'&& e[n].yfgz<e[n+1].yfgz) return true;
  return false;
}

//按员工号等进行排序(冒泡排序)。
//入口参数：员工工资信息数组e，员工数n，cmp比较函数的函数指针，order('A':升序,'D':降序)
void sort(struct EmpType e[],int n,bool (*cmp)(struct EmpType [],int,char),char order) {
  for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++) {
      if (cmp(e,j,order)) {
        //交换e[j]和e[j+1]
        struct EmpType tmp=e[j];
        e[j]=e[j+1];
        e[j+1]=tmp;
      }
    }
}

//显示排序选择菜单
void show_sort_menu(void) {
  printf("\n      排序方式选择菜单\n");
  printf("================================\n");
  printf("1:按员工号从小到大排序\n");
  printf("2:按员工号从大到小排序\n");
  printf("3:按员工姓名排序\n");
  printf("4:按员工性别排序\n");
  printf("5:按员工年龄从小到大排序\n");
  printf("6:按员工年龄从大到小排序\n");
  printf("7:按员工应发工资从小到大排序\n");
  printf("8:按员工应发工资从大到小排序\n");
  printf("q:不排序退出\n");
  printf("================================\n");
  printf("请选择(1--8和q)：");
}

//按员工号等进行排序(使用最简单的冒泡排序)。入口参数：员工工资信息数组e，员工数n
void sort_all(struct EmpType e[],int n) {
  show_sort_menu();
  char choice=getche(); //无缓冲有回显，非标准的库函数
  putchar('\n');
  switch (choice) {
  case '1':sort(e,n,cmp_no,'A');break;
  case '2':sort(e,n,cmp_no,'D');break;
  case '3':sort(e,n,cmp_name,'A');break;
  case '4':sort(e,n,cmp_sex,'A');break;
  case '5':sort(e,n,cmp_day,'A');break;
  case '6':sort(e,n,cmp_day,'D');break;
  case '7':sort(e,n,cmp_salary,'A');break;
  case '8':sort(e,n,cmp_salary,'D');break;
  default:break;
  }
}

//返回员工号no对应的下标，不存在返回-1
//入口参数：员工工资信息数组e，员工数n，no待查找的员工号
int get_index(struct EmpType e[],int n,const char *no) {
  int index=-1;
  for(int i=0;i<n;i++) {
    if (!strcmp(e[i].no,no)) {
      index=i;
      break;
    }
  }
  return index;
}

//按员工号进行查找。入口参数：员工工资信息数组e，员工数n
void search(struct EmpType e[],int n) {
  char no[NO_LEN+1];   //存放待查找的员工号
  
  printf("\n请输入待查询的员工号：");
  fgets(no,NO_LEN+1,stdin);
  eatline();
  int k=get_index(e,n,no);   //返回员工号no对应的下标，不存在返回-1
  
  if (k==-1)
    printf("员工[%s]不存在！\n\n",no);
  else {
    output_table_head;
    output_one(e,k);
    putchar('\n');
  }  
}

//按员工号删除员工信息。返回删除后剩下员工的总数
//入口参数：员工工资信息数组e，员工数n
int delete_emp(struct EmpType e[],int n) {
  char no[NO_LEN+1];    //存放要删除的员工号
  
  printf("\n请输入要删除的员工号："); 
  fgets(no,NO_LEN+1,stdin);
  eatline();
  int k=get_index(e,NUM,no);   //返回员工号no对应的下标，不存在返回-1
  
  if (k==-1) {
    printf("员工[%s]不存在！\n\n",no);
    return n;
  }
  //交换第k个和第n-1个员工的信息
  struct EmpType t=e[k];
  e[k]=e[n-1];
  e[n-1]=t;
  printf("员工[%s]已经被成功删除！\n\n",no);
  return n-1;
}

/*****************************************************************
1、用于测试的合法数据如下：
员工号、姓名、性别、出生日期、岗位工资、补贴总额、代扣总额
1010	伍惺委	男	1990-10-20	3220	1500	300
1011	张艳亲	女	1989-12-9	3530	1800	400
1012	沈民涌	男	1978-11-22	2540	1300	250
1013	颜衍圈	男	1965-10-31	3400	1200	180
1014	王恳呛	男	1979-5-4	4780	2000	450
1006	林指愤	男	1991-1-2	3009	1500	300
1007	潘介馏	男	1964-2-28	3520	1800	400
1008	曾院借	男	1973-3-27	2300	1300	250
1009	陈渝	男	1967-5-28	3340	1200	180
1001	杨玲	女	1966-7-7	3755	2000	450
1002	沈慕泉	男	1981-4-30	3011	1500	300
1003	谢蜂蜂	男	1984-6-30	3598	1800	400
1004	傅消惯	男	1985-2-10	2506	1300	250
1005	倪轻趣	男	1970-8-2	3243	1200	180
1015	杨溏	男	1992-11-3	4708	2000	450
1016	吕袥疫	男	1955-9-4	3060	1500	300
1017	陈馏	女	1962-6-5	2588	1200	400
1018	何猜跃	男	1986-3-16	2595	1300	250
1019	何既位	男	1977-4-11	3760	1200	180
1020	何庆林	男	1962-11-8	4670	2000	450
1021	李点	男	1984-6-9	3878	1500	300
1022	吴温猎	男	1985-11-11	3333	1800	400
1023	左瘟擒	女	1988-9-30	2566	1300	250
1024	黄城河	男	1991-6-12	3222	1200	180
1025	李者訚	男	1990-5-13	4777	2000	450
先选中所有的测试数据并“复制”，然后出现运行窗口
时单击左上角，选“编辑”的“粘贴”可以直接输入
2、用于测试数据检验功能的测试数据如下：
1005	李者訚	男	1990-5-13	4700	2000	450
0010	伍惺委	男	1990-10-20	3000	1500	300
101X	伍惺委	男	1990-10-20	3000	1500	300
1055	李逵	难	1990-5-13	4700	2000	450
1088	李1234	男	1990-5-13	4700	2000	450
1088	李逵	男	1990-15-13	4700	2000	450
1088	李逵	男	1990-5-32	4700	2000	450
1088	李逵	男	1990-5-3	1000000	2000	450
1088	李逵	男	1990-5-3	2000	1000000	450
1088	李逵	男	1990-5-3	2000	450	1000000
1088	李逵	男	1990-11-13	-4700	2000	450
1088	李逵	男	1990-11-13	4700	-2000	450
1088	李逵	男	1990-11-13	4700	2000	0
1088	李逵	男	1995-5-3	4700	2000	450
1088	李逵	男	1940-5-3	4700	2000	450
108 	李逵	男	1980-5-3	4700	2000	450
1088	李  	男	1990-5-13	4700	2000	450
******************************************************************/
