#include "algo_hw3.hpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int* s1;
    int* s2;
    int* s3;
    string str1,str2;
    int s1_length,s2_length,s3_length,tmp;
    while(1)
    {
        cout<<"\nEnter string s1 and s2(enter zzz for both to terminate) "<<endl;
        cin>>str1;
        fflush(stdin);
        cin>>str2;
        fflush(stdin);

        if(str1=="zzz"&&str2=="zzz")
            break;

        s1_length=str1.length();
        s2_length=str2.length();

        s3_length=s1_length+s2_length;
        s1=new int[s1_length+1];//for s1[0] for size
        s2=new int[s2_length+1];//for s2[0] for size
        s3=new int[s3_length];

        s1[0]=s1_length+1;
        s2[0]=s2_length+1;

        for(int i=0;i<s3_length;i++)
            s3[i]=-1;

        for(int i=1;i<=s1_length;i++)
            s1[i]=str1[i-1];

        for(int i=1;i<=s2_length;i++)
            s2[i]=str2[i-1];
        LCS(s1,s2,s3);

        str1.clear();
        str2.clear();
        cout<<"\nFor the final result which is str3 is as ";
        for(int i=0;i<s3_length;i++)
            printf("%c ",s3[i]);
        delete s1;
        delete s2;
        delete s3;
    }
    return 0;
}
