# Game Table
For a competition of teams a game table as ranking shall be programmed.

## 1. Structure Type
Give a C/C++ structure type definition for a team with a C++ string for the name of the team and two integer numbers for the amount of collected points and the amount of done matches.


## 2. Initialisation Array
Define a function with a one-dimensional array of teams (having the data type defined in task 1) and the number of teams as parameters. In the body the name of each team shall be inputted and stored in the array as well as the collected points and done matches be set to value zero.

## 3. Output Game Table
Define a function with a one-dimensional array of teams (having the data type defined in task 1) and the number of teams as parameters. In the body a table with points, done matches and the name of the team as columns shall be written onto standard character output stream (see example below).

## 4. Choosing a Team
Define a function with a one-dimensional array of teams (having the data type defined in task 1) and the number of teams as parameters as well as an integer as return value. In the body a table with the team name of players and an index number in front shall be written onto standard character output stream and by inputting a number this team get chosen and its index returned by the function (see example below).

## 5. Store Game and Points For a Team
Define a function with a one-dimensional array of teams (having the data type defined in task 1), the number of teams, an (actual) array index of a team and a number of points as four parameters. In the body the indexed team shall get added the points, the number of done matches getting incremented and the team depending on its new total number of points getting sorted maybe higher above in the table (see example below).

## 6. Reset Game Table
Define a function with a one-dimensional array of teams (having the data type defined in task 1) and the number of teams as parameters. In the body all points of all teams and all numbers of done matches shall be reset to zero.

## 7. Menu
- first the number of teams gets asked and
- an arra exactly fitting in size being defined
- values in the array getting initialised by a call to the function defined in task 2 and the initial game table getting outputted.
- Afterwards by a small menu
- results from single matches shall be inputted and the ranking getting adjusted,the actual game table getting outputted or resetted
