#include "job.hpp"

using namespace std;

std::ostream &operator<<(std::ostream &out, Job &o)
{
	  out << "Job " << o.getjob();
    out << ": in " << o.get_status() << ".";
    if (o.complete()) {
      out << " Finished at: " << o.getcompt() << endl;
    } else {
      out << " Remaining time: " << o.getrem() << endl;
    }
    return out;
}

Job::Job(int A, int J, int M, int S, int R, int P){
  arr_t = A;
  priority = P;
  mmu = M;
  device = S;
  burst_t = R;
  job_num = J;
  rem_t = R;
  status = "Pending";
  comp_t = -1;
  
}

void Job::run(){
  if (rem_t > 0){
      --rem_t;
  }
}
bool Job::complete(){
  return rem_t == 0;
}
int Job::waitT() { return start_t - arr_t;}
int Job::TaT() { return comp_t - arr_t;}
