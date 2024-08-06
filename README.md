# project games in C
* This is the first project in the introductory course to system programming in the C language, instructions for the project are in a PDF file in Hebrew
* this project has a menu with two games:
  1. Biggest Matrix Sum
  2. color game  
* The project must be run in Linux
## Biggest Matrix Sum
the game is to find the biggest matrix sum in a large matrix,
doFindMaxSubMatrix, which searches within the large matrix for a submatrix whose members are the sum
is the maximum. Only places where the small matrix enters in full must be taken into account
in the big matrix.
The parameters this function accepts are:
• The matrix
•Number of Rows
• Number of columns
•Number of rows of the submatrix
• Number of columns of the sub-matrix
The function returns:
• the sum of the maximal submatrix
• With the help of the index pointer, starting with 0, the upper and lower row is the submatrix
(in example above 6)
• Using the index pointer, starting at 0, the left column contains the submatrix
(in example above 8)
2.biggestMatrixSum – the main function of the exercise performs the following operations within
Division into functions (there is a need for at least 3 more functions in the exercise)
1. Defines a matrix with the size ROWS, rows and COLS. Columns must choose values ​​as you wish. Yes
print which values ​​to the screen.
2. The user receives two numbers that will define the effective size of the matrix so that a number
The rows will be between 1 and ROWS inclusive and the number of columns will be between 1 and COLS inclusive. Must be printed
Which values ​​to screen.
3. If you initialize the matrix with random numbers, you can choose a range as you wish, it must be defined of course
in the constants. The values ​​of the constants must be printed to the screen.
4. Prints the matrix
5. The user receives two additional numbers that will define the size of the submatrix to print values
If for the screen. (The size of the rows and columns in the submatrix should be smaller than the rows and columns
in the big matrix!!!.)
6. Call the function doFindMaxSubMatrix
7. Prints the maximum matrix and its sum (obtained from the function in the previous section)
8. If there is more than one submatrix with a maximum sum, the first one must be printed
found
## how to run
* clone this project into a LINUX system
```console
git clone <git url of this repo>
```
* run in the console make
```console
make
```
* run the project
```console
./game
```
