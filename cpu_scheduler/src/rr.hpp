#ifndef RR_HPP
#define RR_HPP

#include <list>
#include <iostream>  
#include <job.hpp>

class RR
{
  public:
    RR();
    virtual ~RR(){};
    void push(Job obj);
    inline void pop() {
      data.pop_front();
    }
    inline Job first() {
      return data.front();
    }
    inline Job last() {
      return data.back();
    }
    inline int size(){
      return data.size();
    }
    inline bool empty() {
      return data.empty();
    }
    inline std::list<Job> getdata() {
      return data;
    }
    friend std::ostream &operator<<(std::ostream &out, RR &o);  
    
  protected:
  std::list<Job> data ;
  
};
#endif
