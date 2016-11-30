#include "global.hpp"
#include <iostream>  
#include <fstream>
#include <stdio.h>
#include "simulator.hpp"

using namespace std;

std::ostream &operator<<(std::ostream &out, Simulator &o)
{
  System sys = o.getSys();
  j_scheduler j_s = o.getJS();
  p_scheduler p_s = o.getPS();
  out << sys;
  out << j_s;
  out << p_s;
}
Simulator::Simulator(string filename) {
  filename = file;
}
void Simulator::update() {
  j_s.update(sys);
  p_s.update(sys);
}
void Simulator::submit(Job j) {
  int jm = j.getmmu();
  sysconfig config = sys.getConfig();
  int avail_mem = sys.getAvailMem();
  if (jm > config.main_memory) {
    cout << "Job memory exceeds System memory total" << endl;
    return;
  }
  if (jm > avail_mem) {
    j_s.submit(j, sys);
  } else {
    p_s.submit(j, sys);
  }
}
void Simulator::begin() {
  
}