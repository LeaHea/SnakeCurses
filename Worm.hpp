#include "Grid.hpp"
#include <iostream> 

#ifndef _WORM
#define _WORM

class Worm{
  
public:
  Worm( int height, int width );
  int size() const;
 
  Grid *move( int height, int width );
  
  Grid *left();
  Grid *right();
  Grid *up();
  Grid *down();
  void getIdx();
  int score();
  int getHead();
  bool munchin();
  void munch();

  void addMunchie( int m );
  bool dead();
  void die();

  void insertHead( Grid *G );
  Grid *grab( int idx );  
  Grid *head();  
  Grid *prevHead();   
  Grid *tail();  
  Grid *freed();
  void moveTail();

private:
  Grid *wormy;
  Grid *_head, *_tail, *_freed, *_neck;
  int _size, _headHeight, _headWidth, 
    headIdx, tailIdx, _maxSize, _score;
  bool _dead, _munchin;
};
    

#endif
