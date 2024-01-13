# Sudoku-Suite
A C++17-compatible header that provides useful functions which help with the solving, validation and generation of 9x9 Sudoku puzzles. 

## Contents
* [Usage](#usage)
* [Documentation](#documentation)
* [How It Works](#sudoku-solver---how-it-works)
* [Running the code](#running-the-code)

## Usage 

* Download the files in the `src/` directory and move it to your project's directory.
* Include the required header files, as shown below in the examples, and use the functions you need!
* **NOTE:** The code is incompatible with pre-C++17 versions. While compiling, you'll have to compile with the `--std=c++17` flag.
    * For example; when using the clang compiler, the compile command would be `c++ --std=c++17 /path/to/file.cpp`

## Documentation

There are **three functions** that Sudoku-Suite provides the developer, along with **one class**. They are as follows:-

* `Grid`
    *  An object that represents a 9x9 Sudoku grid. The `Grid` object does not validate the grid in any way, i.e, it only holds the grid and values inside it.
    * While initialising, if the given values are invalid, an `std::invalid_argument` exception is thrown.
    * *Check out the examples below to see how we can initialise and use this object!*
* `void solve(Grid *grid)`
    *  A function that takes in a pointer to a `Grid` object and solves the Sudoku puzzle present in it. Returns nothing.
    * If the puzzle cannot be solved, a `std::logic_error` exception is thrown.
* `bool is_valid_solution(Grid &grid)`
    *  A function that takes in a `Grid` object and returns a `bool` with a value of `true` if the `Grid` object contains a finished and valid Sudoku solution. 
* `Grid generate_puzzle()`
    *  A function that takes in nothing and returns a `Grid` object containing an unfinished Sudoku puzzle.

### Sudoku Solver - How It Works
This particular algorithm employs the use of backtracking, one of the more common methods to solve Sudoku puzzles. I've written a simple algorithm to give an idea of how the program works.

1. Start.
2. We start with the first empty cell.
3. We generate a list of possible valid values that can be filled in that cell.
4. We iterate over this list and start with the first value. This value is placed in the required cell.
5. We move on to the next cell. We again generate a list of possibilities. However, if no list can be generated, then this means that there is something wrong with the value of the previous cell. We then move back to the previous cell and place the next value on the generated list in the cell now. We repeat this step until the current cell has a valid value placed inside it.
6. We stop when we reach the 81st cell (the last cell in a Sudoku puzzle) and have placed a valid value.
7. The puzzle has now been solved.
8. Stop.

## Running The Code
* To run the code, compile `examples/sudoku_solver.cpp` and then run the executable produced.


