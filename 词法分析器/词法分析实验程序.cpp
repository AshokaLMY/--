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
    if(isalpha(ch)) /*���������ĸ������ ��ʶ�� ����*/
    {
        buff[0]=ch;
        i=1;
        ch=fgetc(fp);
        while(isalnum(ch)) /*�������ĸ��������ϣ��������*/
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
        if(j>=83)   { cout<<buff<<"\t��ʶ��"<<endl; }
        else        { cout<<buff<<"\t�ؼ���"<<endl; }
    }
    else if(isdigit(ch))
    {
        buff[0]=ch;
        ch=fgetc(fp);
        i=1;
        while(isdigit(ch)) /*�������������������*/
        {
            buff[i]=ch;
            i++;
            ch=fgetc(fp);
        }
        buff[i]='\0'; /*�������Ͻ���*/
        fseek(fp,-1,1);
        cout<<buff<<"\t��"<<endl;
    }
    else if(strchr(fen,ch)>0) /*�жϷָ���*/
    {
        buff[0]=ch;
        ch=fgetc(fp);
        buff[1]='\0';
        fseek(fp,-1,1);
        cout<<buff<<"\t�������"<<endl;
    }
    else if(strchr(calc,ch)>0) /*�ж������*/
    {
        buff[0]=ch;
        if(ch=='=')           /*˫�����*/
        {
            ch=fgetc(fp);
            if(ch=='=')    {cout<<"=="<<"\t�����"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"="<<"\t�����"<<endl;
            }
        }
        else if(ch=='+')           /*˫�����*/
        {
            ch=fgetc(fp);
            if(ch=='+')    {cout<<"++"<<"\t�����"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"+"<<"\t�����"<<endl;
            }
        }
        else if(ch=='-')           /*˫�����*/
        {
            ch=fgetc(fp);
            if(ch=='-')    {cout<<"--"<<"\t�����"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"-"<<"\t�����"<<endl;
            }
        }
        else if(ch=='>')
        {
            ch=fgetc(fp);
            if(ch=='=')     {cout<<">="<<"\t�����"<<endl;}
            else if(ch=='>')  {cout<<">>"<<"\t�������"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<">"<<"\t�����"<<endl;
            }
        }
        else if(ch=='<')
        {
            ch=fgetc(fp);
            if(ch=='=')      {cout<<"<="<<"\t�����"<<endl;}
            else if(ch=='<')  {cout<<"<<"<<"\t�������"<<endl;}
            else
            {
                fseek(fp,-1,1);
                cout<<"<"<<"\t�����"<<endl;
            }
        }
        else if(ch=='!')
        {
            ch=fgetc(fp);
            if(ch=='=')      {cout<<"!="<<"\t�����"<<endl;}
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
                cout<<"ע��  "<<"//";
                while(ch!='\n')
                {
                    cout<<ch;
                    ch=fgetc(fp);
                }
                cout<<endl;
            }
            else if(ch=='*')
            {
                cout<<"ע��  "<<"/";
                while((ch=='*'&&(fgetc(fp))!='/')||ch!='*')
                {
                    cout<<ch;
                    ch=fgetc(fp);
                }
                cout<<"*/"<<endl;
            }
            else cout<<"/"<<"\t�����"<<endl;
        }
        else if(ch=='*')
        {
            ch=fgetc(fp);
            if(ch=='/')   {ch=fgetc(fp);}
            else cout<<"*"<<"\t�����"<<endl;
        }
        else if(ch=='&')
        {
            ch=fgetc(fp);
            if(ch=='&')   cout<<"&&"<<"\t�����"<<endl;
            else cout<<"&"<<"\t�����"<<endl;
        }
        else
        {
            ch=fgetc(fp);
            buff[1]='\0';
            fseek(fp,-1,1);
            cout<<buff<<"\t�����"<<endl;
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
            cout<<buff<<"\t�������"<<endl;
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
        cout<<buff<<"\""<<"\t�ַ���"<<endl;
    }
    else if(ch=EOF)
    {
        cout<<endl;
    }
    else            /*�޷�ʶ����ַ�*/
    {
        buff[0]=ch;
        buff[1]='\0';
        ch=fgetc(fp);
        fseek(fp,-1,1);
        cout<<buff<<"\t�Ƿ��ַ�"<<endl;
    }
}

int main()
{
    FILE *fp;
    char filename[20];
    cout<<"��������Ҫ�򿪵��ļ���������׺������";
L:  cin>>filename;
    fp=fopen(filename,"r"); /*��ֻ����ʽ��ָ���ļ�*/
    if((fp=fopen(filename,"r"))==NULL)   /*�ļ��������������*/
    {
        cout<<"�ļ��������ڣ����������룺";
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
        cout<<"�ʷ������ѽ�����"<<endl;
        cout<<"�����������......"<<endl;
    }
    fclose(fp);
    getch();
}
