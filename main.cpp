#include <iostream>

<<<<<<< HEAD
/*        Start of Check Sudoku Questions        */
//        cek nomor pada baris yang sudah diisi
=======
/*	Start of Check Sudoku Questions	*/
//	cek nomor pada baris yang sudah diisi
>>>>>>> c4af9ab9e53c58b8f00585df9d1557a586033c37
bool checkRow(int grid[][9], int row, int col, int num){
        for(int kolom=col+1; kolom<9; kolom++){
                if(grid[row][kolom] == num){
>>>>>>> 427ae641f66966e58e62fdb11fced535099fdffe
                        return true;
                        break;
                }
        }
}

<<<<<<< HEAD
//        cek nomor pada kolom yang sudah diisi
=======
//	cek nomor pada kolom yang sudah diisi
>>>>>>> c4af9ab9e53c58b8f00585df9d1557a586033c37
bool checkCol(int grid[][9], int row, int col, int num){
        for(int baris=row+1; baris<9; baris++){
                if(grid[baris][col] == num){
>>>>>>> 427ae641f66966e58e62fdb11fced535099fdffe
                        return true;
                        break;
                }
        }
}

<<<<<<< HEAD
//        cek nomor pada box yang sudah diisi
=======
//	cek nomor pada box yang sudah diisi
>>>>>>> c4af9ab9e53c58b8f00585df9d1557a586033c37
bool checkBox(int grid[][9], int boxRow, int boxCol, int row, int col, int num){
        for(int baris=0; baris<3; baris++){
                for(int kolom=0; kolom<3; kolom++){
                        if(grid[baris+boxRow][kolom+boxCol] == num && baris+boxRow != row && kolom+boxCol != col){
>>>>>>> 427ae641f66966e58e62fdb11fced535099fdffe
                                return true;
                                break;
                        }
                }
        }
}

<<<<<<< HEAD
//        return true bila nomor telah digunakan pada baris / kolom / box
=======
//	return true bila nomor telah digunakan pada baris / kolom / box
>>>>>>> c4af9ab9e53c58b8f00585df9d1557a586033c37
bool isSame(int grid[][9], int row, int col, int num){
        return         checkRow(grid,row,col,num) ||
                        checkCol(grid,row,col,num) ||
                        checkBox(grid,row-row%3,col-col%3,row,col,num);
}

//        pencarian nomor yang sama pada soal sudoku
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
/*        End of Check Sudoku Questions        */
>>>>>>> 427ae641f66966e58e62fdb11fced535099fdffe
/*        Start of Searching Sudoku Solutions        */
//        cek baris kolom yang kosong
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

//        cek nomor pada baris
bool usedInRow(int grid[][9], int row, int num){
        for(int col=0; col<9; col++){
                if(grid[row][col] == num){
                        return true;
                        break;
                }
        }
}

//        cek nomor pada kolom
bool usedInCol(int grid[][9], int col, int num){
        for(int row=0; row<9; row++){
                if(grid[row][col] == num){
                        return true;
                        break;
                }
        }
}

//        cek nomor pada box
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

//        return true bila nomor belum digunakan pada baris & kolom & box
bool isSafe(int grid[][9], int row, int col, int num){
        return         !usedInRow(grid,row,num) &&
                        !usedInCol(grid,col,num) &&
                        !usedInBox(grid,row-row%3,col-col%3,num);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
        return 0;
}
