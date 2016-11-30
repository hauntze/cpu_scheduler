#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include <string.h>
#include "job.hpp"
#include "system.hpp"
#include "j_scheduler.hpp"
#include "p_scheduler.hpp"

class Simulator
{
  public:
    Simulator(std::string filename);
    virtual ~Simulator(){}
    void submit(Job j);
    void update();
    void begin();
    inline void init(int C, int M, int S, int Q) {
      sys.setconfig(C,M,S,Q);
    }
    inline System getSys() {
      return sys;
    }
    inline j_scheduler getJS() {
      return j_s;
    }
    inline p_scheduler getPS() {
      return p_s;
    }
    friend std::ostream &operator<<(std::ostream &out, Simulator &o);        
  protected:
    System sys;
    j_scheduler j_s;
    p_scheduler p_s;
    std::string file;
};
#endif
