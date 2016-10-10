#include "Screen.hpp"



Screen::Screen ( int height, int width ){
  _height = height;
  _width = width;
  lastIndex = 0;

  _deathSquare = -1; // indicates unusable square

  _dead = false;
  _free = true;

  _munchie = NULL;
  _oldMunchVal = 0;
  _newMunchVal = 0;

  _screenGrid = new std::vector <Grid*>;
  _freeSpace = new int*[height];
  _next = NULL;

  _score = "";

  buildScreen ( height, width );

}

// builds screen and creates freepool and screengrid
void Screen::buildScreen( int height, int width ){
  // commented out couts here will write the free spaces to the 
  // console after execution
  int space = 0;
  int border = _deathSquare;

  // writes heading
  mvaddstr( 0, 1, "Wormy" );  
  if ( width > 15 )
    mvaddstr( 0, width - 10 , "Score:"); 
 
  for(int p = 0; p <= height + 1; ++p)
    _freeSpace[p] = new int[width];
  
  for (int j = 1; j < height + 1; j++ ){
    //  std::cout << "\r";
    mvaddch(j, 0, '*');
    mvaddch(j, width, '*');
    
    for (int i = 0; i <= width; i++ ){
      mvaddch(1, i, '*');
      mvaddch(height, i, '*');
      
      if (i == 0 || j == 1 || i == width || j == height ){
	_freeSpace[j][i] = border;
	//	std::cout << std::setw(4) << _freeSpace[j][i];
	
      }
      else{
 	Grid *sgrid = new Grid( j, i );
	_screenGrid->push_back( sgrid );
	_freeSpace[j][i] = space;
	
	//	std::cout << std::setw(4) << _freeSpace[j][i];
	space++;
      }
      
    }
    lastIndex = _screenGrid->size() - 1;
    //    std::cout << "\n";
  } 
  
}

// inserts cell into worm (unusable) space
void Screen::insert( Grid *g, Worm *wormy ){
  Grid *temp = new Grid ( g->getHeight(), g->getWidth() );

  _screenGrid->at(_freeSpace[g->getHeight()][g->getWidth()]) = _screenGrid->at( lastIndex );
  
  _freeSpace[_screenGrid->at(lastIndex)->getHeight()][_screenGrid->at(lastIndex)->getWidth()] =
    _freeSpace[temp->getHeight()][temp->getWidth()];
  
  lastIndex--;
  
  _freeSpace[g->getHeight()][g->getWidth()] = _deathSquare;
  
}
// frees space from worm and adds it back to pool
void Screen::free( Grid *g , Grid *p ){  
  _freeSpace[p->getHeight()][p->getWidth()] = lastIndex;
  _screenGrid->at(_freeSpace[p->getHeight()][p->getWidth()]) = _screenGrid->at(++lastIndex);

}

// checks if next space is a munchie
void Screen::munchCheck( Worm *wormy ){ 
  wormy->munch();  

  if ( isMunchie( _next ) ){
    wormy->addMunchie( _oldMunchVal );
  }

  insert ( wormy->prevHead(), wormy );
  
  if ( !wormy->munchin() ){
    wormy->moveTail( );
    free( wormy->freed(), wormy->tail() );// switches the info in tail with the previous node
  }  

} 
// spawns munchie
void Screen::spawnMunchie(){
  _oldMunchVal = _newMunchVal;
  _newMunchVal = (rand() % 9 + 1);

  _munchie = _screenGrid->at( rand() % lastIndex + 1);


  char v = '0' + _newMunchVal;
  
  mvaddch( _munchie->getHeight(), _munchie->getWidth(), v );

}
// checks if grid contains munchie
bool Screen::isMunchie( Grid *g ){
  if ( g->isEq( _munchie ) ){

    spawnMunchie();
    return true;
  }
  return false;
}

// moves the worm/place to the next grid
void Screen::next( Grid *g, Worm *wormy ){  
  munchCheck( wormy );
  _next = g;

}

// checks if the space is available
bool Screen::isFree( Grid *g ){
  if ( _freeSpace[g->getHeight()][g->getWidth()] == _deathSquare )    
    _free = false;

  return _free;
  
}

// where moves are read and applied to the board
void Screen::play( Worm *wormy ){   
  spawnMunchie();

  _next = new Grid ( _height/2, _width/2 );
  
  wormy->insertHead( _next );
  
  while ( isFree ( _next ) ){    
    mvaddstr( 0, _width , score ( wormy ) );
    
    if ( get_char() == 'l' ){
      next( wormy->right(), wormy );
      
    }
    if ( get_char() == 'h' ){
      next( wormy->left(), wormy );
      
    }   
    if ( get_char() == 'k' ){
      next( wormy->up(), wormy );
  
    } 
    if ( get_char() == 'j' ){
      next( wormy->down(), wormy ); 
  
    } 
    refresh();    
  }
  
  wormy->die();
 
}

// gets final score from worm
std::string Screen::finalScore( Worm *wormy ){
  _score = score( wormy );

  return _score;
}    
// allows score to be written to console
char const *Screen::score( Worm *wormy ){ 

  return  std::to_string( wormy->score() ).c_str();
}

// prints screen after execution (debugging)
void Screen::printScreen(){
  std::cout << "\n\n";
 for (int j = 1; j < _height + 1; j++ ){
    std::cout << "\r";
    
    for (int i = 0; i < _width + 1 ; i++ ){
      
      if (i == 0 || j == 1  || i == _width || j == _height ){
	std::cout << std::setw(4) << _freeSpace[j][i];
      }
      else{
	std::cout << std::setw(4) << _freeSpace[j][i];
		
      }
      
    }
    std::cout << "\n";
 }   
    
 std::cout << "\n" << lastIndex << "\n";

}
