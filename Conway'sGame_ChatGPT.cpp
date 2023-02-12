#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

const int ROWS = 30;
const int COLUMNS = 120;

void initialize_board(bool board[ROWS][COLUMNS]);
void print_board(bool board[ROWS][COLUMNS]);
int count_live_neighbors(bool board[ROWS][COLUMNS], int row, int col);
void update_board(bool board[ROWS][COLUMNS]);

int main()
{
    bool board[ROWS][COLUMNS];

    srand(time(NULL));
    initialize_board(board);

    while (true)
    {
        system("cls");
        print_board(board);
        update_board(board);
        usleep(100000);
    }

    return 0;
}

void initialize_board(bool board[ROWS][COLUMNS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            board[row][col] = (rand() % 2 == 1);
        }
    }
}

void print_board(bool board[ROWS][COLUMNS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            std::cout << (board[row][col] ? '*' : '-');
        }
        std::cout << std::endl;
    }
}

int count_live_neighbors(bool board[ROWS][COLUMNS], int row, int col)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLUMNS && (i != 0 || j != 0))
            {
                count += board[r][c];
            }
        }
    }
    return count;
}

void update_board(bool board[ROWS][COLUMNS])
{
    bool temp_board[ROWS][COLUMNS];

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            int live_neighbors = count_live_neighbors(board, row, col);
            if (board[row][col])
            {
                temp_board[row][col] = (live_neighbors == 2 || live_neighbors == 3);
            }
            else
            {
                temp_board[row][col] = (live_neighbors == 3);
            }
        }
    }

    for (int row = 0; row < ROWS; row++)
    {
        for (int col =0; col < COLUMNS; col++)
{
board[row][col] = temp_board[row][col];
}
}
}
//This code creates a 30x70 grid and randomly initializes it with either live or dead cells. It then continuously updates the grid according to the rules of Conway's Game of Life, and displays the current state of the grid on the console.

//Let me know if you have any questions!