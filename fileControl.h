#ifndef FILECONTROL
#define FILECONTROL
#include "defines.h"

class c_FileControl{
  public:
   ENUM_FILECONTROL_ERRO fileWriteString(const mystr,const mystr,const ENUM_FILECONTROL_WRITEMODE);
   ENUM_FILECONTROL_ERRO fileReadString(const mystr,mystr*);
   ENUM_FILECONTROL_ERRO fileWriteCsv(const mystr,const ENUM_FILECONTROL_WRITEMODE,const csvInfo*,const char,const char);
   ENUM_FILECONTROL_ERRO fileReadCsv(const mystr,const char,const char,csvInfo**);
  private:
   bool fileExist(const mystr);
   mystr getFileName(const mystr,const int);
   bool getNameExt(mystr*,mystr*,const mystr);
   //OBJ
   c_StringFunctions m_StrF;

};
#include "includes.h"


#endif // FILECONTROL
