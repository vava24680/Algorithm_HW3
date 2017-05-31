
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
	row size:first_size
	col size:second_size
*/


void LCS(int* X, int* Y, int* C)
{
	int* first_string = X;
	int* second_string = Y;
	int first_size = X[0];//First string length
	int second_size = Y[0];//Secode string length
	int** lcs_length_table;
	lcs_length_table = new int*[first_size];
	for(int i=0;i<first_size;i++)
	{
		lcs_length_table[i] = new int[second_size];
	}
	//set first row of lcs_length_table to zero
	for(int j=0;j<second_size;j++)
	{
		lcs_length_table[0][j] = 0;
	}
	//set first column of lcs_length_table to zero
	for(int i=0;i<first_size;i++)
	{
		lcs_length_table[i][0] = 0;
	}
	for(int i=1;i<=first_size;i++)
	{
		for(int j=1;j<=second_size;j++)
		{
			if(first_string[i]==second_string[i])
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
				lcs_length_table[i][j] = lcs_length_table[j][i-1];
			}
		}
	}
}

void extract_LCS(int* first_string, int* dst_string, int** lcs_length_table, int row_index, int col_index)
{
	if(row_index==0 || col_index==0)
		return;
	if(lcs_length_table[row_index][col_index]==lcs_length_table[row_index-1][col_index])
	{
		extract_LCS(first_string,lcs_length_table,row_index-1,col_index);
	}
	else if(lcs_length_table[row_index][col_index]==lcs_length_table[row_index][col_index-1])
	{
		extract_LCS(first_string,lcs_length_table,row_index,col_index-1);
	}
	else
	{//Only extract the character out onlf if first_string[row_index]==second_string[col_index]
	 //Or it will not be called as Longest Common sequence.
		extract_LCS(first_string,lcs_length_table,row_index-1,col_index-1);
		dst_string[row_index] = first_string[row_index];
	}
}