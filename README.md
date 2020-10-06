# 42_fillit_bitwise
Fit tetrominoes in smallest possible square

This project was done as part of my education at Codam, part of the 42 network of coding schools.

This program was written in collaboration with Jesse Dunnink

<h3>Assignment</h3>

The object of this assignment is to write a program that accepts a collection of between 1 and 26 inclusive
tetrominoes and fits them on the smallest possible square map.

Tetrominoes cannot be rotated, every possible rotation of a tetromino is considered a unique tetromino.

Additionally, each tetromino has to be put in the most upper-left position it can be in within the solution
that renders the smallest square.

For example, if the tetrominoes we get to work with are:
1)\
#...\
#...\
#...\
#...

and
2)\
##..\
##..\
....\
....

The solution has to be:\
122.\
122.\
1...\
1...

Not, for example:\
221.\
221.\
..1.\
..1.

The full assignment can be found here:\
[fillit subject](https://github.com/LER1990/42_subjects/blob/master/fillit.en.pdf)

<h3>Solution</h3>

We started working on this in the following assumptions:

1. A map will never have to be bigger than 16 by 16 places
The maximum of 26 tetrominoes that each contain 4 occupied spaces means that any solution will have a maximum of 104
occupied spaces.
A map of size 16 will have 256 available spaces. Therefore, a map of this size would allow for 152 unoccupied spaces
in the solution, which is a loss of space of roughly 60%.
The nature of the tetrominoes makes it impossible to account for that much inefficiency in filling the map.

2. A map will never be smaller than the square root of the number of (assumed to be square) tetrominoes times four
(the number of spaces it occupies).

Our algorithm consists of the following steps:
1. Every tetromino is converted to a bit mask.  
First, we create a bit mask out of every tetromino. Then we translate the tetromino so that it is in the most upper-left position in a four by four grid.
2. We create a map with the calculated minimal size.
3. We recursively place all tetrominoes in the map in the following way:  
    1. We check whether a tetromino's width or height is bigger than the map size.  
    If so, we increase the map size.
    2. If we are working with large maps, we calculate whether the space that is available could theoretically fit the
  number of tetrominoes that still need to be placed.  
  If not, we increase the map size.
    3. We check whether a tetromino fits at the current x and y coordinate we are looking at in the map  
  If not, we shift through all available coordinates in the map until we either:
        * Find a place where it fits  
    If this is the case, we put the tetromino in the map and move on to the next one
        * Get to the bottom-right corner of the map  
    In which case we break out of a level of recursion and remove the last placed tetromino, then continue looking
    for a place for the tetromino that leads to a solution.
 
<h3>Optimization</h3>

Obviously, the level of recursion can get pretty deep in this algorithm. One of the ways we tried to limit the amount of
time it takes for our algorithm to find a solution (if there is one), is by doing all our operations on a bitwise level.
Our tetrominoes are stored as bit masks, that can be overlayed on our map and toggled relatively fast and efficiently.
This also makes checking whether a tetromino fits pretty straightforward. Every tetromino also contains information on 
where it was last placed. This is the starting point for new iterations of the algorithm, which means we never repeat any possible solutions.



