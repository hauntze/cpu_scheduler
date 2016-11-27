#include "rr.hpp"

using namespace std;

std::ostream &operator<<(std::ostream &out, RR &o)
{
    list<Job> data = o.getdata();
    out  << "Printing contents of Round Robin queue" << endl;
  for (std::list<Job>::iterator it = data.begin(); it != data.end(); it++) {
      out << *it << endl;
    }
    return out;
}
RR::RR() {
}
void RR::push(Job obj) {
  data.push_back(obj);
}