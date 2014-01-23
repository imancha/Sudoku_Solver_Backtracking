#include <iostream>

/*	Start of Searching Sudoku Solutions	*/
//	cek baris kolom yang kosong
bool isEmpty(int grid[][9], int &row, int &col){
	for(row=0; row<9; row++){
		for(col=0; col<9; col++){
			if(grid[row][col] == 0){
				return true;
				break;
			}
		}
	}
}

//	cek nomor pada baris
bool usedInRow(int grid[][9], int row, int num){
	for(int col=0; col<9; col++){
		if(grid[row][col] == num){
			return true;
			break;
		}
	}
}

//	cek nomor pada kolom
bool usedInCol(int grid[][9], int col, int num){
	for(int row=0; row<9; row++){
		if(grid[row][col] == num){
			return true;
			break;
		}
	}
}

//	cek nomor pada box
bool usedInBox(int grid[][9], int boxRow, int boxCol, int num){
	for(int row=0; row<3; row++){
		for(int col=0; col<3; col++){
			if(grid[row+boxRow][col+boxCol] == num){
				return true;
				break;
			}
		}
	}
}

//	return true bila nomor belum digunakan pada baris & kolom & box
bool isSafe(int grid[][9], int row, int col, int num){
	return 	!usedInRow(grid,row,num) &&
			!usedInCol(grid,col,num) &&
			!usedInBox(grid,row-row%3,col-col%3,num);
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
