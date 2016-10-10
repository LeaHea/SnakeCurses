#include "Screen.hpp"

void startup( void );
void terminate( void );

int main(int argc, char *argv[] )
{

  if( argc != 3 ) {
    std::cout << "invalid board dimentions.\n";
    exit(1);
  }
  
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);
  
  if( width < 9 || width > 80 ){
    std::cout << "Invalid width (must be between 9 and 80)\n";
    exit(1);
  }

  if( height < 9 || height > 25){
    std::cout << "Invalid height (must be between 9 and 25)\n";
    exit(1);
  }
  
 
  startup();
  
  height++;
 
  Worm *wormy = new Worm ( height, width );
  Screen *game = new Screen( height, width );
  
  move(height/2, width/2);
  addch( '@' );
  
  refresh();
   
  while (!wormy->dead()){
    game->play( wormy );

   }
  
  terminate();
  //  game->printScreen();
  std::cout << "Loser." << std::endl;
  std::cout << "Your score: " << game->finalScore( wormy ) << std::endl;

}

void startup( void )
{
     initscr();	 /* activate the curses */
     clear();	 /* clear the screen that curses provides */
     noecho();	 /* prevent the input chars to be echoed to the screen */
     cbreak();	 /* change the stty so that characters are delivered to the
		    program as they are typed--no need to hit the return key!*/
}

void terminate( void )
{
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     clear();
     refresh();
     endwin();
}
