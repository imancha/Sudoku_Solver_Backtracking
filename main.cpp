#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <conio2.h>

using namespace std;

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

//	pencarian solusi sudoku
bool solveSudoku(int grid[][9], int &iterasi){
	int row, col;
	
	/*	cek grid sudoku yang kosong	*/
	if(!isEmpty(grid,row,col)){
		/*	grid sudoku sudah tidak ada yang kosong	*/
		return true;
	/*	grid sudoku masih ada yang kosong	*/
	}else{
		/*	coba nomor dari 1-9	*/
		for(int num=1; num<=9; num++){
			/*	jika nomor belum digunakan pada baris, kolom , box	*/
			if(isSafe(grid,row,col,num)){
				/*	pilih nomor tersebut sebagai kandidat solusi pada grid yang dipilih	*/
				grid[row][col] = num;
				/*	langkah bertambah	*/
				iterasi++;
				/*	cek apakah sudoku sudah terselesaikan (rekursif)	*/
				if(solveSudoku(grid,iterasi)){
					/*	sudoku terselesaikan	*/
					return true;
					break;
				/*	sudoku tidak terselesaikan	*/
				}else{
					/*	isi kembali kandidat solusi dengan 0 &
					 *	ganti dengan nomor lain
					 *	jika masih mungkin	*/
					grid[row][col] = 0;
				}				
			}
		}
	}
	/*	trigger backtracking	*/
	return false;
}
/*	End of Searching Sudoku Solutions	*/

/*	Start of Print Sudoku Solved	*/
void instructions(){
	textcolor(8);
	/*	box instructions	*/
	for(int i=0; i<7; i++){
		for(int j=0; j<80; j++){
			/*	corner left top	*/
			if(i==0 && j==0) cout << char(218);
			/*	corner right top	*/
			else if(i==0 && j==79) cout << char(191);
			/*	corner left bottom	*/
			else if(i==6 && j==0) cout << char(192);
			/*	corner right bottom	*/
			else if(i==6 && j==79) cout << char(217);
			/*	border left and right	*/
			else if(j==0 || j==79) cout << char(179);
			/*	border top and bottom	*/
			else if(i==0 || i==2 || i==6) cout << char(196);
			/*	blank space	*/
			else cout << " ";
		}
	}
	
	gotoxy(24,2); cout << "PETUNJUK PENGGUNAAN SUDOKU SOLVER";
	gotoxy(5,4);  cout << "1. Isi Soal Sudoku pada board yang telah disediakan.";
	gotoxy(5,5);  cout << "2. Isi Soal Sudoku yang kosong dengan 0.";
	gotoxy(5,6);  cout << "3. Setelah Soal Sudoku diisi semua, tekan ENTER untuk melihat solusinya.";
	textcolor(7);
}

void board(int x, int y){	
	/*	box board	*/
	for(int i=0; i<19; i++){
		for(int j=0; j<37; j++){
			/*	corner left top	*/
			if(i==0 && j==0){ gotoxy(x+j,y+i); cout << char(218); }
			/*	corner right top	*/
			else if(i==0 && j==36){ gotoxy(x+j,y+i); cout << char(191); }
			/*	corner left bottom	*/
			else if(i==18 && j==0){ gotoxy(x+j,y+i); cout << char(192); }
			/*	corner right bottom	*/
			else if(i==18 && j==36){ gotoxy(x+j,y+i); cout << char(217); }
			/*	border row left	*/
			else if(i%2==0 && j==0){ gotoxy(x+j,y+i); cout << char(195); }
			/*	border row right	*/
			else if(i%2==0 && j==36){ gotoxy(x+j,y+i); cout << char(180); }
			/*	borer column top	*/
			else if(i==0 && j%4==0){ gotoxy(x+j,y+i); cout << char(194); }
			/*	border column bottom	*/
			else if(i==18 && j%4==0){ gotoxy(x+j,y+i); cout << char(193); }
			/*	border row and column	*/
			else if(i%2==0 && j%4==0){ gotoxy(x+j,y+i); cout << char(197); }
			/*	border row	*/
			else if(i%2==0){ gotoxy(x+j,y+i); cout << char(196); }
			/*	border column	*/
			else if(j%4==0){ gotoxy(x+j,y+i); cout << char(179); }
			/*	blank space	*/
			else{ gotoxy(x+j,y+i); cout << " "; }
		}		
	}
}

void sudokuQuestions(int grid[][9]){	
	clrscr();
	instructions();
	board(3,8);
	char crid[9][9];
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			gotoxy(col*3+col+5,row*2+9); 
			crid[row][col] = getche();
			grid[row][col] = crid[row][col] - '0';
		}
	}
	getch();	
}

void printSudoku(int grid[][9]){
	board(42,8);	
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			gotoxy(col*3+col+44,row*2+9);
			cout << grid[row][col];
		}
	}	
}
/*	End of Print Sudoku Solved	*/

int main(int argc, char** argv) {
	char lagi;	
	int grid[9][9];
	
	do{	
		/*	input sudoku questions	*/
		sudokuQuestions(grid);
		
		/*	check sudoku questions	*/	
		if(!cekSudoku(grid)){
			int iterasi = 0;
			clock_t t;
			t = clock();			
			
			/*	check sudoku solutions	*/
			if(solveSudoku(grid,iterasi)){	//	pencarian solusi sudoku				
				/*	sudoku solved	*/
				printSudoku(grid);
			}else{
				/* sudoku can't solved	*/
				gotoxy(44,17); printf("Tidak ada solusi yang mungkin...!");
			}
			
			t = clock() - t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC;
		
			gotoxy(46,27);printf("%i steps, %f seconds...",iterasi,time_taken);
		/*	sudoku questions wrong	*/
		}else{
			/*	sudoku can't solved	*/
			gotoxy(44,17); printf("Tidak ada solusi yang mungkin...!");
		}
		
		do{
			gotoxy(10,27); cout << "Input Lagi [Y/T]  :  "; lagi = getch();
			lagi = toupper(lagi);
		}while(!(lagi == 'Y' || lagi == 'T'));
	}while(lagi == 'Y');	
}
