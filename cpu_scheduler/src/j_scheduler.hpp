#ifndef JOB_SCHEDULER_HPP
#define JOB_SCHEDULER_HPP

#include "sjf.hpp"
#include <iostream>
#include "fifo.hpp"
#include "system.hpp"

class j_scheduler{

  public:
    j_scheduler();
    virtual ~j_scheduler(){}
    void submit(Job j, System sys);
    void update(System sys);
    inline SJF getH1() {
      return hold_1;
    }
    inline FIFO getH2() {
      return hold_2;
    }
    friend std::ostream &operator<<(std::ostream &out, j_scheduler &o);  

  protected:
    SJF hold_1;
    FIFO hold_2;
};

#endif 