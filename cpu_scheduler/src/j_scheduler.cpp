#include "j_scheduler.hpp"
#include <iostream>  
#include "system.hpp"

using namespace std;

std::ostream &operator<<(std::ostream &out, j_scheduler &o)
{
    SJF hold_1 = o.getH1();
    FIFO hold_2 = o.getH2();
	  out << "Displaying Hold_1 Content" << endl;
    out << hold_1;
	  out << "Displaying Hold_2 Content" << endl;
    out << hold_2;
}

void j_scheduler::submit(Job j, System sys) {
  
}

void j_scheduler::update(System sys) {
  
}

j_scheduler::j_scheduler() {
  
}