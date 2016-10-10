#include "Grid.hpp"

Grid::Grid( int height, int width ){
  _height = height;
  _width = width;
}

void Grid::setHeight( int height ){
  _height = height;

}

void Grid::setWidth( int width ){
  _width = width;

}

void Grid::print(){
  std::cout<< " W: " << getWidth();
  
  std::cout << " H: " << getHeight();
}

bool Grid::isEq( Grid *g ){
  if ( _height == g->getHeight() && _width == g->getWidth())
    return true;

  else return false;

}

int Grid::getHeight(){
  return _height;
}

int Grid::getWidth(){
  return _width;
}

