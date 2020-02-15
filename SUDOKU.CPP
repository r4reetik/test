#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define UNASSIGNED 0
#define N 9
randomise();
void Effect(int grid[N][N])
{
	int i,j,k,l,m,n;
	for(i=0;i<N;i++)
	{
		if(i==0)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(187);
				}
				else
				{
					if(k==0)
					{
						cout<<char(201);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(203);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(209);
							}
							else
							{
								cout<<char(205);
							}
						}
					}
				}
			}
		}
		cout<<endl;
		for(j=0,l=0;j<37;j++)
		{
			if(j==0)
			{
				cout<<char(186);
			}
			else
			{
				if(j%12==0)
				{
					if(grid[i][l]==0)
					{
						cout<<' '<<random(9)<<' '<<char(186);
						++l;
					}
					else
					{
						cout<<' '<<grid[i][l]<<' '<<char(186);
						++l;
					}
				}
				else
				{
					if(j%4==0)
					{
						if(grid[i][l]==0)
						{
							cout<<' '<<random(9)<<' '<<char(179);
							++l;
						}
						else
						{
							cout<<' '<<grid[i][l]<<' '<<char(179);
							++l;
						}
					}
				}
			}
		}
		cout<<endl;
		if(i==2||i==5)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(185);
				}
				else
				{
					if(k==0)
					{
						cout<<char(204);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(206);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(216);
							}
							else
							{
								cout<<char(205);
							}
						}
					}
				}
			}
		}
		if(i==8)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(188);
				}
				else
				{
					if(k==0)
					{
						cout<<char(200);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(202);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(207);
							}
							else
							{
								cout<<char(205);
							}
						}
					}
				}
			}
		}
		if(i==0||i==1||i==3||i==4||i==6||i==7)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(182);
				}
				else
				{
					if(k==0)
					{
						cout<<char(199);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(215);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(197);
							}
							else
							{
								cout<<char(196);
							}
						}
					}
				}
			}
		}
	}
}
int Find_zero(int grid[N][N], int &row, int &col);
int Available(int grid[N][N], int row, int col, int num);
int Solution(int grid[N][N])
{
	int row, col;
	if (!Find_zero(grid, row, col))
	{
		return 1;
	}
	for (int num = 1; num <= 9; num++)
	{
		if (Available(grid, row, col, num))
		{
			grid[row][col] = num;
			if (Solution(grid))
			{
				return 1;
			}
			grid[row][col] = UNASSIGNED;
		}
	}
	return 0;
}
int Find_zero(int grid[N][N], int &row, int &col)
{
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (grid[row][col] == UNASSIGNED)
			{
				return 1;
			}
		}
	}
	return 0;
}
int Check_row(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
	{
		if (grid[row][col] == num)
		{
			return 1;
		}
	}
	return 0;
}
int Check_column(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
	{
		if (grid[row][col] == num)
		{
			return 1;
		}
	}
	return 0;
}
int Check_box(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			if(grid[row+boxStartRow][col+boxStartCol]==num)
			{
				return 1;
			}
		}
	}
	return 0;
}
int Available(int grid[N][N], int row, int col, int num)
{
    return !Check_row(grid, row, num) &&
	   !Check_column(grid, col, num) &&
	   !Check_box(grid, row - row%3 , col - col%3, num);
}
int In_row(int grid[N][N],int i,int j);
int In_column(int grid[N][N],int i,int j);
int In_box(int grid[N][N],int i,int j);
int Possible(int grid[N][N])
{
	int i,j,k,l;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(grid[i][j]!=0)
			{
				if(In_row(grid,i,j)==1)
				{
					return 0;
				}
				if(In_column(grid,i,j)==1)
				{
					return 0;
				}
				if(In_box(grid,i,j)==1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
int In_row(int grid[N][N],int i,int j)
{
	int k;
	for(k=0;k<N;k++)
	{
		if(grid[i][j]==grid[i][k]&&j!=k)
		{
			return 1;
		}
	}
	return 0;
}
int In_column(int grid[N][N],int i,int j)
{
	int k;
	for(k=0;k<N;k++)
	{
		if(grid[i][j]==grid[k][j]&&i!=k)
		{
			return 1;
		}
	}
	return 0;
}
int In_box(int grid[N][N],int i,int j)
{
	int box_r,box_c,row,col,r_lim,c_lim;
	box_r=((i+1)/3);
	switch(box_r)
	{
		case 0 :row=0;
			r_lim=3;
			break;
		case 1 :row=3;
			r_lim=6;
			break;
		case 2 :row=6;
			r_lim=9;
			break;
	}
	box_c=((j+1)/3);
	switch(box_c)
	{
		case 0 :col=0;
			c_lim=3;
			break;
		case 1 :col=3;
			c_lim=6;
			break;
		case 2 :col=6;
			c_lim=9;
			break;
	}
	for(row;row<r_lim;row++)
	{
		for(col;col<c_lim;col++)
		{
			if(grid[i][j]==grid[row][col]&&row!=i&&row!=j)
			{
				return 1;
			}
		}
	}
	return 0;
}
void Display_sudoku(int grid[N][N])
{
	int i,j,k,l,m,n;
	for(i=0;i<N;i++)
	{
		if(i==0)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(187);
				}
				else
				{
					if(k==0)
					{
						cout<<char(201);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(203);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(209);
							}
							else
							{
								cout<<char(205);
							}
						}
					}
				}
			}
		}
		cout<<endl;
		for(j=0,l=0;j<37;j++)
		{
			if(j==0)
			{
				cout<<char(186);
			}
			else
			{
				if(j%12==0)
				{
					if(grid[i][l]==0)
					{
						cout<<"   "<<char(186);
						++l;
					}
					else
					{
						cout<<' '<<grid[i][l]<<' '<<char(186);
						++l;
					}
				}
				else
				{
					if(j%4==0)
					{
						if(grid[i][l]==0)
						{
							cout<<"   "<<char(179);
							++l;
						}
						else
						{
							cout<<' '<<grid[i][l]<<' '<<char(179);
							++l;
						}
					}
				}
			}
		}
		cout<<endl;
		if(i==2||i==5)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(185);
				}
				else
				{
					if(k==0)
					{
						cout<<char(204);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(206);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(216);
							}
							else
							{
								cout<<char(205);
							}
						}
					}
				}
			}
		}
		if(i==8)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(188);
				}
				else
				{
					if(k==0)
					{
						cout<<char(200);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(202);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(207);
							}
							else
							{
								cout<<char(205);
							}
						}
					}
				}
			}
		}
		if(i==0||i==1||i==3||i==4||i==6||i==7)
		{
			for(k=0;k<37;k++)
			{
				if(k==36)
				{
					cout<<char(182);
				}
				else
				{
					if(k==0)
					{
						cout<<char(199);
					}
					else
					{
						if(k%12==0)
						{
							cout<<char(215);
						}
						else
						{
							if(k%4==0)
							{
								cout<<char(197);
							}
							else
							{
								cout<<char(196);
							}
						}
					}
				}
			}
		}
	}
}
void main()
{
	clrscr();
	int grid[N][N],eff[N][N],i,j,l,m,eff_i;
	char temp;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			grid[i][j]=0;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			clrscr();
			cout<<"You Sudoku is-----"<<endl;
			Display_sudoku(grid);
			cout<<endl<<endl;
			cout<<"Please enter a value for ["<<i+1<<"]["<<j+1<<"] position.";
			temp=getch();
			if(temp>='1'&&temp<='9')
			{
				grid[i][j]=temp-48;
			}
			else
			{
				grid[i][j]=0;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			eff[i][j]=grid[i][j];
		}
	}
	for(eff_i=0;eff_i<71;eff_i++)
	{
		clrscr();
		cout<<"Solving Sudoku..."<<endl;
		Effect(eff);
		delay(52);
	}
	clrscr();
	if(Possible(grid)==1)
	{
		if(Solution(grid)==1)
		{
			cout<<"Solved Sudoku is-----"<<endl;
			Display_sudoku(grid);
		}
		else
		{
			cout<<"No solution exists.";
		}
	}
	else
	{
		cout<<"Entered Sudoku is not valid.";
	}
	getch();
}