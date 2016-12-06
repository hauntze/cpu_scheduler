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
	int t = 1; //value to store time
	int lt = 0; //value to store time from the line - set to 0 so it increments to 1
	int lnum = 0; //value to store line number in file - set to 0 so that it increments to 1

	int first, second, third, fourth, fifth; //used to store values 
	
	char currentline[];
	char *token; //to store string tokens
	char *command; //to store command of current line

	fstream fin;
	fin.open(filename);

	while(!fin.eof()){
		if(lt < t){
			lnum++;
			currentline = GoToLine(fin, lnum);
			token = strtok(cline, " MSQJRPD=");
			command = token;
			if(isdigit(command)){
				lt = (int)command;
			} else {
				token = strtok(NULL, " ");
				lt = (int)token;
			}
		}
		else if(lt == t){
			if(command == "C"){
				token = strtok(NULL, " ");
				first = (int)token;
				token = strtok(NULL, " ");
				second = (int)token;
				token = strtok(NULL, " ");
				third = (int)token;
				//do stuff
			}
			if(command == "A"){
				token = strtok(NULL, " ");
				first = (int)token;
				token = strtok(NULL, " ");
				second = (int)token;
				token = strtok(NULL, " ");
				third = (int)token;
				token = strtok(NULL, " ");
				fourth = (int)token;
				token = strtok(NULL, " ");
				fifth = (int)token;
				//do stuff
			}
			if(command == "Q"){
				token = strtok(NULL, " ");
				first = (int)token;
				token = strtok(NULL, " ");
				second = (int)token;
				//do stuff
			}
			if(command == "L"){
				token = strtok(NULL, " ");
				first = (int)token;
				token = strtok(NULL, " ");
				second = (int)token;
				//do stuff
			}
		}
		t++;
	}
	fin.close();
}
