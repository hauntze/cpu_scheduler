#ifndef JOB_HPP
#define JOB_HPP

#include <string>
#include <iostream>  

class Job
{
public:
		friend std::ostream &operator<<(std::ostream &out, Job &o);
    
    Job(int A, int J, int M, int S, int R, int P);
    ~Job(){}
    inline void run();
		inline int getdev(){ return device ;}
		inline int getmmu(){ return mmu ;}
		inline int getarr(){ return arr_t;}
    inline int getrem(){ return rem_t;}
    inline int getcompt() { return comp_t;}
    inline int getjob() { return job_num;}
		inline bool complete();
    inline int waitT();
    inline int TaT();
    inline std::string get_status() { return status;}
    inline void set_status(std::string ns) {status = ns;}

	protected:
		int arr_t; // arrival time
		int priority; // job priority, 1 or 2
		int mmu; // number of required main m
		int device; // number of devices this job uses
		int burst_t; //execution time
		int rem_t; //remaining execution time;
    int comp_t; //completion time
    int start_t; //start time
    int job_num;
	  std::string status; //job state
};
#endif
