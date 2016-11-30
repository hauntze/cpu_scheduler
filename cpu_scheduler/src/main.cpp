#include "global.hpp"
#include <iostream>  
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "system.hpp"
#include "simulator.hpp"

using std::ifstream;
using namespace std;

int main() {
  string filename = "input_tests/t1.txt";
  Simulator sim(filename);
  sim.init(1,2,3,4);
  cout << sim;
  sim.begin();
}