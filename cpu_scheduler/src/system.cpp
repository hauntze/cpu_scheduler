#include "system.hpp"

using namespace std;

std::ostream &operator<<(std::ostream &out, System &o)
{
    int mem = o.getAvailMem();
    int dev = o.getAvailDev();
    int runtime = o.getRunTime();
    sysconfig config = o.getConfig();
	  out << "Displaying current System:" << endl;
    out << "Current Configuration:" << endl;
    out << "Start time:" << config.start_t << endl;
    out << "Total MMU:" << config.main_memory << endl;
    out << "Total Devices:" << config.devices << endl;
    out << "Quantum:" << config.quantum << endl;
    out << "Available Memory:" << mem << endl;
    out << "Available Devices:" << dev << endl;
    out << "Run time:" << runtime << endl;
}
void System::setconfig(int C, int M, int S, int Q) {
  config.start_t = C; // starting time
  config.main_memory = M; // total mmu
  config.devices = S; // total devices
  config.quantum = Q; // time quantum 
  avail_mem = M; // available memory
  avail_dev = S; // available devices
  time = C; // runtime
}
void System::update() {
  time++;
}
void System::allocate_mem(int amount) {
  avail_mem -= amount;
}
void System::deallocate_mem(int amount) {
  avail_mem += amount;
}
System::System() {
  
}