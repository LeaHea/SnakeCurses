#include <string>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>

#ifndef _GRID
#define _GRID


class Grid {

public:
  Grid() {};
  Grid( int height, int width );
  ~Grid(){};
  void setHeight( int height );
  void setWidth( int width );
  void print();
  bool isEq( Grid *g );
 
  int getHeight();
  int getWidth();

private:
  int _height, _width;
};

#endif
