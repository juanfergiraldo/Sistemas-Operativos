#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>

int main(){
  struct tms buf;
  clock_t count;
  count = times(&buf);
  //printf("%.9ld\n", (long)count);
  printf("%.3ld\t", (&buf)->tms_utime); //User time
  printf("%.3ld\n", (&buf)->tms_stime); //System time
  printf("%.3ld\t", (&buf)->tms_cutime); //User time of children
  printf("%.3ld\n", (&buf)->tms_cstime); //System time of children
  return 0;
}

/*
int main ()
{
   struct tms currentTime;
   times(&currentTime);
   printf("%d\n", currentTime.tms_stime);
   return 0;
}
*/
