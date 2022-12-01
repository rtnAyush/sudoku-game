#include <bits/stdc++.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
int mistake = 0;
vector<vector<int>> realQues;

class Sudoku
{
private:
    vector<vector<int>> easyQ = {{9, 0, 1, 5, 6, 8, 4, 0, 7},
                                 {0, 7, 0, 0, 0, 0, 9, 1, 0},
                                 {2, 0, 5, 1, 9, 0, 6, 8, 0},

                                 {0, 1, 0, 0, 7, 0, 2, 0, 6},
                                 {3, 0, 4, 9, 0, 6, 0, 0, 1},
                                 {7, 6, 2, 8, 5, 0, 3, 4, 0},

                                 {5, 0, 3, 2, 0, 0, 0, 6, 4},
                                 {0, 9, 7, 6, 8, 0, 1, 3, 0},
                                 {1, 0, 0, 0, 3, 4, 5, 9, 0}};
    vector<vector<int>> midQ;
    vector<vector<int>> hardQ;
    void shuffler(vector<vector<int>> &sudokuboard);
    bool checkInBox(vector<vector<int>> arr, int r, int c, int value)
    {
        if (r >= 0 && r <= 2)
        {
            r = 0;
        }
        else if (r >= 3 && r <= 5)
        {
            r = 3;
        }
        else if (r >= 6 && r <= 8)
        {
            r = 6;
        }

        if (c >= 0 && c <= 2)
        {
            c = 0;
        }
        else if (c >= 3 && c <= 5)
        {
            c = 3;
        }
        else if (c >= 6 && c <= 8)
        {
            c = 6;
        }

        for (int i = r; i < (r + 3); i++)
        {
            for (int j = c; j < (c + 3); j++)
            {
                if (arr[i][j] == value)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkInLine(vector<vector<int>> arr, int r, int c, int value)
    {
        // check in that  colummn
        for (int i = 0; i < 9; i++)
        {
            if (arr[i][c] == value)
            {
                return false;
            }
        }
        //  check in that row
        for (int j = 0; j < 9; j++)
        {
            if (arr[r][j] == value)
            {
                return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<int>> &board, int row, int col)
    {
        // cout <<"###" <<row << col << endl;
        int n = board.size();
        if (row == n)
            return true;

        int nRow = 0, nCol = 0;
        if (col != n - 1)
        {
            nRow = row;
            nCol = col + 1;
        }
        else
        {
            nRow = row + 1;
            nCol = 0;
        }

        // cout << nRow << nCol << endl;
        if (board[row][col] != 0)
        {
            if (helper(board, nRow, nCol))
                return true;
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (checkInLine(board, row, col, i) && checkInBox(board, row, col, i))
                {
                    board[row][col] = i;
                    if (helper(board, nRow, nCol))
                        return true;
                    else
                        board[row][col] = 0;
                }
            }
        }
        return false;
    }

protected:
    vector<vector<int>> question;
    vector<vector<int>> solution;
    void getEasy()
    {
        shuffler(easyQ);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(easyQ[i]);
        }
        helper(easyQ, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            realQues.push_back(question[i]);
            solution.push_back(easyQ[i]);
        }
    }
    void getMid()
    {
        shuffler(midQ);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(midQ[i]);
        }
        helper(hardQ, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            solution.push_back(midQ[i]);
        }
    }
    void getHard()
    {
        shuffler(hardQ);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(hardQ[i]);
        }
        helper(hardQ, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            solution.push_back(hardQ[i]);
        }
    }
    void hint(vector<vector<int>> board, int row, int col)
    {
        cout << "Possible Moves on Pos (" << row << "*" << col << ") are:\n";
        row--;
        col--;
        for (int i = 1; i <= 9; i++)
        {
            if (checkInLine(board, row, col, i) && checkInBox(board, row, col, i))
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};
