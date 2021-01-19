#ifndef FILECONTROL_FILEEXIST
#define FILECONTROL_FILEEXIST
#include <stdio.h>
bool c_FileControl::fileExist(const mystr fileName){
  FILE* fileHandle;
  fileHandle=fopen(fileName,FILECONTROL_READ);
  if(fileHandle!=NULL){
    fclose(fileHandle);
    return true;
  }
  return false;
};


#endif
