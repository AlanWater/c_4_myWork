#include <string.h>
#include <stdio.h>
//声明拼接字符串方法
extern char srcs[10][200];
void concat(char *str1,char str2[100])
{
    int len = strlen(str2);
    int idx;
    char *p;
    p = str1[0]+strlen(str1);
    printf("start address is %x\n,%s\n",p,str1);
    for(idx=0;idx<len;idx++)
    {
        printf("%c %x\n",str2[idx],p);
        *p = str2[idx];
        printf("%s\n",str1);
        printf("%s\n",srcs[0]);
        p++;
    }
}
