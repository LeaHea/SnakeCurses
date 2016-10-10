#include "getChar.hpp"
#include "Worm.hpp"

#ifndef _SCREEN
#define _SCREEN

class Screen {

public:

  Screen( int width, int height );
  void buildScreen( int width, int height );
 
  bool isFree( Grid *g );
  void next( Grid *g, Worm *wormy );
  void insert( Grid *g, Worm *wormy );
  int getSpace( Grid g );
  bool deadWorm();
  void killWorm();
  void printScreen();
 
  std::vector <Grid*> *screenGrid() const { return _screenGrid; }
  
  bool isMunchie( Grid *g );
  void free( Grid *g, Grid *p );
  std::string finalScore ( Worm *wormy );
  char const *score( Worm *wormy);
  void munchCheck( Worm *wormy );
  void spawnMunchie();
  void play( Worm *wormy );


private:
  bool _free, _dead;
  int lastIndex;
  int _deathSquare, _oldMunchVal, _newMunchVal, _height, _width, idx;

  Grid *_next, *_tail, *_munchie;
  
  std::string _score;

  std::vector <Grid*> *_screenGrid;
  int **_freeSpace;
};


#endif
