class Solution
{
public:
    bool isSafe(int row, int col, int grid[N][N], int val)
    {

        for (int i = 0; i < N; i++)
        {
            //         row check
            if (grid[row][i] == val)
            {
                return false;
            }
            //         col check
            if (grid[i][col] == val)
            {
                return false;
            }
            //         3x3 matrix check
            if (grid[3 * (row / 3) + i / 3][(3 * (col / 3)) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here

        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                //             cell empty
                if (grid[row][col] == 0)
                {
                    for (int val = 1; val <= 9; val++)
                    {
                        if (isSafe(row, col, grid, val))
                        {
                            grid[row][col] = val;
                            //                         recursive call
                            bool aageSolutionPossible = SolveSudoku(grid);
                            if (aageSolutionPossible)
                            {
                                return true;
                            }
                            else
                            {
                                //                             backtrack
                                grid[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        SolveSudoku(grid);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};
