#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

/*        Start of Check Sudoku Questions        */
//        cek nomor pada baris yang sudah diisi
bool checkRow(int grid[][9], int row, int col, int num){
        for(int kolom=col+1; kolom<9; kolom++){
                if(grid[row][kolom] == num){
                        return true;
                        break;
                }
        }
}

//        cek nomor pada kolom yang sudah diisi
bool checkCol(int grid[][9], int row, int col, int num){
        for(int baris=row+1; baris<9; baris++){
                if(grid[baris][col] == num){
                        return true;
                        break;
                }
        }
}

//        cek nomor pada box yang sudah diisi
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

//        return true bila nomor telah digunakan pada baris / kolom / box
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

//        show backtracking prosses
void print(int grid[][9]){
        for(int row=0; row<9; row++){
                putchar(' ');
                for(int col=0; col<9; col++){
                        printf("%d",grid[row][col]);
                }
        }
}

//        pencarian solusi sudoku
bool solveSudoku(int grid[][9], int &iterasi){
        int row, col;
        
        if(!isEmpty(grid,row,col)){        
                return true;
        }else{
                for(int num=1; num<=9; num++){                        //        coba-coba nomor pada grid yang kosong
                        if(isSafe(grid,row,col,num)){                //        jika nomor belum digunakan pada baris, kolom & box
                                grid[row][col] = num;                        //        masukkan nomor pada grid yang kosong tersebut
                                
//                                print(grid); putchar('\n');                //        tampil proses backtracking                        
                                iterasi++;
                                                                
                                if(solveSudoku(grid,iterasi)){        // (rekursif) cek apakah dengan memasukkan nomor pada grid tersebut dapat menyelesaikan sudoku
                                        return true;
                                        break;                                                //        jika ia simpan nomor tersebut
                                }else{
                                        grid[row][col] = 0;                        //        jika tidak isi dengan 0 dan ganti dengan nomor yang lain
                                }                                
                        }
                }
        }
        
        return false;                                                                //        trigger backtracking
}
/*        End of Searching Sudoku Solutions        */

/*        Start of Print Sudoku Solved        */
void header(){
        for(int i=0; i<37; i++){
                if(i==0) cout << char(218);
                else if(i==36) cout << char(191);
                else if(i%4==0) cout << char(194);
                else cout << char(196);
        }        
}

void footer(int i){
        if(i == 8){
                for(int l=0; l<37; l++){
                        if(l==0) cout << char(192);
                        else if(l==36) cout << char(217);
                        else if(l%4==0) cout << char(193);
                        else cout << char(196);
                }
        }else{
                for(int k=0; k<37; k++){
                        if(k==0) cout << char(195);
                        else if(k==36) cout << char(180);
                        else if(k%4==0) cout << char(197);
                        else cout << char(196);
                }
        }        
}

void printSudoku(int grid[][9]){
        header();
        for(int row=0; row<9; row++){
                cout << endl << char(179);
                for(int col=0; col<9; col++){
                        cout << " " << grid[row][col] << " " << char(179);
                }
                putchar('\n');
                footer(row);
        }
}
/*        End of Print Sudoku Solved        */

int main(int argc, char** argv) {
        char lagi;
        char rid[9][9];
        int grid[9][9];
        
        do{
                system("cls");
                header();
                for(int row=0; row<9; row++){
                        cout << endl << char(179);
                        for(int col=0; col<9; col++){
                                cout << " "; rid[row][col] = getche(); cout << " " << char(179);
                                grid[row][col] = rid[row][col] - '0';
                        }
                        putchar('\n');
                        footer(row);
                }
        
                putchar('\n');                
        
        
                if(!cekSudoku(grid)){                                //        cek dulu soalnya, barangkali ada nomor yang sama pada baris / kolom / box
                        int iterasi = 0;
                        clock_t t;
                        t = clock();                        
                        
                        if(solveSudoku(grid,iterasi)){        //        pencarian solusi sudoku
                                putchar('\n');
                                printSudoku(grid);
                        }else{
                                printf("\n Tidak ada solusi yang mungkin...\n");
                        }
                        
                        t = clock() - t;
                        double time_taken = ((double)t)/CLOCKS_PER_SEC;
                
                        printf("\n\n %i steps, %f seconds...\n\n",iterasi,time_taken);                
                }else{
                        printf("\n Tidak ada solusi yang mungkin...\n");
                }
                
                do{
                        cout << "\n Input Lagi [Y/T] : "; lagi = getche();
                        lagi = toupper(lagi);
                }while(!(lagi == 'Y' || lagi == 'T'));
        }while(lagi == 'Y');
        getch();        
}
