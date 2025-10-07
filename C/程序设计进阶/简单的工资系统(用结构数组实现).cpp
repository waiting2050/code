/***********************************************************************************************************
//����һ���򵥵Ĺ���ϵͳ��
//   1)���롢��ʾ������Ϣ(������Ա���š��ַ������������Ա𡢳������ڡ���λ���ʡ������ܶ�����ܶ�)��
//   2)���Ӧ������(�ܶ�)����ߡ���ͺ�ƽ��ֵ��
//   3)��Ա��������������Ϣ��
//   4)��Ա���Ų��Ҳ��������Ϣ��Ҳ��ɾ���鵽��Ա����
//Ҫ��:
//   1)�������õķ��ͼ򵥵Ľ��棻
//   2)���ú�����ʵ�ָ�ģ�飻
//   3)�ýṹ����ʵ�֡�
//������Ȼ���ڵ����⣺�û�����Ҫ������ݸ�ʽ(����˳�����ͺͳ��ȵ�)�������ݻᵼ�³�����ֲ���Ԥ�ϵĴ���
//��д�ߣ����ӻԣ���дʱ�䣺2010-12-26
//�汾��ά����Ϣ����
************************************************************************************************************/

#include <stdio.h>
#include <string.h>   //strchr,strcmp,strcpy�Ⱥ�����Ҫ
#include <conio.h>    //getch������Ҫ
#include <ctype.h>    //toupper,isdigit,isascii�Ⱥ������꣩��Ҫ
#include <stdlib.h>   //exit,atoi�Ⱥ�����Ҫ
#include <time.h>     //time,localtime�Ⱥ�����Ҫ

//#define DEBUG       //����״̬����

#define FILE_NAME "g:\\temp\\Employee.dat"  //���Ա����Ϣ���ļ���

#define NO_LEN 4          //Ա���ų���
#define NAME_LEN 8        //��������
#define NUM 5000          //���Ա����
#define S_NUM 40          //ѡ��˵���ͷ���Ǻ���Ŀ
#define MAX_MENU 255      //����ѡ��˵����������
#define E_NUM 72          //���Ա����Ϣ��ͷ�Ⱥŵ���Ŀ
#define YMD_LEN 10        //����'2010-12-31'�������ַ�������󳤶�
#define MAX_SALARY 99999  //��λ���ʡ������ܶ�����ܶ����������ֵ
#define MIN_AGE 17        //���Բμӹ�������С����
#define MAX_AGE 65        //���Բμӹ������������

//�����Ա�(ö��)����
enum SexType {female,male};

//�����������(�ṹ)����
typedef struct BirthdayType {
  int year,month,day;     //�������ڵ��ꡢ�¡���
} Birthday;

//Ա�����ʽṹ(����)�Ķ��塣�������ǰ�棬��Ϊ����ĺ���ԭ�Ͷ�Ҫ�õ���
struct EmpType {
  char no[NO_LEN+1];      //Ա����(һ������¾�Ϊ�ַ�����������Ϊint����)
  char name[NAME_LEN+1];  //����(������Ϊ��Ա������ͬ�ĳ��ȣ�������) 
  enum SexType sex;       //�Ա�
  Birthday birthday;      //��������
  double gwgz;            //��λ����(������ƴ��������������������ע�⣬��Ҳ�ܳ���)
  double btze;            //�����ܶ�
  double dkze;            //�����ܶ�
  double yfgz;            //Ӧ������(�ܶ�)=��λ����+�����ܶ�-�����ܶ�
};
//����������ֱ�����������Ա��������Ϣ�����顱����������齫��Ϊȫ�ֱ���(����)�����ǲ��õı�̷�����
//Ҳ����д�ɣ�double gwgz,btze,dkze,yfgz;��������дע�ⲻ������������д�ɣ�double salary[4]; ��ͬ�����á�
//�����char no[NO_LEN+1];�����char *no;��������������Դ���ʲô���⣿

