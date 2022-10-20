# 暨南大学C语言程序设计实验作业合订本

### 2022年春

1. 实验一
   ![hello world](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E4%B8%80.png)
   ```c
   #include<stdio.h>
    int main(){
        printf("hello world");
        return 0;
    }
   ```
   - 每个程序员的必备小仪式
2. 实验二
   ![meter-inch](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E4%BA%8C.png)
   ```c
   #include<stdio.h>
    int main(){
        int inch,cun;
        float meter;
        scanf("%d,%d",&inch,&cun);
        meter=inch*0.3048+cun*0.0254;
        printf("The meter is %f\n",meter);
    }
   ```
   - 要注意的是，在C语言中两个整型变量相除，其结果是结果向下取整，所以题目中的转换公式我们需要将`cun`的除数`12`先同`0.3048`相乘,再与inch计算的结果相加。
   - 输出的时候要注意`printf`函数的数据类型要统一

3. 实验三
   ![encode_char](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E4%B8%89.png)
   ```c
   #include<stdio.h>
    int main(){
        char char_x, m, n, a, A;
        a = 97;A = 65;
        printf("Please enter a character:");
        scanf("%c",&char_x);
        if((char_x >= 'a'&&char_x <= 'm')){
            // n=char_x-a;
            m = char_x + char_x - a + 1;
            // printf("%c",m);
        }
        if(char_x >= 'A'&&char_x <= 'M'){
            // n=char_x-A;
            m = char_x + char_x - A + 1;
            // printf("%c",m);
        }   
        if(char_x>'M'&&char_x<='Z'){
            m = char_x + char_x - A- 25;
            // printf("%c",m);
            // 在这里，由于字母表是闭环，所以超过一圈时要减掉一周的量
        }
        if(char_x > 'm'&&char_x <= 'z'){
            m = char_x+char_x-a-25;
            // printf("%c",m);
        }
        printf("%c",m);
        return 0;
    }
   ```
   - 多情况判断类题型

4. 实验四
   ![prime_number](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E5%9B%9B.png)
  ```c
  #include<stdio.h>
  #include<math.h>
    int main(){
        int n, i, j, k = 1,a[1000];
        printf("pelase enter a number:\n");
        scanf("%d",&n);
        printf("2 is a prime number.\n");
        for(i = 2;i <= n; i++){
            for(j = 2;j <= i; j++)
                {
                    if(i%j == 0)break;
                    if(j >= sqrt(i)&&j < sqrt(i) + 1){printf("%d is a prime number.\n",i);
                                    k++;}
                }
        }
        printf("there are %d prime numbers!",k);
        return 0;
    }
  ```
   - 需要注意的是，我们采用的是小于n的数依次整除n的方法来判断素数，由于$ n = \sqrt{n} * \sqrt{n} $,所以我们只需要判断$ 1- \sqrt{n}$的数即可，节省计算的时间
5. 实验五
   ![sin_cos](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E4%BA%94.png)
   ```c
   #include<stdio.h>
   #include<math.h>
   int main(){
        double y;
        int xx,xs,xc;
        for(y=1;y>=-1;y-=0.1){
            xc=acos(y)*10;
            xs=asin(y)*10;
            if(xs<0){
                 xs=-xs+31;
        }
        for(xx=0;xx<=62;xx++){
            if(xx==xs||xx==31-xs||xx==93-xs){
                printf("*");
            }
            else if(xx==xc||xx==62-xc){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
    }
   ```
   - 这题考察的是C语言字符串输出的特点，从左到右，从上到下，所以我们只要模拟其过程即可，一行一行扫描，最后绘制成正弦和余弦曲线，在函数上的点为`*`,不在的为空格
6. 实验六
   ![power_off](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E5%85%AD.png)
   ```c
   #include<stdio.h>
    int count(int s);
    int main(){
        int m , d, i = 0,n = 1,t = 0, s, output;
        do{
            scanf("%d/%d",&m,&d);
            if(m>8||m<7||n<=0||n>31)return 0;
            s = (m-7)*31+d;
            output = count(s);
            printf("%d\n",output);
            }
        while(m != 0&&d != 0);

    }

    int count(int s){
        int a[10] = {1,3,6,10,15,21,28,36,45,55};
        int n = 1, t = 0;
        for(int i = 0;i < 10;i++){
            if(a[i] >= s) t++;
        }
         return(t);
    }
   ```
   - 这道题需要注意的是，要将日期`date`转化为十进制的数来表示，然后再统计停电的日期
