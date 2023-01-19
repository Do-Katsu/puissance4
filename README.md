# **Connect Four Game**

This is a simple implementation of the classic game Connect Four written in C. The game allows two players to take turns placing tokens in a 7x7 grid with the goal of getting four tokens in a row horizontally, vertically, or diagonally.

## **How to play**

- ​	The game begins with an empty 7x7 grid.
- ​	Player 1 will place their token (X) by entering the column number (1-7) where they want to drop it.
- ​	Player 2 will then place their token (O) in the same way.
- ​	The game continues until one player gets four tokens in a row or the grid is full.
- ​	The game also includes a heart shape pattern with a name in the center to be printed when the game is over.

## **Game Functions**

- ​	initG(unsigned int tabl[TAILLE][TAILLE]): Initializes the game board to all zeroes.
- ​	afficheG(unsigned int tabl[TAILLE][TAILLE],unsigned int nbC): Prints the current state of the game board and the number of the current turn.
- ​	placeJeton(int numJoueur, unsigned int numCol, unsigned int tabl[TAILLE][TAILLE]): Allows the current player to place their token in the chosen column.
- ​	estPleine(unsigned int numC, unsigned int tabl[TAILLE][TAILLE]): Checks if the chosen column is full. If it is, the player will be prompted to choose another column.
- ​	heart(char name[20]): Prints a heart shape pattern with a name in the center of the shape.

## **How to run the game**

1. ​	Compile the source code using a C compiler.
2. ​	Run the executable file.
3. ​	Follow the prompts to play the game.

The game is a simple implementation of the Connect Four game which can be used as a starting point for more complex implementations. Have fun!
