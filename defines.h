#ifndef FILECONTROL_DEFINES
#define FILECONTROL_DEFINES
#define FILECONTROL_DOT_ASC2 46
#define FILECONTROL_WRITE "w"
#define FILECONTROL_READ  "r"
#define FILECONTROL_MAXEQUALFILENAME 500
#include <stdlib.h>
enum ENUM_FILECONTROL_WRITEMODE{
  FILECONTROL_WRITEMODE_NEWFILE,
  FILECONTROL_WRITEMODE_REWRITE,
};

enum ENUM_FILECONTROL_ERRO{
  FILECONTROL_ERRO_NOERRO,
  FILECONTROL_ERRO_INVALIDWRITEMODE,
  FILECONTROL_ERRO_FILENAMEERRO,
  FILECONTROL_ERRO_OPENFILEERRO,
  FILECONTROL_ERRO_WRITEFILEERRO,
  FILECONTROL_ERRO_NODATA,
  FILECONTROL_ERRO_CONVERTCSVERRO,
};




#endif