7. 实验七
   ![matrix](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E4%B8%83.png)
   ```c
   #include<stdio.h>

    int main(){
    int M,N,T,t,test;
    scanf("%d",&T);
    for(test=1;test<=T;++test){
        scanf("%d %d",&M,&N);
        int res[4][4]={{1,0,0,0},
                        {0,1,0,0},
                        {0,0,1,0},
                        {0,0,0,1}};
        int A[4][4];
        int i,j,t,k;
        for(i=0;i<M;i++){
            for(j=0;j<M;j++){
                scanf("%d",&A[i][j]);
            }
        }
        for(t=0;t<N;++t){
            int tmp[4][4]={0};
            for(i=0;i<M;++i){
                for(j=0;j<M;++j){
                    for(k=0;k<M;++k){
                        tmp[i][j]+=res[i][k]*A[k][j];
                    }
                }
            }
            for(i=0;i<M;i++){
                for(j=0;j<M;j++){
                    res[i][j]=tmp[i][j];
                }
            }
        }
        printf("Case %d:\n",test);
        for(i=0;i<M;i++){
            for(j=0;j<M;j++){
                printf("%d",res[i][j]);
                if(j!=M-1)printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
    }
   ```
   - 流程图
  ![](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/ACM001.png)
  - 这题的难点在于手写一个矩阵的乘法运算
8. 实验八
   ![gaussing](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E5%85%AB.png)
   ```c
   #include<stdio.h>

    int main()
    {
    int N,value,row,col,dir,i,j, n;
    while(scanf("%d",&N)!=EOF)
    {   
        int tri[24][24]={0};
         row = col = 1;
         value = 1;
         for(;value<=N;++value)
            tri[row++][col]=value;
         row = N;
         col =2 ;
         value = N+1;
         for(;value<=2*N-1;++value)
             tri[row][col++] = value;
         row = N-1;
         col = N-1;
         value = 2*N;
         for(;value<=3*N-3;++value)
             tri[row--][col--] = value;
         row = 2;
         col = 2;
         value = 3*N-2;
         dir = 1;
         while(value<=N*(N+1)/2)
         {
              if(1==dir)
              {
                 if((0==tri[row+1][col]))
                   tri[++row][col] = value;
                 else
                 {
                     dir = 2;
                     tri[row][++col] = value;
                 }
              }
              else if(2==dir)
              {
                   if((0==tri[row][col+1]))
                     tri[row][++col] = value;
                   else
                   {
                       dir = 3;
                       tri[--row][--col] = value;
                   }
              }
              else
              {
                    if((0==tri[row-1][col-1]))
                      tri[--row][--col] = value;
                    else
                    {
                        dir=1;
                        tri[++row][col] = value;
                    }
              }
              ++value;
         }
         row = 1;
         for(;row<=N;++row)
         {  
             col = 1;
            for(;col<=row;++col)
            {   
                printf("%d",tri[row][col]);
                if(!(row==N&&col==row))
                  {printf(" ");}
                tri[row][col] = 0;
            }
         }
         printf("\n");
    }
    return 0;
    }
   ```
   - 流程图
   - ![](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/ACM002.png)
   - 模拟过程，这道题的规律是从顶点开始向内RT三角形状螺旋形成二维数组，所以通过一些`选择+判断`即可完成
9.  实验九
    ![51](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E4%B9%9D.png)
    ```c
     #include<stdio.h>
    int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int l = n;
		for (int m = 1; m <= l; m++) {
			int i = m;
			while (i > 0) {
				int j = i % 10;
				i = i / 10;
				if (j == 1 || j == 5) {
					n = n - 1;
					break;
				}
			}
		}
		printf("%d\n", n);
	}
    }
    ```
    - 思路很简单，循环+从个位数开始判断，遇到`1 or 5`直接` break `,时间复杂度为` O(n·log(n))`
