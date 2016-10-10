# SnakeCurses
This is a simple game of snake that uses c++ and the ncurses library

For all intents and porposes, we'll refer to the 'snake' as Wormy --this is a traditional snake game.
Wormy eats munchies and grows according to their corresponding value. If wormy runs into either
a wall or itself, it dies and the game is over.



My variables/vectors are organized as follows:

-My class "Grid" contains a width and height and represents
the individual grid spaces on the board.

-"Worm" is a circular array that contains the information and functions of wormy, I did the
function separately from screen so hypothetically they could act independently (good if 
someone felt like adding multiple worms or something)

-"Screen" contains information and functions of the board. It can spawn and translate 
munchies, as well as update and warp freepool and screengrid.

-FreeSpace is my vector of ints that indicate whether a space is free or not (I think it 
corresponds with Brett's "Grid") and ScreenGrid is my vector of Grid that contains individual 
gridcells on the board.
