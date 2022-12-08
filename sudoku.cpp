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
    vector<vector<int>> easy_q = {{9, 0, 1, 5, 6, 8, 4, 0, 7},
                                  {0, 7, 0, 0, 0, 0, 9, 1, 0},
                                  {2, 0, 5, 1, 9, 0, 6, 8, 0},
                                  {0, 1, 0, 0, 7, 0, 2, 0, 6},
                                  {3, 0, 4, 9, 0, 6, 0, 0, 1},
                                  {7, 6, 2, 8, 5, 0, 3, 4, 0},
                                  {5, 0, 3, 2, 0, 0, 0, 6, 4},
                                  {0, 9, 7, 6, 8, 0, 1, 3, 0},
                                  {1, 0, 0, 0, 3, 4, 5, 9, 0}};

    vector<vector<int>> mid_q = {{1, 0, 6, 4, 0, 0, 0, 0, 7},
                                 {0, 0, 9, 0, 0, 7, 0, 0, 0},
                                 {0, 0, 8, 9, 2, 0, 0, 4, 6},

                                 {0, 6, 0, 1, 0, 4, 2, 0, 0},
                                 {0, 8, 1, 0, 0, 0, 0, 3, 0},
                                 {2, 0, 0, 8, 0, 5, 6, 0, 1},

                                 {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 3, 4, 0, 6, 0, 7, 0, 0},
                                 {0, 1, 7, 0, 0, 0, 9, 6, 0}};

    vector<vector<int>> hard_q = {{0, 5, 8, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 2, 0, 8, 7, 9, 0, 0},
                                  {0, 0, 0, 0, 0, 4, 0, 0, 0},
                                  {0, 6, 0, 0, 0, 0, 0, 3, 0},
                                  {3, 0, 0, 0, 6, 0, 5, 0, 0},
                                  {0, 0, 0, 5, 0, 8, 7, 0, 4},
                                  {0, 9, 6, 3, 0, 0, 0, 7, 0},
                                  {0, 0, 1, 0, 0, 0, 0, 0, 9},
                                  {0, 0, 0, 8, 0, 0, 2, 5, 0}};

    vector<vector<int>> exp_q{{0, 0, 0, 0, 0, 0, 0, 2, 0},
                              {0, 0, 0, 0, 0, 7, 8, 0, 0},
                              {0, 8, 0, 0, 0, 3, 0, 0, 0},
                              {0, 4, 0, 0, 0, 0, 0, 0, 5},
                              {1, 0, 0, 0, 0, 0, 0, 6, 0},
                              {0, 7, 0, 0, 9, 0, 0, 0, 0},
                              {0, 9, 2, 0, 0, 0, 4, 0, 0},
                              {0, 0, 5, 4, 2, 0, 7, 0, 0},
                              {0, 0, 4, 5, 6, 0, 9, 8, 0}};
    vector<vector<int>> evil_q =
        {
            {0, 0, 7, 4, 0, 1, 0, 2, 9},
            {8, 0, 0, 0, 0, 0, 0, 0, 7},
            {0, 0, 0, 0, 0, 3, 0, 0, 0},
            {0, 5, 0, 0, 0, 0, 6, 0, 0},
            {0, 0, 8, 2, 0, 7, 0, 1, 0},
            {0, 0, 0, 0, 9, 0, 0, 0, 0},
            {0, 0, 4, 0, 3, 0, 0, 0, 0},
            {0, 0, 0, 0, 8, 0, 0, 9, 0},
            {6, 0, 0, 9, 0, 4, 1, 0, 0}};

    void swapTwoValues(vector<vector<int>> arr, int value1, int value2)
    {
        if (value1 == value2)
        {
            return;
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (arr[i][j] == value1)
                {
                    arr[i][j] = value2;
                    continue;
                }
                if (arr[i][j] == value2)
                {
                    arr[i][j] = value1;
                }
            }
        }
    }
    void swapTwoColumns(vector<vector<int>> arr, int col1, int col2)
    {
        for (int i = 0; i < 9; i++)
        {
            swap(arr[i][col1], arr[i][col2]);
        }
    }
    void shuffler(vector<vector<int>> &sudokuboard)
    {
        srand(time(0));
        int random[3] = {0, 3, 6};
        int m = rand() % 3;
        int n = (m+1)%3;
        swapTwoColumns(sudokuboard, random[m], random[n]);
        swapTwoColumns(sudokuboard, random[m] + 1, random[n] + 1);
        swapTwoColumns(sudokuboard, random[m] + 2, random[n] + 2);
        swap(sudokuboard[random[m]], sudokuboard[random[n]]);
        swap(sudokuboard[random[m] + 1], sudokuboard[random[n] + 1]);
        swap(sudokuboard[random[m] + 2], sudokuboard[random[n] + 2]);

        int z = (rand() % 2) + 1;
        swap(sudokuboard[random[3 - n - m]], sudokuboard[random[3 - n - m] + z]);
        srand(time(0));
        swapTwoValues(sudokuboard, (rand() % 9) + 1, (rand() % 9) + 1);
        swapTwoValues(sudokuboard, (rand() % 9) + 1, (rand() % 9) + 1);
        swapTwoValues(sudokuboard, (rand() % 9) + 1, (rand() % 9) + 1);
    }
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
        shuffler(easy_q);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(easy_q[i]);
        }
        helper(easy_q, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            realQues.push_back(question[i]);
            solution.push_back(easy_q[i]);
        }
    }
    void getMid()
    {
        shuffler(mid_q);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(mid_q[i]);
        }
        helper(mid_q, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            realQues.push_back(question[i]);
            solution.push_back(mid_q[i]);
        }
    }
    void getHard()
    {
        shuffler(hard_q);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(hard_q[i]);
        }
        helper(hard_q, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            realQues.push_back(question[i]);
            solution.push_back(hard_q[i]);
        }
    }
    void getExp()
    {
        shuffler(exp_q);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(exp_q[i]);
        }
        helper(exp_q, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            realQues.push_back(question[i]);
            solution.push_back(exp_q[i]);
        }
    }
    void getEvil()
    {
        shuffler(evil_q);
        for (int i = 0; i < 9; i++)
        {
            question.push_back(evil_q[i]);
        }
        helper(evil_q, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            realQues.push_back(question[i]);
            solution.push_back(evil_q[i]);
        }
    }
    void hint(vector<vector<int>> board, int row, int col)
    {
        cout << "Possible Moves on Pos (" << row << "*" << col << ") are:\n";
        row--;
        col--;
        if (board[row][col] == 0)
        {
            for (int i = 1; i <= 9; i++)
            {
                if (checkInLine(board, row, col, i) && checkInBox(board, row, col, i))
                {
                    cout << i << " ";
                }
            }
        }
        else
        {
            HANDLE console_color;
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color, 12);
            cout << "Pos (" << row + 1 << "*" << col + 1 << ") already filled.";
            SetConsoleTextAttribute(console_color, 7);
        }
        cout << endl;
    }
};

