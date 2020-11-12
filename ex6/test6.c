#include <unistd.h>

void main(int argc, char* argv[])
{
  if(argc == 1) { 
      printf("Usage: %s 프로그램 실행 실패 \n", argv[0]);
      return 1;    }

  pid_t p;
  p = fork();
  
    if(p == 0)  {
      wait(0);
    }
    
  else if(p < 0)    {
      perror("fork error"); 
      return 1;    }
      
  else{
      execvp(argv[1],argv+1); 
      //execvp(경로,인수목록)
      return 0;
    }
}

