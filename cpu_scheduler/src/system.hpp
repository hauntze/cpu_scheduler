#ifndef System_HPP
#define System_HPP

#include "sysconfig.hpp"
#include <iostream>  

class System
{
  public:
    System();
    virtual ~System(){}
    void update();
    void allocate_mem(int amount);
    void deallocate_mem(int amount);
    void setconfig(int C, int M, int S, int Q);
    inline sysconfig getConfig() {
      return config;
    }
    inline int getAvailMem() {
      return avail_mem;
    }
    inline int getAvailDev() {
      return avail_dev;
    }
    inline int getRunTime() {
      return time;
    }
    friend std::ostream &operator<<(std::ostream &out, System &o);        
  protected:
    sysconfig config;
    int avail_mem;
    int avail_dev;
    int time;
};
#endif