//����Ա����Ϣ�ļ��е����ݲ��������ṹ����e���ļ����������Զ�������
//����n�����������Ա���������ض����Ա����
int readFromFile(struct EmpType e[],int n);
//��ʾ��ͷ��n���ַ�(ch)(inline:�����������ӿ������ٶ�)
inline void show_table_head(int n,char ch);
//��ʾϵͳ��ǰ���ں�ʱ��
void show_time(void);
//����ϵͳ��ǰ���ڵ����ֵ
int get_cur_year(void);
//��ʾ����ѡ��˵�
//��ڲ�������������û�ѡ�������(��д)�ַ�����ʽ���磺��A,B,C,D,Q��
void show_menu(char *);
//����û���ѡ�񣬷���ֵ���û����µ��ַ�(��д)
char get_choice(void);
//��������ʣ��������ַ���<�س�>��
inline void eatline(void);
//������'2010-12-31'�������ַ����ֽ�Ϊ�����մ���������ڽṹ(����)�����ظýṹ
//ʹ��const(�����޸�)�޶������Ա������ڲ����ַ����������޸�
Birthday brkYMD(const char *ymd);
//���ָ���ꡢ�¶�Ӧ������
int getDaynumOfMonth(int year,int month);
//ȷ��Ա��������Ϣ����e�е�n��Ա����Ա�����Ƿ�Ϸ���
//�Ϸ�����true�����Ϸ�����false
bool isValidNo(struct EmpType e[],int n);
//ȷ��Ա��������Ϣ����e�е�n��Ա���Ĺ�����Ϣ�Ƿ�Ϸ���
//���ݺϷ�����true�����ݲ��Ϸ�����false
bool isValidData(struct EmpType e[],int n);
//��Ա��������Ϣ����e�е�n��Ա���Ĺ�����Ϣ����Ա����Ϣ�ļ��С�
void writeToFile(FILE *fp,struct EmpType e[],int n);
//����Ա��������Ϣ���ṹ����e����ǰ�Ѿ������Ա����Ϊi
//���ؼ��ϱ��������ǰ�Ѿ������Ա������(<=NUM)
int input(struct EmpType e[],int n);
//���Ա��������Ϣ����e�е�n��Ա���Ĺ�����Ϣ��
inline void output_one(struct EmpType e[],int n);
//���Ա��������Ϣ����ڲ�����Ա��������Ϣ����e��Ա����n
void output(struct EmpType e[],int n);
//���Ա������ͳ����Ϣ����ڲ�����Ա��������Ϣ����e��Ա����n
void calc(struct EmpType e[],int n);
//����order��ֵ('A':����,'D':����)�Ƚ�Ա���ţ�����true��false
bool cmp_no(struct EmpType e[],int n,char order);
//����order��ֵ('A':����,'D':����)�Ƚ�Ա��������������true��false
bool cmp_name(struct EmpType e[],int n,char order);
//����order��ֵ('A':����,'D':����)�Ƚ�Ա�����Ա𣬷���true��false
bool cmp_sex(struct EmpType e[],int n,char order);
//����order��ֵ('A':����,'D':����)�Ƚ�Ա�������䣬����true��false
bool cmp_day(struct EmpType e[],int n,char order);
//����order��ֵ('A':����,'D':����)�Ƚ�Ա����Ӧ�����ʣ�����true��false
bool cmp_salary(struct EmpType e[],int n,char order);
//��Ա���ŵȽ�������(ð������)��
//��ڲ�����Ա��������Ϣ����e��Ա����n��cmp�ȽϺ����ĺ���ָ�룬order('A':����,'D':����)
void sort(struct EmpType e[],int n,bool (*cmp)(struct EmpType [],int,char),char order);
//��ʾ����ѡ��˵�
void show_sort_menu(void);
//��Ա���ŵȽ�������(ð������)����ڲ�����Ա��������Ϣ����e��Ա����n
void sort_all(struct EmpType e[],int n);
//����Ա����no��Ӧ���±꣬�����ڷ���-1
//��ڲ�����Ա��������Ϣ����e��Ա����n��no�����ҵ�Ա����
int get_index(struct EmpType e[],int n,const char *no);
//��Ա���Ž��в��ҡ���ڲ�����Ա��������Ϣ����e��Ա����n
void search(struct EmpType e[],int n);
//��Ա����ɾ��Ա����Ϣ������ɾ����ʣ��Ա��������
//��ڲ�����Ա��������Ϣ����e��Ա����n
int delete_emp(struct EmpType e[],int n);
//�ýṹ����ĵ�ǰԱ����Ϣ�����ļ���ԭ�е�����
void flushFile(struct EmpType e[],int n);

