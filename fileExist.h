#ifndef FILECONTROL_FILEEXIST
#define FILECONTROL_FILEEXIST
#include <stdio.h>
bool c_FileControl::fileExist(const mystr name){
  FILE* fHandle;
  fHandle=fopen(name,FILECONTROL_READ);
  if(fHandle!=NULL){
    fclose(fHandle);
    return true;
  }
  return false;
};


#endif
