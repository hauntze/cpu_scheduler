#include "p_scheduler.hpp"
#include <iostream>  

using namespace std;

std::ostream &operator<<(std::ostream &out, p_scheduler &o)
{
    RR ready = o.getR();
    SJF wait = o.getW();
	  out << "Displaying Ready Queue Contents" << endl;
    out << ready;
	  out << "Displaying Wait Queue Content" << endl;
    out << wait;
}

void p_scheduler::submit(Job j, System sys) {
  
}

void p_scheduler::update(System sys) {
  
}

p_scheduler::p_scheduler() {
  
}