//�����ͷ����Ϣ
#define output_table_head \
printf("%6s%-9s%-5s%11s%10s%10s%10s%10s\n","Ա����"," ����","�Ա�","��������","��λ����","�����ܶ�","�����ܶ�","Ӧ������")
//���Ա������Ϣ��Ա���š��������Ա�
#define output_no_name_sex(fp,emp,index) \
fprintf(fp,"%-6s%-9s%-5s",emp[index].no,emp[index].name,(emp[index].sex==male?"��":"Ů"))
//�����������
#define output_birthday(fp,bd) fprintf(fp," %4d.%02d.%02d",bd.year,bd.month,bd.day);
//���Ա������Ϣ����λ���ʡ������ܶ�����ܶӦ������(�ܶ�)
#define output_salary(fp,emp,index) \
fprintf(fp,"%10.2lf%10.2lf%10.2lf%10.2lf\n",emp[index].gwgz,emp[index].btze,emp[index].dkze,emp[index].yfgz)

int main() {
  struct EmpType emp[NUM];  //���Ա��������Ϣ������
  //�ṹ(��)��������׵��¶�ջ���������취���޸�IDE�����ã����߸�Ϊstatic���顣
  int eNum=0;               //��ǰ�Ѿ������Ա������(��ò�Ҫ�����ȫ�ֱ���)
  char choice;              //�û����µ��ַ�(��д)
  
  eNum=readFromFile(emp,NUM);    //����Ա����Ϣ�ļ��е�����
  
  while ((choice=get_choice())!='Q') {
    if (choice!='I'&&!eNum) {
      printf("\a\n��û��Ա����Ϣ������ʹ�øù��ܣ���������Ա����Ϣ��\n\n");
      continue;
    }
    switch (choice) {
    case 'I':
      eNum=input(emp,eNum);       //����Ա��������Ϣ
      if (eNum) output(emp,eNum); //���Ա��������Ϣ
      break;
    case 'O':
      output(emp,eNum);           //���Ա��������Ϣ
      break;
    case 'T':
      calc(emp,eNum);             //���Ա������ͳ����Ϣ
      break;
    case 'S':
      sort_all(emp,eNum);         //��Ա���ŵȽ�������
      output(emp,eNum);           //���Ա��������Ϣ
      break;
    case 'F':
      search(emp,eNum);           //��Ա���Ž��в���
      break;
    case 'D':
      eNum=delete_emp(emp,eNum);  //ɾ��Ա����Ϣ
      flushFile(emp,eNum);        //���޸ĺ��Ա����Ϣд���ļ�
      break;
    }
  }
}

//�ýṹ����ĵ�ǰԱ����Ϣ�����ļ���ԭ�е�����
void flushFile(struct EmpType e[],int n) {
  FILE *fp=fopen(FILE_NAME,"w");
  //��д��Ա����Ϣ�ļ�����ʱ�������ж��Ƿ��ʧ�ܣ����Ǻ����������Ż�����⡣
  for (int i=0;i<n;i++)
    writeToFile(fp,e,i);   //��Ա��������Ϣ����e�е�i��Ա���Ĺ�����Ϣ����Ա����Ϣ�ļ���
  fclose(fp);
}

//����Ա����Ϣ�ļ��е����ݲ��������ṹ����e���ļ����������Զ�������
//����n�����������Ա���������ض����Ա����
int readFromFile(struct EmpType e[],int n) {
  int i=0;      //�����Ա����
  char sex[3];  //�����Ա�(�л�Ů)
  
  FILE *fp;
  if ((fp=fopen(FILE_NAME,"a+"))==NULL) {
    fprintf(stderr,"\a\n��Ա����Ϣ�ļ�:%s����\n\n",FILE_NAME);
    exit(-1);
  }
  
  //����ֻ��ͨ���������ṩ�Ĺ��ܱ������ݣ����Բ���Ҫ�����ݵ������Ե��ٴν��м��顣
  while(i<NUM && fscanf(fp,"%s%s%s",e[i].no,e[i].name,sex)==3) {
    fscanf(fp,"%4d.%2d.%2d",&e[i].birthday.year,&e[i].birthday.month,&e[i].birthday.day);
    fscanf(fp,"%lf%lf%lf%lf",&e[i].gwgz,&e[i].btze,&e[i].dkze,&e[i].yfgz);
    if (!strcmp(sex,"��")) e[i].sex=male;
    else                   e[i].sex=female;
    
#ifdef DEBUG
    output_one(e,i);
#endif
    
    i++;
  }
  
  if (fclose(fp)) {
    fprintf(stderr,"\a\n�ر�Ա����Ϣ�ļ�:%s����\n\n",FILE_NAME);
    exit(-2);
  }
  
  return i;
}

