#include "Worm.hpp"

Worm::Worm( int height, int width ){
  _maxSize = height * width - (height * 2  + width * 2 - 4);
  _headHeight = height/2;
  _headWidth = width/2;

  _size = 0;
  _score = 1; // actuall max score
  
  _dead = false;
  _munchin = false;
  
  tailIdx = 0;
  headIdx = 1;
  wormy = new Grid[_maxSize];

  _head = NULL;
  _neck = NULL;
  _tail = NULL;
  _freed = NULL;

}
// gets index (debugging)
void Worm::getIdx(){
  std::cout << "head Idx: "<< headIdx << std::endl;
  std::cout << "tail Idx: "<< tailIdx << std::endl;

}

void Worm::addMunchie ( int m ){
  _score = _size + m;
  std::cout << m;
}

bool Worm::munchin(){
  return _munchin;
}

void Worm::munch(){
  if ( _size <_score ){

    _munchin = true;
  }
  
  else 
    _munchin = false;
}

bool Worm::dead(){
  return _dead;
} 

void Worm::die(){
  _dead = true;
} 

int Worm::score(){
  return _size;

}
int Worm::size() const{
  return _size;
  
}

Grid *Worm::move( int height, int width ){
  _head = new Grid( height, width );
  _tail = &wormy[tailIdx % _maxSize];

  insertHead( _head );
  
  return _head;

  
}

Grid *Worm::right(){
  mvaddch( _headHeight, ++_headWidth, '@');
  return move( _headHeight, _headWidth );
 
}

Grid *Worm::left(){
  mvaddch( _headHeight, --_headWidth, '@');
  return move(  _headHeight, _headWidth  );

}

Grid *Worm::up(){
  mvaddch( --_headHeight, _headWidth, '@');
  return move(  _headHeight, _headWidth  );
}

Grid *Worm::down(){
  mvaddch( ++_headHeight, _headWidth, '@');  
  return move( _headHeight, _headWidth );
}


void Worm::insertHead( Grid *g ){    
  wormy[headIdx % _maxSize] = *g;
  headIdx = (headIdx + 1)%(_maxSize); 

  _size++;
    
}

Grid *Worm::grab( int idx ){  
  return &wormy[(tailIdx + idx) % _maxSize];

}

Grid *Worm::tail(){  
  _tail = &wormy[tailIdx % _maxSize];
  return _tail;

}

Grid *Worm::head(){  
  return _head;

}

// gets node that was previously head
Grid *Worm::prevHead(){  
  _neck = &wormy[(headIdx + _maxSize - 2) % _maxSize ];
  mvaddch ( _neck->getHeight(), _neck->getWidth(), 'o');

  return _neck;

}

Grid *Worm::freed(){  
  _freed = &wormy[(tailIdx + _maxSize - 1) % _maxSize ];

  return _freed;

}

// moves tail if not munchin
void Worm::moveTail(){
  tailIdx = (tailIdx + 1 + _maxSize % _maxSize);  // Advance the read pointer

  _tail = &wormy[tailIdx % _maxSize];
  _size--;
  mvaddch ( _tail->getHeight(), _tail->getWidth(), ' ');

}