class Feature
{
public:
    void help()
    {
        printHyphen();
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 10);
        cout << "\n#  (Row no.)(Col no.) (Value) is used for filling the sudoku ,\n=>>12 4 ,here 12 are row and col and 4 is value to be filled.\n";
        cout << "\n#  focus digit is used for focusing on any digit of sudoku,\n=>>focus 1 ,here 1 will be highlighted.\n";
        cout << "\n#  quit is used for existing the problem.\n";
        cout << "\n#  hint (Row no.)(Col no.) will show you what are the possible number to be filled at that row-col, \n=>> hint 11,here all the possible digit to be filled at 11 will be displayed.\n";
        SetConsoleTextAttribute(console_color, 7);
        printHyphen();
    }
    void option()
    {
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 2);
        cout << "Commands are: \n(Row no.)(Col no.) (Value)";
        cout << "\nfocus digit\nquit\nhint (Row no.)(Col no.)\nhelp\n=>>";
        SetConsoleTextAttribute(console_color, 7);
    }
    void printHyphen()
    {
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 8);
        string sss(71, '-');
        cout << endl
             << sss << endl
             << endl;
    }
    void focus(vector<vector<int>> a, int digit)
    {
        system("cls");
        int cnt = 1;
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 8);
        for (int i = 0; i < 9; i++)
        {

            if (i % 3 == 0)
            {
                printHyphen();
            }
            for (int j = 0; j < 9; j++)
            {
                if (j == 0)
                {
                    SetConsoleTextAttribute(console_color, 9);
                    cout << cnt++;
                    SetConsoleTextAttribute(console_color, 8);
                    cout << "--->||  ";
                }
                else if (j % 3 == 0)
                {
                    SetConsoleTextAttribute(console_color, 8);
                    cout << "  ||  ";
                }
                if (a[i][j] == digit && digit != 0)
                {
                    cout << " ";
                    SetConsoleTextAttribute(console_color, 32);
                    cout << " " << a[i][j] << " ";
                    SetConsoleTextAttribute(console_color, 8);
                    cout << " ";
                }
                else if (a[i][j] == digit && digit == 0)
                {
                    cout << " ";
                    SetConsoleTextAttribute(console_color, 32);
                    cout << " _ ";
                    SetConsoleTextAttribute(console_color, 8);
                    cout << " ";
                }
                else if (a[i][j] == 0)
                {
                    cout << "  ";
                    SetConsoleTextAttribute(console_color, 8);
                    cout << "_";
                    cout << "  ";
                    continue;
                }
                else if (a[i][j] == realQues[i][j] && a[i][j] != 0)
                {
                    SetConsoleTextAttribute(console_color, 6);
                    cout << "  " << a[i][j] << "  ";
                    SetConsoleTextAttribute(console_color, 8);
                }
                else
                {
                    SetConsoleTextAttribute(console_color, 3);
                    cout << "  " << a[i][j] << "  ";
                    SetConsoleTextAttribute(console_color, 8);
                }

                if (j == 8)
                {
                    SetConsoleTextAttribute(console_color, 8);
                    cout << "  ||";
                }
            }
            cout << "\n\n";
            if (i == 8)
            {
                cout << "\n\t   ";
                for (int i = 1; i <= 9; i++)
                {
                    SetConsoleTextAttribute(console_color, 9);
                    cout << i;
                    SetConsoleTextAttribute(console_color, 8);
                    if (i == 9)
                        continue;
                    else if (i % 3 == 0)
                        cout << "_________>";
                    else
                        cout << "<~~>";
                }
                cout << endl;
                printHyphen();
            }
        }
        SetConsoleTextAttribute(console_color, 7);
    }
    void printBoard(vector<vector<int>> a)
    {
        system("cls");
        int cnt = 1;
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 8);
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
            {
                printHyphen();
            }
            for (int j = 0; j < 9; j++)
            {
                if (j == 0)
                {
                    SetConsoleTextAttribute(console_color, 9);
                    cout << cnt++;
                    SetConsoleTextAttribute(console_color, 8);
                    cout << "--->||  ";
                }
                else if (j % 3 == 0)
                {
                    cout << "  ||  ";
                }
                if (a[i][j] == 0)
                    cout << "  _  ";
                else if (a[i][j] == realQues[i][j])
                {
                    SetConsoleTextAttribute(console_color, 6);
                    cout << "  " << a[i][j] << "  ";
                    SetConsoleTextAttribute(console_color, 8);
                }
                else
                {
                    SetConsoleTextAttribute(console_color, 3);
                    cout << "  " << a[i][j] << "  ";
                    SetConsoleTextAttribute(console_color, 8);
                }
                if (j == 8)
                {
                    cout << "  ||";
                }
            }
            cout << "\n\n";
            if (i == 8)
            {
                cout << "\n\t   ";
                for (int i = 1; i <= 9; i++)
                {
                    SetConsoleTextAttribute(console_color, 9);
                    cout << i;
                    SetConsoleTextAttribute(console_color, 8);
                    if (i == 9)
                        continue;
                    else if (i % 3 == 0)
                        cout << "_________>";
                    else
                        cout << "<~~>";
                }
                cout << endl;
                printHyphen();
            }
        }
        SetConsoleTextAttribute(console_color, 7);
    }
    bool isFull(vector<vector<int>> arr)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (arr[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void makeMove(vector<vector<int>> &ques, vector<vector<int>> ans, int row, int col, int value)
    {
        int mistake_max = 4;
        cout << endl;

        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        if (value > 9 || value < 1)
        {
            mistake++;
            SetConsoleTextAttribute(console_color, 12);
            cout << "\nInvalid Move\nMistakes remaining " << mistake_max - mistake << endl;
            SetConsoleTextAttribute(console_color, 8);
        }

        if (value == ques[row - 1][col - 1])
        {
            printBoard(ques);
            SetConsoleTextAttribute(console_color, 12);
            cout << "\npos (" << row << "*" << col << ") already have a value.\n"
                 << endl;
            SetConsoleTextAttribute(console_color, 8);
        }
        else if (value == ans[row - 1][col - 1])
        {
            ques[row - 1][col - 1] = value;
            printBoard(ques);
        }
        else
        {
            mistake++;
            SetConsoleTextAttribute(console_color, 12);
            cout << "\nInvalid Move\nMistakes remaining " << mistake_max - mistake << endl;
            SetConsoleTextAttribute(console_color, 8);
        }
    }
};

class AllLevel : protected Sudoku, Feature
{
public:
    AllLevel()
    {
        getLevel();
        play();
    }
    int choice()
    {
        int n;
        string mode[6] = {"PAPER", "EASY", "MEDIUM", "HARD", "EXPERT", "EVIL"};
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 10);

        cout << "\nOPTIONS\n1: Easy\n2: Medium\n3: Hard\n4: Expert\n5: Evil\n=>>";
        cin >> n;
        cout << "\n\t\t\t----->" << mode[n] << " SUDOKU BEGINS IN<-----\n";
        cout << "\n\t\t\t----->     ";
        for (int i = 5; i >= 0; i--)
        {
            cout << i << "  ";
            Sleep(400);
        }
        SetConsoleTextAttribute(console_color, 7);
        return n;
    }
    void getLevel()
    {
        int c = choice();
        switch (c)
        {
        case 1:
            getEasy();
            break;
        case 2:
            getMid();
            break;
        case 3:
            getHard();
            break;
        case 4:
            getExp();
            break;
        case 5:
            getEvil();
            break;

        default:
            cout << "Plz enter a vaild option.\n";
            break;
        }
    }
    void play()
    {
        printBoard(question);
        string command;
        while (!isFull(question))
        {
            option();
            cin >> command;
            if (command == "focus")
            {
                int digit;
                cin >> digit;
                focus(question, digit);
            }
            else if (command == "hint")
            {
                int temp;
                cin >> temp;
                int r = temp / 10;
                int c = temp % 10;
                hint(question, r, c);
                cout << endl
                     << endl;
            }
            else if (command == "quit")
            {
                printBoard(solution);
                cout << "The Solution was:\n";
                cout << "Exiting in -->";
                for (int i = 5; i >= 0; i--)
                {
                    cout << i << "  ";
                    Sleep(1000);
                }
                return;
            }
            else if (command == "help")
            {
                printBoard(question);
                help();
            }
            else
            {
                bool flag = true;
                for (int i = 0; i < 2; i++)
                {
                    if (!isdigit(command[i]))
                        flag = false;
                }
                if (flag)
                {
                    int temp = stoi(command);
                    int r = temp / 10;
                    int c = temp % 10;
                    int v;
                    cin >> v;
                    if (mistake == 4)
                    {
                        cout << "\n\t\t----->Game Over<----- \n\n\n";
                        return;
                    }
                    makeMove(question, solution, r, c, v);
                }
                else
                {
                    cout << "Plz enter a vaild command." << endl;
                }
            }
        }
    }
};

int main()
{

    AllLevel obj;

    return 0;
}