/**********************************************************
//��ʾ��ͷ��n���ַ�(ch)
//�õݹ麯��ʵ��(��������ʾ�ݹ麯����ʵ�ʲ���ôʹ��)
void show_table_head(int n,char ch) {
  if (n<1) return;
  putchar(ch); 
  if (n==1) putchar('\n');
  if (n>1) show_table_head(n-1,ch);
}
***********************************************************/
//��ʾ��ͷ��n���ַ�(ch)(inline:�����������ӿ������ٶ�)
inline void show_table_head(int n,char ch) {
if (n<1) return;
for (int i=0;i<n;i++)
putchar(ch); 
putchar('\n');
}

//��ʾϵͳ��ǰ���ں�ʱ��
void show_time(void) {
  struct tm *local;
  long long t;
  static char wday[][3]={"��","һ","��","��","��","��","��"};
  
  time(&t);
  local = localtime(&t);  //���ؽṹָ��
  
  printf("������: %d.%02d.%02d(����%s) ",local->tm_year+1900,++local->tm_mon,local->tm_mday,wday[local->tm_wday]);
  printf(" %02d:%02d:%02d\n",local->tm_hour,local->tm_min,local->tm_sec);
} 
/****************************************************************************************************************************
struct tm {
int tm_sec;   //�� - ȡֵ����Ϊ[0,59]
int tm_min;   //�� - ȡֵ����Ϊ[0,59] 
int tm_hour;  //ʱ - ȡֵ����Ϊ[0,23] 
int tm_mday;  //һ�����е����� - ȡֵ����Ϊ[1,31]
int tm_mon;   //�·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11]
int tm_year;  //��ݣ���ֵ����ʵ����ݼ�ȥ1900
int tm_wday;  //���� �C ȡֵ����Ϊ[0,6]������0���������죬1��������һ���Դ�����
int tm_yday;  //��ÿ���1��1�տ�ʼ������ �C ȡֵ����Ϊ[0,365]������0����1��1�գ�1����1��2�գ��Դ�����
int tm_isdst; //����ʱ��ʶ����ʵ������ʱ��ʱ��tm_isdstΪ������ʵ������ʱ�Ľ���tm_isdstΪ0�����˽����ʱ��tm_isdst()Ϊ����
}; 
*****************************************************************************************************************************/

//����ϵͳ��ǰ���ڵ����ֵ
int get_cur_year(void) {
  struct tm *local;
  long long t;
  time(&t);
  local = localtime(&t);
  return (local->tm_year+1900);
}

//��ʾ����ѡ��˵�
//��ڲ�������������û�ѡ�������(��д)�ַ�����ʽ���磺��A,B,C,D,Q��
void show_menu(char *select_str) {
  //��Ź���ѡ��˵���Ҫ��ÿ�еĵ�һ���ַ�����Ϊѡ���ַ������һ��һ���ǡ�Q:�˳�ϵͳ����
  const static char *menu[]={
      "I:����Ա��������Ϣ",
      "O:���Ա��������Ϣ",
      "T:���Ա������ͳ����Ϣ",
      "S:��Ա���ŵ���������Ա��������Ϣ",
      "F:��Ա���Ų��Ҳ�����乤����Ϣ",
      "D:��Ա���Ų��Ҳ�ɾ���乤����Ϣ",
      "Q:�˳�ϵͳ"
  };
  
  show_table_head(S_NUM,'*');   //��ʾE_NUM��'*'
  int j;
  for (int i=0,j=0;i<sizeof(menu)/sizeof(menu[0]);i++) {
    printf("%-4s%-*s*\n","*",S_NUM-5,menu[i]);
    if (i>0) select_str[j++]=',';
    select_str[j++]=toupper(menu[i][0]);
  }
  select_str[j++]='\0';
  
  show_table_head(S_NUM,'*');   //��ʾE_NUM��'*'
  
  printf("��ѡ��(%s):",select_str);
}

//����û���ѡ�񣬷���ֵ���û����µ��ַ�(��д)
char get_choice(void) {
  char select_str[MAX_MENU*2];
  //��������û�ѡ�������(��д)�ַ�����ʽ���磺��A,B,C,D,Q��
  char choice;
  while (1) {
    show_menu(select_str);        //��ʾ����ѡ��˵�
    choice=toupper(getch());      //�ǻ����޻�������
    putchar(choice);              //���Ը�������ַ�
    //���������Ի���ʵ�ֺ�ǰ��2�������ͬ�Ĺ���
    //choice=toupper(getche());   //�ǻ����л�������
    putchar('\n');
    if (strchr(select_str,choice)&&choice!=',') break;
    printf("\a\nѡ�����������ѡ��......\n\n");
  }
  return choice;
}

