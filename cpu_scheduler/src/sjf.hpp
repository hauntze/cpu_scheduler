#ifndef SJF_HPP
#define SJF_HPP

#include <list>
#include <iostream>  
#include <job.hpp>

class SJF
{
  public:
    SJF();
    virtual ~SJF(){};
    void push(Job obj);
    inline void pop() {
      data.pop_front();
    }
    void sort();
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
    friend std::ostream &operator<<(std::ostream &out, SJF &o);  
    
  protected:
  std::list<Job> data ;
};
#endif
