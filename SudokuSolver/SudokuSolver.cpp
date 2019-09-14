//
// Created by zhang on 9/4/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    bool isValid(int i, int j, int c){
        for(int k=0; k<9; k++){
            if(sudoku_array[i][k]==c) return false;
            if(sudoku_array[k][j]==c) return false;
            if(sudoku_array[i-i%3+k/3][j-j%3+k%3]==c) return false;
        }
        return true;
    }

    bool solveSudoku(int i, int j){
        if(i==9) return true;
        if(j==9) return solveSudoku(i+1, 0);
        if(sudoku_array[i][j]!=0) return solveSudoku(i,j+1);
        for (int k = 1; k < 10; k++) {
            if(isValid(i,j,k)){
                sudoku_array[i][j] = k;
                if (solveSudoku(i,j+1))
                    return true;
                sudoku_array[i][j] = 0;
            }
        }
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        for(int i=0; i<9; ++i){
            for (int j = 0; j < 9; ++j) {
                char temp = board[i][j];
                sudoku_array[i][j] = temp =='.' ? 0 : board[i][j]-'0';
            }
        }
        showSudokuArray();

        solveSudoku(0,0);
        for(int i=1; i<9; i++){
            for (int j = 0; j < 9 ; j++) {
                board[i][j] = sudoku_array[i][j]+'0'-0;
            }
        }
        showSudokuArray();
    }

    void showSudokuArray(){
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << sudoku_array[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

private:
    int sudoku_array[9][9]={0};

};

int main(int argc, char** argv){
    std::vector<std::vector<char>> s ={
            { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    Solution sol;
    sol.solveSudoku(s);
}