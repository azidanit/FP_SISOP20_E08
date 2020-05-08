#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

void cstat(char *path)
{
    int fd;
  struct stat st;
  
  char *name = path;

  if((fd = open(path, 0)) < 0){
    printf(2, "stat: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
    printf(2, "stat: cannot stat %s\n", path);
    close(fd);
    return;
  }

  switch(st.type) {
    case T_FILE:
      printf(1, "File: %s\nType: %d (File)\nSize: %d\nDevice: %d\tInode: %d\tLinks: %d\n",name, st.type, st.size,st.dev,st.ino,st.nlink);
      break;

    case T_DIR:
      printf(1, "File: %s\nType: %d (Directory)\nSize: %d\nDevice: %d\tInode: %d\tLinks: %d\n",name, st.type, st.size,st.dev,st.ino,st.nlink);
      break;

    case T_DEV:
      printf(1, "File: %s\nType: %d(Device)\nSize: %d\nDevice: %d\tInode: %d\tLinks: %d\n",name, st.type, st.size,st.dev,st.ino,st.nlink);
      break;
  }
  close(fd);
}

int main(int argc, char *argv[])
{
  int i;
  if(argc < 2){
    printf(1, "[stat] [argument]\n");
    exit();
  }
  for(i=1; i<argc; i++)
    cstat(argv[i]);
  exit();
}
