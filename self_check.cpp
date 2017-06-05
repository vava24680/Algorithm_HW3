#include "algo_hw3.hpp"
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main(void)
{
	while(1)
	{
		string input_1;
		string input_2;
		cout << "Input two string : (Input xxx to terminate)" << endl;
		cin >> input_1;
		cin >> input_2;
		if(input_1=="xxx" && input_2=="xxx")
		{
			break;
		}
		//cout << input_1 << endl;
		//cout << input_2 << endl;
		int len_input_1 = input_1.length();
		int len_input_2 = input_2.length();
		int* input_s_1 = new int[len_input_1+1];
		int* input_s_2 = new int[len_input_2+1];
		int* dst_s = new int[len_input_1+len_input_2];
		input_s_1[0] = len_input_1+1;
		input_s_2[0] = len_input_2+1;
		for(int i=1;i<=len_input_1;i++)
		{
			input_s_1[i] = static_cast<int>(input_1[i-1]);
		}
		for(int i=1;i<=len_input_2;i++)
		{
			input_s_2[i] = static_cast<int>(input_2[i-1]);
		}
		for(int i=0;i<len_input_1+len_input_2;i++)
		{
			dst_s[i] = -1;
		}
		LCS(input_s_1,input_s_2,dst_s);
		for(int i=0;i<len_input_1+len_input_2;i++)
		{
			if(dst_s[i]!=-1)
			{
				printf("%c",dst_s[i]);
			}
			else
				break;
		}
		cout << endl;
		if(input_s_1!=0)
			delete [] input_s_1;
		if(input_s_2!=0)
			delete [] input_s_2;
		if(dst_s!=0)
			delete [] dst_s;
	}
}