#include "fifo.hpp"

using namespace std;

std::ostream &operator<<(std::ostream &out, FIFO &o)
{
    list<Job> data = o.getdata();
    out  << "Printing contents of FIFO queue" << endl;
  for (std::list<Job>::iterator it = data.begin(); it != data.end(); it++) {
      out << *it << endl;
    }
    return out;
}
FIFO::FIFO() {
}
void FIFO::push(Job obj) {
  data.push_back(obj);
}