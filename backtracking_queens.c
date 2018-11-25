#include <stdio.h>

int N;
char board[100][100];

//Function to check if the position to place the queen is safe or not
int is_in_danger(int i,int j); 

//Function to place the queens in their optimal positions
int place_queens(int n);


int main()
{
	printf("Enter the size for the NxN board: ");
	scanf("%d",&N);

	int i,j;

	//Creating an empty board
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			board[i][j] = '*';
		}
	}

	printf("\n");

	//To place the queens in their positions
	place_queens(N);

	//Displaying the board for the user
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%c\t",board[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}



int is_in_danger(int i,int j)
{
	/*
		Function to check if the provided position is safe or not for placing a queen

		We do this by checking the adjacent rows, columns and diagonals
		
		@int i: The provided row value
		@int j: The provided column value
	*/
	int row_iter; // An iterator for checking the rows of the board
	
	int col_iter; // An iterator for checking the columns of the board

	// Checking the adjacent rows and columns for a potential queen attack
	// Since, it is an NxN board, rows and columns are equal, we need only a single iterator
	
	for(row_iter=0;row_iter<N;row_iter++)
	{
		//If there is a queen
		if( (board[row_iter][j])=='Q' || (board[i][row_iter])=='Q')
			return 1;
	}

	// Checking if the diagonals from the specified position for queen attacks
	for(row_iter=0;row_iter<N;row_iter++)
	{
		for(col_iter=0;col_iter<N;col_iter++)
		{
			/*
				
				Diagonal from lower-left corner to upper-right corner: Summation of coordinates(3+2,2+3,1+4)
				Diagonal from upper-left corner to lower-right corner: Difference of coordinates(1-2,2-3,3-4)

				Board:

				 1 2 3 4 5
				1  *   *
				2    * 
				3  *   *		 
			
			*/

			//Checking both diagonals
			if( ((row_iter+col_iter)==(i+j)) || ((row_iter-col_iter)==(i-j)) )
			{	
				//If there is a queen 
				if(board[row_iter][col_iter]=='Q')
				{
					return 1;
				}
			} 
		}
	}
	return 0;
}

int place_queens(int n)
{
	/*
		Function to place the queens in the ideal positions using Backtracking with recursion

		Before placing we check to see that the position is safe and that it is empty

		@int n: The number of queens to be placed
	*/

	//Base case for recursion
	//If this is attained, the chosen positions are ideal
	if(n == 0)
		return 1;

	int i,j;

	//Check the board before placing the queens
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			//Checking the conditions before placing the queen
			if( (!is_in_danger(i,j)) && (board[i][j]!='Q') )
			{
				//Placing the queen
				board[i][j]='Q';

				//Applying recursion to check if the current placement works with that of the remaining queens
				if( place_queens(n-1)==1 )
				{
					return 1;
				}

				//If not, then remove the queen from the position and try again
				board[i][j]='*';
			}
		}
	}
	return 0;
}
