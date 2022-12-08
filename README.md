# Sudoko Game

## Participants:

    1.Ayush kumar
    2.Ravish kumar

  It is a Console Interface Program with Object-Oriented Approach written in C++ to play the Game of Sudoku which can handle some of the commands like:
  
    1. choose a mode of hardness out of 5 modes
    2. Followed by Some commands to play game by user 
        2.1 (Row no.)(Col no.) (Value)
        2.2 focus digit
        2.3 quit
        2.4 hint (Row no.)(Col no.)
        2.5 help
    
This Console Application serves as a user interface to the user to play and solve the sodoku with the given option of hint and focus .

## Table of Content:

        1. How to install and run the project
        2. Explanation of Project
        3. Tutorial of Project
        
### 1. How to install and run the project
        
        1. Open the Github Page where project is located.
        2. On top right corner click code buttton
        3. Copy HTTPS link
        4. use command "git clone < paste HTTPS link>"
        5. Then Compile and run the cpp file in your console.
        6. Choose the option on the display on the console and Enjoy the Game .
        
        (or)
        
        1. Open the Github Page where project is located.
        2. On top right corner click code buttton
        3. Click on Download Zip
        4. After download ,Extract the file 
        5. Then Compile and run the .cpp file in your console.
        6. Choose the option on the display on the console and Enjoy the Game.

###  2. Explanation of Project

        This project is based on object_Oriented Programmming
        The aim of this project is to apply OOPs concept to reduce , reuse and encapsulate it to improve the efficiency.
        
#### Class Structure of Project

        1. It consist of 3 classes , of which 
            - one class makes the question and answer ,
                + It makes the new question from the filled value of 5 modes of question with the help of suffling the positions of digits
                + And stores the solve solution of it
            - second class contains the features of the game and 
                + Features like hint,focus a column, etc
            - the third one deals with the user input and output.
        
###  3. Tutorial of Project


        After compiling the program on terminal or command prompt using command (g++ sudoku.cpp -o sudoku) in the same directory as of the code file.
        
        Run the file using command (./sudoku) or simply click on the sudoku.exe file gernerated by compiling the sudoku.cpp file
        
        It will give you interface like this:
        ![image](https://user-images.githubusercontent.com/98096047/206520547-18a46ec0-71dc-4a63-bdf4-749db0cb784d.png)

        Based on Your choice of hardness of level, it will display the game like this:
        ![image](https://user-images.githubusercontent.com/98096047/206521063-e4dcf550-bb29-4dc8-a4ae-3ae9efb3ed4a.png)
        
        ![image](https://user-images.githubusercontent.com/98096047/206521156-6071dddd-3bf3-424d-8b23-7bff82a554ff.png)
        
##### How to use the Commands (This also you can find by typing help in the console) :


        #  (Row no.)(Col no.) (Value) is used for filling the sudoku ,
            =>>12 8 ,here 12 are row and col and 8 is value to be filled.
            ![image](https://user-images.githubusercontent.com/98096047/206522483-8f9ff683-ec44-488b-84cc-b3932437258b.png)
            
            when entered wrong value
            ![image](https://user-images.githubusercontent.com/98096047/206522739-3a6e4796-79e9-4753-8d04-add8524bb788.png)


        #  focus digit is used for focusing on any digit of sudoku,
            =>>focus 1 ,here 1 will be highlighted.
            ![image](https://user-images.githubusercontent.com/98096047/206522071-ca5e20a4-1a9b-4e9f-919a-91b78a593168.png)


        #  quit is used for existing the problem.
            ![image](https://user-images.githubusercontent.com/98096047/206522191-ab71b1af-3f29-4d5c-810c-464fa3f2ce4e.png)


        #  hint (Row no.)(Col no.) will show you what are the possible number to be filled at that row-col,
            =>> hint 12,here all the possible digit to be filled at 11 will be displayed.
                ![image](https://user-images.githubusercontent.com/98096047/206522351-01bdbf89-0df8-4821-a52d-9f58d2f4b2a0.png)


## 4. UML DAIGRAM of Project

        ![uml-sudoku](https://user-images.githubusercontent.com/98096047/206471365-3a201f82-b9db-4c70-a453-49c63f50e784.png)
  
