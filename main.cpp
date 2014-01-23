#include <iostream>

/*	Start of Check Sudoku Questions	*/
//	cek nomor pada baris yang sudah diisi
bool checkRow(int grid[][9], int row, int col, int num){
	for(int kolom=col+1; kolom<9; kolom++){
		if(grid[row][kolom] == num){
			return true;
			break;
		}
	}
}

//	cek nomor pada kolom yang sudah diisi
bool checkCol(int grid[][9], int row, int col, int num){
	for(int baris=row+1; baris<9; baris++){
		if(grid[baris][col] == num){
			return true;
			break;
		}
	}
}

//	cek nomor pada box yang sudah diisi
bool checkBox(int grid[][9], int boxRow, int boxCol, int row, int col, int num){
	for(int baris=0; baris<3; baris++){
		for(int kolom=0; kolom<3; kolom++){
			if(grid[baris+boxRow][kolom+boxCol] == num && baris+boxRow != row && kolom+boxCol != col){
				return true;
				break;
			}
		}
	}
}

//	return true bila nomor telah digunakan pada baris / kolom / box
bool isSame(int grid[][9], int row, int col, int num){
	return 	checkRow(grid,row,col,num) ||
			checkCol(grid,row,col,num) ||
			checkBox(grid,row-row%3,col-col%3,row,col,num);
}

//	pencarian nomor yang sama pada soal sudoku
bool cekSudoku(int grid[][9]){	
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			if(grid[row][col] != 0){
				if(isSame(grid,row,col,grid[row][col])){
					return true;
					break;
				}
			}
		}
	}
}
/*	End of Check Sudoku Questions	*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