//��������ʣ��������ַ���<�س�>��
inline void eatline(void) {
  while (getchar()!='\n')
    continue;
}

//������'2010-12-31'�������ַ����ֽ�Ϊ�����մ���������ڽṹ(����)�����ظýṹ
Birthday brkYMD(const char *ymd) {
  char *p=strchr(ymd,'-');  //��ŵ�1��'-'��λ��
  char *q=strchr(p+1,'-');  //��ŵ�2��'-'��λ��
  
  //�ֽ�Ϊ�����մ������y��m��d
  char y[YMD_LEN+1],m[YMD_LEN+1],d[YMD_LEN+1];  //��������յ��ַ���
  strcpy(y,ymd);  y[p-ymd]='\0';
  strcpy(m,p+1);  m[q-p-1]='\0';
  strcpy(d,q+1);
  
  //ת��Ϊ���Ͳ�����ṹ��
  Birthday tmp;
  tmp.year=atoi(y);
  tmp.month=atoi(m);
  tmp.day=atoi(d);
  
  return tmp;
}

//ȷ��Ա��������Ϣ����e�е�n��Ա����Ա�����Ƿ�Ϸ���
//�Ϸ�����true�����Ϸ�����false
bool isValidNo(struct EmpType e[],int n) {
  //Ա������Ա����Ϣ��Ψһ��ʶ���������ظ���
  //Ա���Ÿ�ʽ�涨��{1--9}+{0--9}+{0--9}+{0--9}+......
  //������1λΪ1--9֮������֣�������ַ���������������
  if (strlen(e[n].no)!=NO_LEN) {
    printf("\nԱ����\"%s\"���ȱ���Ϊ��%d��\n",e[n].no,NO_LEN);
    return false;
  }
  unsigned int i;
  for (i=0;i<(unsigned int)n;i++) {
    if (!strcmp(e[i].no,e[n].no)) {
      printf("\nԱ������Ա����Ϣ��Ψһ��ʶ���������ظ���Ա����\"%s\"�Ѿ����ڡ�\n",e[n].no);
      return false;
    }
  }
  if (!isdigit(e[n].no[0]) || e[n].no[0]=='0') {
    printf("\nԱ���ŵ�1λ����Ϊ1--9֮������֣�\n");
    return false;
  }
  for (i=1;i<strlen(e[n].no);i++)
    if (!isdigit(e[n].no[i])) {
      printf("\nԱ���Ŵӵ�2λ��ʼ����Ϊ0--9֮������֣�\n");
      return false;
    }
    return true;
}

//���ָ���ꡢ�¶�Ӧ������
int getDaynumOfMonth(int year,int month) {
  int day_num[]={31,-1,31,30,31,30,31,31,30,31,30,31};
  if (month<1 || month>12) return -1;
  if (month!=2)  return day_num[month-1];
  else return ((year%4==0 && year%100!=0)||(year%400==0)?29:28);
}

//ȷ��Ա��������Ϣ����e�е�n��Ա���Ĺ�����Ϣ�Ƿ�Ϸ���
//���ݺϷ�����true�����ݲ��Ϸ�����false
bool isValidData(struct EmpType e[],int n) {
  
  if (!isValidNo(e,n)) return false;    //Ա��������
  
  for (unsigned int i=0;i<strlen(e[n].name);i++){
    if (isascii(e[n].name[i])) {
      printf("\nԱ���������붼�Ǻ��֣�\n");
      return false;
    }
  }
  if (strlen(e[n].name)<4) {
    printf("\n����������2�����ϵĺ��֣�\n");
    return false;
  }
  
  //�Գ�������ֻ���бȽϼ򵥵ļ���
  if (e[n].birthday.month<1 || e[n].birthday.month>12) {
    printf("\n�������ڵ��·ݴ���ֻ����1--12֮�䣡\n");
    return false;
  }
  int days=getDaynumOfMonth(e[n].birthday.year,e[n].birthday.month);
  if (e[n].birthday.day>days) {
    printf("\n�������ڵ����ڴ���%d��%d��ֻ��%d�죡\n",e[n].birthday.year,e[n].birthday.month,days);
    return false;
  }
  int age=get_cur_year()-e[n].birthday.year;  //��������
  if (age<MIN_AGE || age>MAX_AGE) {           //��������Ů��������������
    printf("\n����(%d)Ӧ����%d---%d֮�䣡\n",age,MIN_AGE,MAX_AGE);
    return false;
  }
  
  if (e[n].gwgz<=0 || e[n].gwgz>MAX_SALARY) {
    printf("\n��λ��������ֵӦ�ô���0��������%d��\n",MAX_SALARY);
    return false;
  }
  if (e[n].btze<=0 || e[n].btze>MAX_SALARY) {
    printf("\n�����ܶ�����ֵӦ�ô���0��������%d��\n",MAX_SALARY);
    return false;
  }
  if (e[n].dkze<=0 || e[n].dkze>MAX_SALARY) {
    printf("\n�����ܶ�����ֵӦ�ô���0��������%d��\n",MAX_SALARY);
    return false;
  }
  
  return true;
}

