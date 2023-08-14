****Class Team Members****
John Abraham
Dharmik Gowda
Noor Baig
********************
***IMPORTANT***
The constants bx and by are the number of rows and columns that needs to be changed manually when the maze file changes.
***************
We use bx and by to convert the maze into a 2D array, so that we can allow Michael to traverse through the 2D array(the maze).

The intel2.txt file contains our algorithm that essentially checks in all 4 directions from the current position and moves in the direction of 
the largest number of free spaces available.

functions.c file contains all of function definitions.
functions.h is our header file for our function definition.
maze.txt is the file that contains the maze.
main.c is where we run the code.

The starting position for Michael is found by searching through the entire first row for an empty space.
Michael mainly uses BJPI and the move functions to move.
In the CWF,CWB,CWL,CWR functions, Michael considers the good deeds(if any) as a free space but it doesnt actually know that there is a number there.

Moves.txt is the file where we write the actions performed by Michael. We also display the path travelled by Michael 
through the maze at the end of the Moves.txt file along with the number of good deeds collected, the total value of those good deeds, and the 
number of steps performed.

The program ends when there are no available free spaces in all 4 directions of Michael's current position.

The function file, header file and main files have to be connected to each other. In Dev-C++, they are all under a single project to connect them.

Sample Input in maze.txt file:
*** ****4*
*        *
*2** *****
*        *
** ***** *
*        *
* *** ** *
*        *
**** ***6*
** ***** *
*        *
* **2* * *
*        *
* * * ** *
*        *
*** ****8*
*        *
******** *
*        *
* **** ***
*        *
**6* ** **
*        *
**********

Sample Output in moves.txt:
MARK
PUSH
RP
CWF
MARK
PUSH
MOVE_F
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
MARK
PUSH
MOVE_F
CWF
MARK
PUSH
MOVE_F
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
CWF
CWL
CWR
CWB
BJPI
MARK
PUSH
***P****4*
*  PP   P*
*2**P*****
*   P   P*
** *****P*
*       P*
* *** **P*
*       P*
**** ***P*
** *****P*
*       P*
* **2* *P*
*       P*
* * * **P*
*       P*
*** ****P*
*       P*
********P*
*P      P*
*P**** ***
*PP     P*
**P* ** **
* PPPPPPP*
**********
THE END.
deedcount:3
deedvalue:20
Number of steps performed: 181
