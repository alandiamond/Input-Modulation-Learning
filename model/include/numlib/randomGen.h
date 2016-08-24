/*--------------------------------------------------------------------------
   Author: Thomas Nowotny
  
   Institute: Institute for Nonlinear Dynamics
              University of California San Diego
              La Jolla, CA 92093-0402
  
   email to:  tnowotny@ucsd.edu
  
   initial version: 2002-02-01
  
--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------

  random number generator, initializes with system time, returns a random
  number according to am equipartition in [0,1];
  making use of the ISAAC random number generator; C++ Implementation
  by Quinn Tyler Jackson of the RG invented by Bob Jenkins Jr.
  
--------------------------------------------------------------------------*/
  
#ifndef RANDOMGEN_H
#define RANDOMGEN_H

#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include "isaac.hpp"
#include <assert.h>

class randomGen
{
 private:
  QTIsaac<8, unsigned long> TheGen;
  double a;
  
 public:
  explicit randomGen();
  randomGen(unsigned long, unsigned long, unsigned long);
  ~randomGen() { }
  void seedrand(unsigned long, unsigned long, unsigned long);
  double n();
};

class stdRG
{
 private:
  double themax;
    
 public:
  explicit stdRG();
  stdRG(unsigned int);
  ~stdRG() { }
  void seedrand(unsigned int);
  double n();
  unsigned long nlong();
};

//#include "randomGen.cc"

#endif
