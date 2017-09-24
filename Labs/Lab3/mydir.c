#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>


/*int main(int argc, char const *argv[]) {
  //char path[] = *argv[1];
  printf("%s\n", argv[1]);
  struct stat fi;
  size_t buffSize, nbytes;
  char* buff;
  buffSize = fi.st_size;
  if(buffSize == 0)
  buffSize = PATH_MAX;
  printf("%d\n", (int)buffSize);
  buff = malloc(buffSize);
  nbytes = readlink(argv[1], buff, buffSize);
  printf("%d\n", (int)nbytes);
  free(buff);
  return 0;
}
*/

int main(int argc, char const *argv[]) {
  int counter = 0;
  char buf[PATH_MAX];
  struct dirent *dir;
  DIR *refdir;

  if(argc == 1){
    refdir = opendir((getwd(buf)));

  }else{
    refdir = opendir(argv[1]);
  }

  while ((dir = readdir(refdir)) != NULL) {
    if((counter % 3) == 0){
      printf("\n");
    }
    printf("%-30s", dir->d_name);
    counter++;
  }
  printf("\n");
  return 0;
}
