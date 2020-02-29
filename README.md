# 42_fillit_bitwise
Fit tetrominoes in smallest possible square

This project was done as part of my education at Codam, part of the 42 network of coding schools.

This program was written in collaboration with Jesse Dunnink

<h3>Assignment</h3>

The object of this assignment is to write a program that accepts a collection of between 1 and 26 tetrominoes
and fits them on the smallest possible square map.

Additionally, each tetromino has to be put in the most upper-left position it can be in within the solution
that renders the smallest square.

For example, if the tetrominoes we get to work with are:
1)
#...
#...
#...
#...

and
2)
##..
##..
....
....

The solution has to be:
122.
122.
1...
1...

Not, for example:
221.
221.
..1.
..1.

The full assignment can be found here:\
[fillit subject](https://github.com/LER1990/42_subjects/blob/master/fillit.en.pdf)

<h3>Solution</h3>

We started working on this in the following assumptions:

1. A map will never have to be bigger than 16 by 16 places
The maximum of 26 tetrominoes that each contain 4 occupied spaces means that any solution will have a maximum of 104
occupied spaces
A map of size 16 will have 256 available spaces. Therefore, a map of this size would allow for 152 unoccupied spaces
in the solution, which is a loss of space of roughly 60%.
The nature of the tetrominoes makes it impossible to account for that much inefficiency in filling the map.

2. A map will never be smaller than the square root of the number of (assumed to be square) tetrominoes times four
(the number of spaces it occupies)

Our algorithm consists of the following steps:





