#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char srcs[10][200],dists[10][200];
char baseSrc[100],baseDist[100],configs[20][200];
//初始化目标文件资源路径
void initSrcs(void);
//初始化源文件资源数组路径
void initDst(void);
//读取配置，初始化基本参数
void initBase(void);

void copyPng4AppIconAndScreen(void);

void createNewProjectByConfig(void);

int main()
{
    initBase();
    createNewProjectByConfig();
    initSrcs();
    initDst();
    copyPng4AppIconAndScreen();
    //file_copy("C:\\Users\\sy\\Desktop\\杭实投资 APP\\杭实投资 APP\\APP 图标\\Android\\36x36.png","F:\\android_project\\test\\platforms\\android\\res\\mipmap-ldpi\\icon.png");
    printf("程序成功运行,按任意键结束......");
    getchar();
    return 0;
}


void file_copy(char *src, char *dst)
{
    FILE *fp1, *fp2;
    int c;
    fp1 = fopen(src, "rb");
    fp2 = fopen(dst, "wb");//打开文件
    if(fp1 == NULL || fp2 == NULL)//错误处理
    {
        printf("open file failed\n");
        if(fp1) fclose(fp1);
        if(fp2) fclose(fp2);
        return 0;
    }

    while((c = fgetc(fp1)) != EOF)//读字节
        fputc(c, fp2); //写数据
        printf("已将文件%s\n",src);
        printf("替换至%s\n\n",dst);
    fclose(fp1);//关闭文件
    fclose(fp2);
    return 0;
}

void initBase(void)
{
    FILE *fp;
    int index = 0;
    char *p1;
    fp = fopen("F:\\android_project\\param.ini","rb");
    if(fp == NULL)
    {
        printf("open file failed\n");
        if(fp) fclose(fp);
    }
    char tmp[100];
    while((fgets(tmp,100,fp)) != EOF && index<16)
    {

        if((p1 = strchr(tmp, '\n')) != NULL)
        {
           *p1 = '\0';
        }
        if((p1 = strchr(tmp, '\r')) != NULL)
        {
           *p1 = '\0';
        }

        strcpy(configs[index],tmp); //读取配置存入配置数组中

        if(index==15)
        {
            strcpy(baseSrc,tmp);
        }
        if(index==3)
        {
            strcpy(baseDist,tmp);
        }
        index+=1;
    }
    //printf("the baseSrc is %s\nthe baseDist is %s\n",baseSrc, baseDist);
}

void createNewProjectByConfig(void)
{
    char folderSrc[100],
         folderDist[100],
         tmp[2000];

    strcpy(folderSrc,configs[1]);
    strcpy(folderDist,configs[3]);

    strcpy(tmp,"xcopy ");
    strcat(tmp,folderSrc);
    strcat(tmp," ");
    strcat(tmp,folderDist);
    strcat(tmp," ");
    strcat(tmp,"/s");

    system(tmp);

    return 0;
}

void initSrcs(void)
{
    char tmp[200];
    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APP 图标\\Android\\36x36.png");
    strcpy(srcs[0],tmp);

    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APP 图标\\Android\\48x48.png");
    strcpy(srcs[1],tmp);

    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APP 图标\\Android\\72x72.png");
    strcpy(srcs[2],tmp);

    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APP 图标\\Android\\96x96.png");
    strcpy(srcs[3],tmp);

    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APPloading页\\200x320.png");
    strcpy(srcs[4],tmp);

    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APPloading页\\320x480.png");
    strcpy(srcs[5],tmp);

    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APPloading页\\480x800.png");
    strcpy(srcs[6],tmp);

    strcpy(tmp,baseSrc);
    strcat(tmp,"\\APPloading页\\720x1280.png");
    strcpy(srcs[7],tmp);
}

void initDst(void)
{
    char tmp[200];
    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\mipmap-ldpi\\icon.png");
    strcpy(dists[0],tmp);

    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\mipmap-mdpi\\icon.png");
    strcpy(dists[1],tmp);

    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\mipmap-hdpi\\icon.png");
    strcpy(dists[2],tmp);

    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\mipmap-xhdpi\\icon.png");
    strcpy(dists[3],tmp);

    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\drawable-port-ldpi\\screen.png");
    strcpy(dists[4],tmp);

    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\drawable-port-mdpi\\screen.png");
    strcpy(dists[5],tmp);

    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\drawable-port-hdpi\\screen.png");
    strcpy(dists[6],tmp);

    strcpy(tmp,baseDist);
    strcat(tmp,"\\platforms\\android\\res\\drawable-port-xhdpi\\screen.png");
    strcpy(dists[7],tmp);
}

void copyPng4AppIconAndScreen(void)
{
    unsigned short int idx=0;
    for(;idx<8;idx++)
    {
        file_copy(srcs[idx],dists[idx]);
    }
}
