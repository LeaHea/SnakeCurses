#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Worm.hpp"

using namespace std;

int main ()
{
  // Test for existence of file name argument
  //  if (argc < 2)
  // {
  //    cerr << "Usage: " << argv[0] << " <file-name>\n";
  //    exit (1);
  //  }
  // Test to see if file was opened
// ifstream ins (argv[1]);
//  if (ins.fail ())
// {
      //    cerr << "No file " << argv[1] << " found\n";
  //   exit (2);
  //  }

  Worm wormy ( 4, 4 ); 
  char action;
  int value;
  Grid *one = new Grid(1, 1);
  Grid *two = new Grid(2, 2);
  Grid *three = new Grid(3, 3);
  Grid *four = new Grid(4, 4);
  Grid *five = new Grid(5, 5);

  wormy.insertHead(one);
  wormy.insertHead(one);
  wormy.move( 9, 9 );
  wormy.left();
  wormy.head()->print();
  wormy.tail()->print();
  /*  if (wormy->insertHead (one)){
    std::cout << " inserted at front of list\n";
    one->print();
  }
  else
    std::cout << value << " not inserted at front of list\n";
  if (wormy->insertHead (two)){
    std::cout << " inserted at front of list\n";
    one->print();
  }
  else
    std::cout << " not inserted at front of list\n";
  if (wormy.insertHead (three)){
    std::cout << " inserted at front of list\n";
    one->print();
  }
  else
    std::cout << " not inserted at front of list\n";
  
  if (wormy->tail ( 0 ))
    std::cout << "Last value deleted from list\n";
  
  else
    std::cout << "Last value not deleted from list\n";
  */

  std::cout << "Size of Wormy: " << wormy.size();

  return 0;     
}