//��Ա��������Ϣ����e�е�n��Ա���Ĺ�����Ϣ����Ա����Ϣ�ļ��С�
void writeToFile(FILE *fp,struct EmpType e[],int n) {
  output_no_name_sex(fp,e,n);
  output_birthday(fp,e[n].birthday);
  output_salary(fp,e,n);
}

//����Ա��������Ϣ���ṹ����e����ǰ�Ѿ������Ա����Ϊi
//���ؼ��ϱ��������ǰ�Ѿ������Ա������(<=NUM)
int input(struct EmpType e[],int i) {
  char sex[3];            //�����Ա�(�л�Ů)
  char str_bd[YMD_LEN+1]; //����������ڵ��ַ���
  bool isValidSex=true;   //�Ա��Ƿ�Ϸ��ı�־
  
  FILE *fp=fopen(FILE_NAME,"a+");
  //��Ա����Ϣ�ļ�����ʱ�������ж��Ƿ��ʧ�ܣ����Ǻ����������Ż�����⡣
  
  printf("\n�����벻����%d��Ա����\nԱ���š��������Ա𡢳������ڡ���λ���ʡ������ܶ�����ܶ\n\n",NUM-i);
  printf("�����װ�<Ctrl>+Z��<�س�>��<�س�>�������룡\n");
  
  while (i<NUM && scanf("%s%s%s%s%lf%lf%lf",e[i].no,e[i].name,sex,str_bd,&e[i].gwgz,&e[i].btze,&e[i].dkze)==7) {
    e[i].birthday=brkYMD(str_bd);
    e[i].yfgz=e[i].gwgz+e[i].btze-e[i].dkze;    //����Ӧ������
    
#ifdef DEBUG
    output_one(e,i);
#endif
    
    if (!strcmp(sex,"��"))
      e[i].sex=male;
    else if (!strcmp(sex,"Ů")) 
      e[i].sex=female;
    else {
      isValidSex=false;
      printf("\a\n�Ա�ֻ����\"��\"��\"Ů\"��\n");
    }
    if (isValidSex && isValidData(e,i)) {
      writeToFile(fp,e,i);   //��Ա��������Ϣ����e�е�i��Ա���Ĺ�����Ϣ����Ա����Ϣ�ļ���
      i++;                   //�������Ա�����ݺϷ�����ǰ�Ѿ������Ա������+1
    }
    else 
      printf("\a�������Ա�������д�����û�б����棡\n\n");
  }
  eatline();    //��������ʣ��������ַ���<�س�>��
  
#ifdef DEBUG
  printf("��ǰ�Ѿ������Ա������Ϊ��%d\n\n",i);
#endif
  
  fclose(fp);   //�ر�Ա����Ϣ�ļ���ͬ�����������жϡ�
  return i;
}

//���Ա��������Ϣ����e�е�n��Ա���Ĺ�����Ϣ��
inline void output_one(struct EmpType e[],int n) {
  output_no_name_sex(stdout,e,n);
  output_birthday(stdout,e[n].birthday);
  output_salary(stdout,e,n);
}

//���Ա��������Ϣ����ڲ�����Ա��������Ϣ����e��Ա����n
void output(struct EmpType e[],int n) {
  printf("\n����Ա������Ϊ��%d\n\n",n);
  output_table_head;
  show_table_head(E_NUM,'=');   //���E_NUM��'='
  for(int i=0;i<n;i++) {
    output_one(e,i);
  }
  show_table_head(E_NUM,'=');   //���E_NUM��'='
  putchar('\n');
}

