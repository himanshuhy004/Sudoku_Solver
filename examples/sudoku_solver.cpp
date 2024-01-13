#include<iostream>
#include"../src/sudoku_solver.h"
#include"../src/sudoku_validator.h"
#include"../src/sudoku_generator.h"

int main() {
    int type;
    std::cout << "Choose method: \n";
    std::cout << "1. Random Puzzle\n2. Input Puzzle\n";

    std::cin >> type;
    if(type==1){
        sudoku::Grid grid = sudoku::generate_puzzle();
        std::cout << grid << std::endl;

        sudoku::solve(&grid);

        if (sudoku::is_valid_solution(grid)) {
            std::cout << "Solution is valid!\n";
            std::cout << grid << std::endl;
        } else {
            std::cout << "Something isn't working.\n";
        }
    }
    else if (type==2){
        std::cout << "Enter the unsolved Sudoku grid:\n";
        std::cout << "Note: Enter 'n' for 9 rows and 9 columns such that 0<=n<=9 where 0 is an empty cell\n";
        std::cout << "+-------+-------+-------+\n";
        sudoku:: Grid grid;
        std::cin >> grid;
        std::cout << grid << '\n';
        sudoku::solve(&grid);

        if (sudoku::is_valid_solution(grid)) {
            std::cout << "Solution is valid!\n";
            std::cout << grid << std::endl;
        } else {
            std::cout << "Something isn't working.\n";
        }
    }
    else{
        std::cout << "INVALID TYPE!\n";
    }
    return 0;
}
