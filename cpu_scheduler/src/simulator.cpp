#include "global.hpp"
#include <iostream>  
#include <fstream>
#include <stdio.h>
#include <limits>
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

fstream& GoToLine(fstream& file, unsigned int num){
  file.seekg(ios:::beg);
  int i;
  for(i = 0; i < num - 1; ++i){
    file.ignore(numeric_limits<streamsize>::max(),'\n');
  }
  return file;
}

void Simulator::begin() {
  int t = 1;
  int lt = 0;
  int lnum = 1;
  
  string currentline;
  
  char cline[];
  char *command;
  char *number;
  
  fstream fin;
  
  fin.open(filename);
  
  while(!fin.eof()){
    if(lt < t){
      lnum++;
      currentline = GoToLine(fin, lnum);
      cline = GoToLine(fin, lnum);
      command = strtok(cline, " ");
      number = strtok(NULL, " ");
      lt = (int)number;
    }
    else if(lt == t){
      if(command == "C"){}
      if(command == "A"){}
      if(command == "Q"){}
      if(command == "L"){}
      if(command == "D"){}
    }
    t++;
  }
  fin.close();
}
