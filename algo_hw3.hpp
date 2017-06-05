#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
// change this to your id
static const char* student_id = "0416005" ;


// do not edit prototype
void LCS(int *, int*, int*);

// X,Y are input strings, C is answer string
//
// data structure :
// length of array X is m+1, length of array Y is n+1, length of array C is m+n
// X[0] = m+1, Y[0] = n+1,
// all element of C are "-1"
// other datas are in [0,255] means the symble in ASCII or ANSI table


// you only allow declare a table with size (m+1)*(n+1)
//
// do your homework here
//

/*
	lcs_length_table will be like this
	**************
	**************
	**************
	**************
	**************
	row size:row_size
	col size:col_size
*/

void extract_LCS(const int* first_string,const int* second_string, int* dst_string, int** lcs_length_table, int row_index, int col_index, int dst_index);
void LCS(int* X, int* Y, int* C)
{
	int* first_string = X;
	int* second_string = Y;
	int* temp_dst_string = 0;
	int lcs_max_length = (first_string[0]-1<=second_string[0]-1) ? first_string[0]-1 : second_string[0]-1 ;
	int row_size = X[0];//First string length+1
	int col_size = Y[0];//Secode string length+1
	/*In the computing lcs_table, the first row and first column is preserved but not used, so our size must be string length plus 1*/
	int** lcs_length_table;
	lcs_length_table = new int*[row_size];
	for(int i=0;i<row_size;i++)
	{
		lcs_length_table[i] = new int[col_size];
	}
	//set first row of lcs_length_table to zero
	for(int j=0;j<col_size;j++)
	{
		lcs_length_table[0][j] = 0;
	}
	//set first column of lcs_length_table to zero
	for(int i=0;i<row_size;i++)
	{
		lcs_length_table[i][0] = 0;
	}
	/*First string is at position 1 to row_size-1
	  Second string is at position 1 to col_size-1*/
	for(int i=1;i<row_size;i++)
	{
		for(int j=1;j<col_size;j++)
		{
			if(first_string[i]==second_string[j])
			{
				lcs_length_table[i][j] = lcs_length_table[i-1][j-1]+1;
				//NO direction record
			}
			else if(lcs_length_table[i-1][j]>=lcs_length_table[i][j-1])
			{
				lcs_length_table[i][j] = lcs_length_table[i-1][j];
			}
			else
			{//lcs_length_table[i][j-1] is larger
				lcs_length_table[i][j] = lcs_length_table[i][j-1];
			}
		}
	}
	/*
	Temparay array to store the result of LCS
	Since I don't know how long the LCS is, I use a temparay array to store the result of LCS
	This temparay array length is the biggest length among two original strings
	And whole array initial value is -1 so I can distinguish where is the start of LCS after extract_LCS executed
	*/
	temp_dst_string = new int[lcs_max_length];
	for(int i=0;i<lcs_max_length;i++)
	{
		temp_dst_string[i] = -1;
	}
	/*The last three parameters have minus 1 is because of they represent the index of 0-based array*/
	extract_LCS(first_string,second_string,temp_dst_string,lcs_length_table,first_string[0]-1,second_string[0]-1,lcs_max_length-1);
	for(int i=0,j=0;i<lcs_max_length;i++)
	{
		if(temp_dst_string[i]!=-1)
		{
			C[j] = temp_dst_string[i];//Copy the result to C array
			j+=1;
		}
		else
			continue;
	}
	if(temp_dst_string!=0)
		delete [] temp_dst_string;
	for(int i=0;i<row_size;i++)
	{
		if(lcs_length_table[i]!=0)
			delete [] lcs_length_table[i];
	}
	if(lcs_length_table!=0)
		delete [] lcs_length_table;
}

void extract_LCS(const int* first_string, const int* second_string,int* dst_string,int** lcs_length_table, int row_index, int col_index, int dst_index)
{
	if(row_index==0 || col_index==0)
	//Terminal condition for recursive func. extract_LCS
		return;
	if(lcs_length_table[row_index][col_index]==lcs_length_table[row_index-1][col_index-1]+1 && first_string[row_index]==second_string[col_index])
	{//Equivalent to the "To left-up" move in b table
		extract_LCS(first_string,second_string,dst_string,lcs_length_table,row_index-1,col_index-1,dst_index-1);
		dst_string[dst_index]=first_string[row_index];
	}
	else if(lcs_length_table[row_index][col_index]==lcs_length_table[row_index-1][col_index])
	{//Equivalent to the "To up" move in b table
		extract_LCS(first_string,second_string,dst_string,lcs_length_table,row_index-1,col_index,dst_index);
	}
	else
	{//Equivalent to the "To left" move in b table
		extract_LCS(first_string,second_string,dst_string,lcs_length_table,row_index,col_index-1,dst_index);
	}
}