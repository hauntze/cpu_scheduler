#ifndef FIFO_HPP
#define FIFO_HPP

#include <list>
#include <iostream>  
#include <job.hpp>

class FIFO
{
  public:
    FIFO();
    virtual ~FIFO(){};
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
    friend std::ostream &operator<<(std::ostream &out, FIFO &o);  
    
  protected:
  std::list<Job> data ;
};
#endif
