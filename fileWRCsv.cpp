#ifndef FILECONTROL_FILEWRITECSV_CPP
#define FILECONTROL_FILEWRITECSV_CPP
#include "defines.h"
#include "includes.h"

ENUM_FILECONTROL_ERRO c_FileControl::fileReadCsv(const mystr fname,const char itemLineBreak,const char lineBreak,csvInfo **ret){
 mystr data;
 ENUM_FILECONTROL_ERRO erro=fileReadString((mystr)fname,&data);
 if(erro!=FILECONTROL_ERRO_NOERRO)return erro;
 *ret=m_StrF.strToCsvStruct(data,itemLineBreak,lineBreak);
 return FILECONTROL_ERRO_NOERRO;
};

ENUM_FILECONTROL_ERRO c_FileControl::fileWriteCsv(const mystr fname,
                                                const ENUM_FILECONTROL_WRITEMODE wm,
                                                const csvInfo*info,
                                                const char itemLineBreak,
                                                const char lineBreak
                                                ){
  mystr data=m_StrF.csvStructToStr(info,itemLineBreak,lineBreak);
  if(data==NULL)return FILECONTROL_ERRO_CONVERTCSVERRO;
  ENUM_FILECONTROL_ERRO erro=fileWriteString(fname,data,wm);
  free(data);
  return erro;
}


#endif
