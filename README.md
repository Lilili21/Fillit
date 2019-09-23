# Fillit
Fillit is my project for School 21/42

Description: this is an analogue of the tetris game. You should read the card with tetrimino and arrange them so as to create the smallest square possible. The map begins to fill from the upper left corner.

Algorithm: we substitute tetrimins so far can add them to the minimum card. If it was not possible to substitute the tetrimino, the program returns to the previous tetrimino and rearranges it to the next available position. If there is no previous tetrimino, but the current one could not be substituted, then the card increases by + 1. The substitution algorithm works until the minimum available field is filled.

![example]https://github.com/Lilili21/Fillit/blob/master/img/Example.png
![resolve]https://github.com/Lilili21/Fillit/blob/master/img/Resolve.png
![solution]https://github.com/Lilili21/Fillit/blob/master/img/Solution.png
