#ifndef FILECONTROL
#define FILECONTROL
#include "includes.h"
class c_FileControl{
  public:
   ENUM_FILECONTROL_ERRO fileWriteString(const mystr,const mystr,const ENUM_FILECONTROL_WRITEMODE);
   ENUM_FILECONTROL_ERRO fileReadString(const mystr,mystr*);
  private:
   bool fileExist(const mystr);
   mystr getFileName(const mystr,const int);
   bool getNameExt(mystr*,mystr*,const mystr);

};

#include "fileExist.h"
#include "getNameExt.h"
#include "getFileName.h"
#include "fileWriteString.h"
#include "fileReadString.h"


#endif // FILECONTROL
