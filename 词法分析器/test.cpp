#include<iostream>
using namespace std;
int main()
{
    int i,j,k;
    cout<<endl;
    for(i=1;i<5;i++)
    /*    ����Ϊ����ѭ��/
           ����Ϊ����ѭ��*

           ����Ϊ����ѭ��/*    */
      for(j=1;j<5;j++)
            for (k=1;k<5;k++)
            {
                if (i!=k&&i!=j&&j!=k)    //ȷ��i��j��k��λ������ͬ
                cout<<i<<endl<<j<<endl<<k<<endl;
            }
}
