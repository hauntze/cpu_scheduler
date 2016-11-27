#ifndef PROCESS_SCHEDULER_HPP
#define PROCESS_SCHEDULER_HPP

#include "sjf.hpp"
#include <iostream>
#include "rr.hpp"
#include "system.hpp"
class p_scheduler{

  public:
    p_scheduler();
    virtual ~p_scheduler(){}
    void submit(Job j, System sys);
    void update(System sys);
    inline RR getR() {
      return ready;
    }
    inline SJF getW() {
      return wait;
    }
    friend std::ostream &operator<<(std::ostream &out, p_scheduler &o);  
  protected:
    RR ready;
    SJF wait;
};

#endif 