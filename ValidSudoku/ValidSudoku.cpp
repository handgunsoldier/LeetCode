//
// Created by zhang on 9/4/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::map<char, int> row[9], column[9], sub_box[9];
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char temp = board[i][j];
                if(temp!='.' ){
                    if(row[i][temp]++){
                        return false;
                    }
                    if(column[j][temp]++){
                        return false;
                    }
                    if(sub_box[i/3*3+j/3][temp]++){
                        sub_box[i/3*3+j/3][temp]++;
                        return false;
                    }
                }
            }
        }
        return true;
    }
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

    Solution solution;
    std::cout << solution.isValidSudoku(s) << std::endl;

}