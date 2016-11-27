#include "sjf.hpp"

using namespace std;

std::ostream &operator<<(std::ostream &out, SJF  &o)
{
    list<Job> data = o.getdata();
    out  << "Printing contents of SJF queue" << endl;
  for (std::list<Job>::iterator it = data.begin(); it != data.end(); it++) {
      out << *it << endl;
    }
    return out;
}
SJF::SJF() {
}
void SJF::push(Job obj) {
  data.push_back(obj);
  sort();
}
void SJF::sort() {
  
}