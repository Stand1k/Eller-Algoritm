#include <time.h>
#include <windows.h> 
#include <stdio.h>
#include <conio.h>

const int rows = 15; //Ширина
const int columns = 30; //Высота

int count = 1;

unsigned char arr[rows][columns];
int int_arr[rows][columns];

char symbol;

	 void Init()
	 {
		 for (int r = 0; r < rows; r++) {
			 for (int c = 0; c < columns; c++)
			 {

				 if ((c == 0  || c == columns - 1) && r != 0) 
				 {
					 symbol = 124;
				 }
				 else if (r == 0 && (c > 0 && c < columns - 1) || r == rows - 1 && (c > 0 && c < columns - 1))
				 {
					 symbol = 95;
				 }
				 else
				 {
					 symbol = 32;
				 }

				 arr[r][c] = symbol;
			 }
		 }

		 for (int r = 0; r < rows; r++)
		 {
			 for (int c = 0; c < columns; c++) 
			 {
				 if (((c >= 0 && c < columns - 1) && (r > 0 && r < rows - 1))  ) 
				 {
					 int_arr[r][c] = count;
					 count++;
				 }
				
			 }
			 count = 0;
		 }
	 }

	 void setNumber() 
	 {
		 srand(time(NULL));
		 int randomize;

		 for (int r = 1; r < rows; r++) 
		 {
			 for (int c = 1; c < columns - 2; c++)
			 {
				 randomize = rand() % 100 + 1;
				 if (randomize <= 50 && c % 2 == 0)
				 {
					 int_arr[r][c] = -1;
					 arr[r][c] = 124;
				 }
				 else if(randomize > 50 )
				 {
					 int_arr[r][c + 1] = int_arr[r][c];
				 }
			 }
		 }

	 }

	 void setVertical() 
	 {
		 for (int r = 1; r < rows - 1; r++)
		 {
			 for (int c = 1; c < columns - 1; c += 2)
			 {
					 if ((arr[r][c] == arr[r][c + 1]))
					 {
						 int_arr[r][c + 1] = 0;
						 int_arr[r][c - 1] = 0;

						 arr[r][c + 1] = 95;
						 arr[r][c] = 95;
					
					 }
					 if ((arr[r][c - 1] == 124 && arr[r][c] == 95) && arr[r - 1][c] == 95)
					 {
						 arr[r][c] = 32;
					 }

					 if ((r == rows - 2) && (arr[r + 1][c] == 124 || arr[r + 1][c + 1 ] == 124))
					 {
						 arr[r][c] = 32;
						 arr[r][c + 1] = 32;
					 }
					 
				 }
			 }
		 }


	 void Render()
	 {
		 for (int r = 0; r < rows; r++)
		 {
			 printf("\n\t");
			 for (int c = 0; c < columns; c++)
			 {
				 symbol = arr[r][c];
				 printf("%c", symbol);
				 //Sleep(25); //Задержка на вывод
			 }
			 printf("\t");
		 }
	 }

int main()
{
	Init();
	setNumber();
	setVertical();

	Render();

	system("color a");

	_getch();
	return 0;
}