//���Ա������ͳ����Ϣ����ڲ�����Ա��������Ϣ����e��Ա����n
void calc(struct EmpType e[],int n) {
  double sum=0,sum_male=0,sum_female=0;
  //����Ա��Ӧ�������ܶ����Ա��Ӧ�������ܶŮ��Ա��Ӧ�������ܶ�
  double max,min;           //Ӧ�����ʵ���ߺ����
  int c_male=0,c_female=0;  //����С�Ů��Ա��������
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
  printf("\nӦ���������Ϊ��%.2lf�����Ϊ��%.2lf������Ա��Ӧ�������ܶ�Ϊ��%.2lf\n",max,min,sum);
  printf("\n����Ա������Ϊ��%d��Ů��Ա������Ϊ��%d\n",c_male,c_female);
  printf("\nӦ������ƽ��ֵΪ��%.2lf(���У�����ƽ��ֵΪ��%.2lf��Ů��ƽ��ֵΪ��%.2lf)\n\n",sum/n,sum_male/c_male,sum_female/c_female);
}

//����order��ֵ('A':����,'D':����)�Ƚ�Ա���ţ�����true��false
bool cmp_no(struct EmpType e[],int n,char order) {
  if (order=='A'&& strcmp(e[n].no,e[n+1].no)>0) return true;
  if (order=='D'&& strcmp(e[n].no,e[n+1].no)<0) return true;
  return false;
}

//����order��ֵ('A':����,'D':����)�Ƚ�Ա��������������true��false
bool cmp_name(struct EmpType e[],int n,char order) {
  if (order=='A'&& strcmp(e[n].name,e[n+1].name)>0) return true;
  if (order=='D'&& strcmp(e[n].name,e[n+1].name)<0) return true;
  return false;
}

//����order��ֵ('A':����,'D':����)�Ƚ�Ա�����Ա𣬷���true��false
bool cmp_sex(struct EmpType e[],int n,char order) {
  if (order=='A'&& e[n].sex>e[n+1].sex) return true;
  if (order=='D'&& e[n].sex<e[n+1].sex) return true;
  return false;
}

//����order��ֵ('A':����,'D':����)�Ƚ�Ա�������䣬����true��false
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

//����order��ֵ('A':����,'D':����)�Ƚ�Ա����Ӧ�����ʣ�����true��false
bool cmp_salary(struct EmpType e[],int n,char order) {
  if (order=='A'&& e[n].yfgz>e[n+1].yfgz) return true;
  if (order=='D'&& e[n].yfgz<e[n+1].yfgz) return true;
  return false;
}

//��Ա���ŵȽ�������(ð������)��
//��ڲ�����Ա��������Ϣ����e��Ա����n��cmp�ȽϺ����ĺ���ָ�룬order('A':����,'D':����)
void sort(struct EmpType e[],int n,bool (*cmp)(struct EmpType [],int,char),char order) {
  for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++) {
      if (cmp(e,j,order)) {
        //����e[j]��e[j+1]
        struct EmpType tmp=e[j];
        e[j]=e[j+1];
        e[j+1]=tmp;
      }
    }
}

//��ʾ����ѡ��˵�
void show_sort_menu(void) {
  printf("\n      ����ʽѡ��˵�\n");
  printf("================================\n");
  printf("1:��Ա���Ŵ�С��������\n");
  printf("2:��Ա���ŴӴ�С����\n");
  printf("3:��Ա����������\n");
  printf("4:��Ա���Ա�����\n");
  printf("5:��Ա�������С��������\n");
  printf("6:��Ա������Ӵ�С����\n");
  printf("7:��Ա��Ӧ�����ʴ�С��������\n");
  printf("8:��Ա��Ӧ�����ʴӴ�С����\n");
  printf("q:�������˳�\n");
  printf("================================\n");
  printf("��ѡ��(1--8��q)��");
}

