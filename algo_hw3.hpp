
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
}