10. 实验九（二）
    ![](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E4%B9%9D%EF%BC%88%E4%BA%8C%EF%BC%89.png)
    ```c
    #include<stdio.h>
    #include<math.h>

    int main(){
    double f2(int n , double a[] , double x);
    int n;
    while(scanf("%d",&n)!=EOF){
        double num[10000];
        for(int i = 0;i <= n;++i){
            scanf("%lf",num+i);
        }
        int m;
        scanf("%d",&m);
        double ans[1000];
        for(int j = 0;j < m;++j){
            double x;
            scanf("%lf",x);
            ans[j] = f2(n+1,num,x);
        }
        for(int j = 0;j < m;++j){
            printf("%lf",ans[j]);
            if(j!=m-1)printf(" ");
        }
        printf("\n");
    }
    }

    double f2(int n , double a[] , double x){
 	    int i;
 	    double p = a[0];
 	    for(i = 1;i < n ;i++){
 		p += (a[i] * pow(x,i));
	 }
	 return p;
    } 
    ```
    - 用**秦九韶算法**更加快速和省内存
11. 实验十一
    ![](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E5%8D%81%E4%B8%80.png)
    ```c
        #include<stdio.h>
        #include<string.h>
        #include<malloc.h>
    struct medol
    {
        char name[21];
        int jin;
        int yin;
        int tong;
        struct medol *next;
    };
    struct medol *myhead = NULL;
    void printdata();
    int my_sort(char *name, int ji, int yi, int to, int len){
    int i=0;
    struct medol *p=NULL, *q=NULL, *tmp=NULL;
    if(myhead == NULL)
        return -1;
    if(len == 0)
    {
        myhead->next = (struct medol*)malloc(sizeof(struct medol));
        if(myhead->next != NULL)
        {
            memcpy(myhead->next->name, name, 21);
            myhead->next->jin = ji;
            myhead->next->yin = yi;
            myhead->next->tong = to;
            myhead->next->next = NULL;
        }
        else
        {
            return -1;
        }
    }
    else
    {
         
        if(myhead->next == NULL)
            return -1;
             
        p = myhead->next;
        tmp = (struct medol*)malloc(sizeof(struct medol));
        if(tmp != NULL)
        {
            memcpy(tmp->name, name, 21);
            tmp->jin = ji;
            tmp->yin = yi;
            tmp->tong = to;
            tmp->next = NULL;
        }
        else
            return -1;
             
        for(i=0; i< len+1; i++)
        {
  
            if(p != NULL)
            {
                if(ji > p->jin
                    || (ji == p->jin && yi > p->yin)
                    || (ji == p->jin && yi == p->yin && to > p->tong)
                    || (ji == p->jin && yi == p->yin && to == p->tong && strcmp(name, p->name) < 0)
                )
                {
                    if(p == myhead->next)
                    {
                        tmp->next = p;
                        myhead->next = tmp;
                         
                    }
                    else
                    {
                        tmp->next = p;
                        q->next = tmp;
                    }
                    break;
                }
                else
                {
                    q = p;
                    p = p->next;
                }
            }
            else
            {
                q->next = tmp;
                break;
            }
        }
    }
    return 0;
    }
  
    void printdata()
    {
     
    struct medol *p=NULL;
    if(myhead == NULL)
        return;
    p = myhead->next;
    while(p)
    {
        printf("%s\n", p->name);
        p = p->next;
    }
    }
    void freedata()
    {
    struct medol *p=NULL, *q=NULL;
    if(myhead == NULL)
        return;
    p=q=myhead->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = NULL;
        p = q;
    }
  
    free(myhead);
    myhead = NULL;
    }
    int main()
    { 
    int country_num = 0;
    char c_name[21]={0};
    int tmj=0, tmy=0, tmt=0;
    int i=0;
  
    scanf("%d", &country_num);
    if(country_num > 0 && country_num < 21)
    {
         
        myhead = (struct medol*)malloc(sizeof(struct medol));
        if(myhead == NULL)
            return 1;
        myhead->next = NULL;
         
        for(i=0; i<country_num; i++)
        {
            scanf("%s %d %d %d", c_name, &tmj, &tmy, &tmt);
            my_sort(c_name, tmj, tmy, tmt, i);
        }
        printdata();
        freedata();
    }
    return 0;
    }
    ```
    - 这道题ZXY提供了两个解题的实现思路：
        - 不需要三个变量存储金银铜奖牌数量，用100，10，1的权重计算出权重值再录入即可
        - 全部国家输入后再排序会浪费空间而且慢，其实可以输入几个排序几个（**插入排序**）的思想
12. 实验十二
    ![](/%E5%A4%A7%E4%B8%80%E4%B8%8BC%E8%AF%AD%E8%A8%80%E4%BD%9C%E4%B8%9A/%E5%AE%9E%E9%AA%8C%E5%8D%81%E4%BA%8C.png)
    - 目前没有好的思路