//��Ա���ŵȽ�������(ʹ����򵥵�ð������)����ڲ�����Ա��������Ϣ����e��Ա����n
void sort_all(struct EmpType e[],int n) {
  show_sort_menu();
  char choice=getche(); //�޻����л��ԣ��Ǳ�׼�Ŀ⺯��
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

//����Ա����no��Ӧ���±꣬�����ڷ���-1
//��ڲ�����Ա��������Ϣ����e��Ա����n��no�����ҵ�Ա����
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

//��Ա���Ž��в��ҡ���ڲ�����Ա��������Ϣ����e��Ա����n
void search(struct EmpType e[],int n) {
  char no[NO_LEN+1];   //��Ŵ����ҵ�Ա����
  
  printf("\n���������ѯ��Ա���ţ�");
  fgets(no,NO_LEN+1,stdin);
  eatline();
  int k=get_index(e,n,no);   //����Ա����no��Ӧ���±꣬�����ڷ���-1
  
  if (k==-1)
    printf("Ա��[%s]�����ڣ�\n\n",no);
  else {
    output_table_head;
    output_one(e,k);
    putchar('\n');
  }  
}

//��Ա����ɾ��Ա����Ϣ������ɾ����ʣ��Ա��������
//��ڲ�����Ա��������Ϣ����e��Ա����n
int delete_emp(struct EmpType e[],int n) {
  char no[NO_LEN+1];    //���Ҫɾ����Ա����
  
  printf("\n������Ҫɾ����Ա���ţ�"); 
  fgets(no,NO_LEN+1,stdin);
  eatline();
  int k=get_index(e,NUM,no);   //����Ա����no��Ӧ���±꣬�����ڷ���-1
  
  if (k==-1) {
    printf("Ա��[%s]�����ڣ�\n\n",no);
    return n;
  }
  //������k���͵�n-1��Ա������Ϣ
  struct EmpType t=e[k];
  e[k]=e[n-1];
  e[n-1]=t;
  printf("Ա��[%s]�Ѿ����ɹ�ɾ����\n\n",no);
  return n-1;
}

/*****************************************************************
1�����ڲ��ԵĺϷ��������£�
Ա���š��������Ա𡢳������ڡ���λ���ʡ������ܶ�����ܶ�
1010	����ί	��	1990-10-20	3220	1500	300
1011	������	Ů	1989-12-9	3530	1800	400
1012	����ӿ	��	1978-11-22	2540	1300	250
1013	����Ȧ	��	1965-10-31	3400	1200	180
1014	����Ǻ	��	1979-5-4	4780	2000	450
1006	��ָ��	��	1991-1-2	3009	1500	300
1007	�˽���	��	1964-2-28	3520	1800	400
1008	��Ժ��	��	1973-3-27	2300	1300	250
1009	����	��	1967-5-28	3340	1200	180
1001	����	Ů	1966-7-7	3755	2000	450
1002	��ĽȪ	��	1981-4-30	3011	1500	300
1003	л���	��	1984-6-30	3598	1800	400
1004	������	��	1985-2-10	2506	1300	250
1005	����Ȥ	��	1970-8-2	3243	1200	180
1015	����	��	1992-11-3	4708	2000	450
1016	��Л��	��	1955-9-4	3060	1500	300
1017	����	Ů	1962-6-5	2588	1200	400
1018	�β�Ծ	��	1986-3-16	2595	1300	250
1019	�μ�λ	��	1977-4-11	3760	1200	180
1020	������	��	1962-11-8	4670	2000	450
1021	���	��	1984-6-9	3878	1500	300
1022	������	��	1985-11-11	3333	1800	400
1023	������	Ů	1988-9-30	2566	1300	250
1024	�ƳǺ�	��	1991-6-12	3222	1200	180
1025	����ӝ	��	1990-5-13	4777	2000	450
��ѡ�����еĲ������ݲ������ơ���Ȼ��������д���
ʱ�������Ͻǣ�ѡ���༭���ġ�ճ��������ֱ������
2�����ڲ������ݼ��鹦�ܵĲ����������£�
1005	����ӝ	��	1990-5-13	4700	2000	450
0010	����ί	��	1990-10-20	3000	1500	300
101X	����ί	��	1990-10-20	3000	1500	300
1055	����	��	1990-5-13	4700	2000	450
1088	��1234	��	1990-5-13	4700	2000	450
1088	����	��	1990-15-13	4700	2000	450
1088	����	��	1990-5-32	4700	2000	450
1088	����	��	1990-5-3	1000000	2000	450
1088	����	��	1990-5-3	2000	1000000	450
1088	����	��	1990-5-3	2000	450	1000000
1088	����	��	1990-11-13	-4700	2000	450
1088	����	��	1990-11-13	4700	-2000	450
1088	����	��	1990-11-13	4700	2000	0
1088	����	��	1995-5-3	4700	2000	450
1088	����	��	1940-5-3	4700	2000	450
108 	����	��	1980-5-3	4700	2000	450
1088	��  	��	1990-5-13	4700	2000	450
******************************************************************/
