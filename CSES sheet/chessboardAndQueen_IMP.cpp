#include <iostream>
#include <vector>
using namespace std;

const int N = 8; // Size of the chessboard
int solCount = 0; // To count the number of solutions

// Arrays to track column and diagonal attacks
bool column[N] = {false};
bool diag1[2 * N] = {false}; // diag1 for r + c
bool diag2[2 * N] = {false}; // diag2 for r - c

void placeQueens(int row, const std::vector<std::string>& board) {
    if (row == N) {
        // All queens are placed successfully
        solCount++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (board[row][col] == '.' && !column[col] && !diag1[row + col] && !diag2[row - col + N]) {
            // Place the queen
            column[col] = true;
            diag1[row + col] = true;
            diag2[row - col + N] = true;

            // Recur to place the next queen
            placeQueens(row + 1, board);

            // Backtrack: remove the queen
            column[col] = false;
            diag1[row + col] = false;
            diag2[row - col + N] = false;
        }
    }
}

int main() {
    std::vector<std::string> board(N);

    // Read the chessboard configuration
    for (int i = 0; i < N; i++) {
        std::cin >> board[i];
    }

    // Start placing queens from the first row
    placeQueens(0, board);

    // Output the number of valid configurations
    std::cout << solCount << std::endl;

    return 0;
}










/* ---------------------------------------------------------------------

To solve the problem of placing eight queens on a chessboard with reserved squares, we can use a backtracking approach. The key points are:

Backtracking: This method will explore all possible placements of queens, ensuring that no two queens attack each other.
Reserved Squares: We will only place queens on free squares (denoted by .), while still accounting for the reserved squares (denoted by *).

Approach ---->>>>>
Data Structures: Use arrays to keep track of which columns and diagonals are attacked.
Recursive Backtracking: Place a queen in a valid position and recursively attempt to place the next queen.
Base Case: When all queens are placed successfully, count this configuration as a valid solution.


Explanation of the Code -------------->>>>>>>

Input Handling: The chessboard configuration is read into a vector of strings.
Tracking Attacks: We maintain arrays column, diag1, and diag2 to track whether a column or diagonal is already attacked.
Backtracking Function:
If all queens are placed (row == N), we increment the count.
We loop through each column in the current row and check if the square is free and not under attack.
If a queen can be placed, we mark the column and diagonals as attacked, call the function recursively to place the next queen, and then backtrack by unmarking the current position.
Output: Finally, the total count of valid placements is printed.

------------------------------------------------------------------------*/