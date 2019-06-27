#include<iostream>
#include"stdio.h"
#include"string.h"
#include"conio.h"
#include"ctype.h"
using namespace std;
char *key[84]={"iostream","include","alignas","alignof","char16_t","char32_t","constexpr","decltype","noexcept","nullptr","static_assert",
               "asm","auto","bool","break","case","cin","cout","catch","char","class","const","const_cast","continue","default","delete",
               "do","double","dynamic_cast","else","enum","explicit","export","extern","false","float","for","friend","goto","std",
               "if","inline","int","long","mutable","main","namespace","new","operator","private","protected","protected","public","register","reinterpret_cast",
               "return","short","signed","sizeof","static","static_cast","struct","switch","template","this","throw","true","try",
               "typedef","typeid","typename","union","unsigned","using","virtual","void","volatile","wchar_t","while","do","return","break","continue"};
char calc[11]="+-=*/><!%&";
char fen[11]="#,.;{}[]()";
char ch;
int i,k;
char buff[20];
void scan(FILE *fp)
{
    int j;
    ch=fgetc(fp);
    while(ch==' '||ch=='\n'||ch=='\t')
        {ch=fgetc(fp);}
    if(isalpha(ch)) /*输入的是字母，进行 标识符 处理*/
    {
        buff[0]=ch;
        i=1;
        ch=fgetc(fp);
        while(isalnum(ch)) /*如果是字母数字则组合，否则结束*/
        {
            buff[i]=ch;
            i++;
            ch=fgetc(fp);
        }
        buff[i]='\0';
        fseek(fp,-1,1);
        j=0;
        while((j<83)&& strcmp(buff,key[j]))
            j++;
        if(j>=83)   { cout<<buff<<"\t标识符"<<endl; }
        else        { cout<<buff<<"\t关键字"<<endl; }
    }
    else if(isdigit(ch))
    {
        buff[0]=ch;
        ch=fgetc(fp);
        i=1;
        while(isdigit(ch)) /*如果是数字则整合数字*/
        {
            buff[i]=ch;
            i++;
            ch=fgetc(fp);
        }
        buff[i]='\0'; /*整数整合结束*/
        fseek(fp,-1,1);
        cout<<buff<<"\t数"<<endl;
    }
    else if(strchr(fen,ch)>0) /*判断分隔符*/
    {
        buff[0]=ch;
        ch=fgetc(fp);
        buff[1]='\0';
        fseek(fp,-1,1);
        cout<<buff<<"\t特殊符号"<<endl;
    }
    else if(strchr(calc,ch)>0) /*判断运算符*/
    {
        buff[0]=ch;
        if(ch=='=')           /*双运算符*/
        {
            ch=fgetc(fp);
            if(ch=='=')    {cout<<"=="<<"\t运算符"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"="<<"\t运算符"<<endl;
            }
        }
        else if(ch=='+')           /*双运算符*/
        {
            ch=fgetc(fp);
            if(ch=='+')    {cout<<"++"<<"\t运算符"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"+"<<"\t运算符"<<endl;
            }
        }
        else if(ch=='-')           /*双运算符*/
        {
            ch=fgetc(fp);
            if(ch=='-')    {cout<<"--"<<"\t运算符"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"-"<<"\t运算符"<<endl;
            }
        }
        else if(ch=='>')
        {
            ch=fgetc(fp);
            if(ch=='=')     {cout<<">="<<"\t运算符"<<endl;}
            else if(ch=='>')  {cout<<">>"<<"\t特殊符号"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<">"<<"\t运算符"<<endl;
            }
        }
        else if(ch=='<')
        {
            ch=fgetc(fp);
            if(ch=='=')      {cout<<"<="<<"\t运算符"<<endl;}
            else if(ch=='<')  {cout<<"<<"<<"\t特殊符号"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"<"<<"\t运算符"<<endl;
            }
        }
        else if(ch=='!')
        {
            ch=fgetc(fp);
            if(ch=='=')      {cout<<"!="<<"\t运算符"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"error!"<<endl;
            }
        }
        else if(ch=='/')
        {
            ch=fgetc(fp);
            if(ch=='/')
            {
                ch=fgetc(fp);
                cout<<"注释  "<<"//";
                while(ch!='\n')
                {
                    cout<<ch;
                    ch=fgetc(fp);
                }
                cout<<endl;
            }
            else if(ch=='*')
            {
                cout<<"注释  "<<"/";
                while((ch=='*'&&(fgetc(fp))!='/')||ch!='*')
                {
                    cout<<ch;
                    ch=fgetc(fp);
                }
                cout<<"*/"<<endl;
            }
            else cout<<"/"<<"\t运算符"<<endl;
        }
        else if(ch=='*')
        {
            ch=fgetc(fp);
            if(ch=='/')   {ch=fgetc(fp);}
            else cout<<"*"<<"\t运算符"<<endl;
        }
        else if(ch=='&')
        {
            ch=fgetc(fp);
            if(ch=='&')   cout<<"&&"<<"\t运算符"<<endl;
            else cout<<"&"<<"\t运算符"<<endl;
        }
        else
        {
            ch=fgetc(fp);
            buff[1]='\0';
            fseek(fp,-1,1);
            cout<<buff<<"\t运算符"<<endl;
        }
    }
    else if(ch=='\'')
    {
        buff[0]=ch;
        ch=fgetc(fp);
        i=1;
        if(ch=='\'') goto start;
        else
        {
            ch=fgetc(fp);
            buff[1]='\0';
            fseek(fp,-1,1);
            cout<<buff<<"\t特殊符号"<<endl;
        }
    }
    else if(ch=='\"')
    {
        buff[0]=ch;
        ch=fgetc(fp);
        i=1;
start:  while(ch!='\"')
        {
            buff[i]=ch;
            i++;
            ch=fgetc(fp);
        }
        buff[i]='\0';
        cout<<buff<<"\""<<"\t字符串"<<endl;
    }
    else if(ch=EOF)
    {
        cout<<endl;
    }
    else            /*无法识别的字符*/
    {
        buff[0]=ch;
        buff[1]='\0';
        ch=fgetc(fp);
        fseek(fp,-1,1);
        cout<<buff<<"\t非法字符"<<endl;
    }
}

int main()
{
    FILE *fp;
    char filename[20];
    cout<<"请输入你要打开的文件名（含后缀名）：";
L:  cin>>filename;
    fp=fopen(filename,"r"); /*以只读方式打开指定文件*/
    if((fp=fopen(filename,"r"))==NULL)   /*文件不存在输出错误*/
    {
        cout<<"文件名不存在！请重新输入：";
        goto L;
    }
    else
    {
        cout<<endl;
        while(ch!=EOF)
        {
            scan(fp);
        }
  A:    cout<<endl;
        cout<<"词法分析已结束！"<<endl;
        cout<<"按任意键结束......"<<endl;
    }
    fclose(fp);
    getch();
}
