#ifndef FILECONTROL_FILEWRITECSV_CPP
#define FILECONTROL_FILEWRITECSV_CPP
#include "defines.h"
#include "includes.h"

ENUM_FILECONTROL_ERRO c_FileControl::fileReadCsv(const mystr fileName,const char itemLineBreak,const char lineBreak,csvInfo **csvInfoReturn){
 mystr readData=NULL;
 ENUM_FILECONTROL_ERRO readFileErro=fileReadString((mystr)fileName,&readData);
 if(readData==NULL)return readFileErro;
 *csvInfoReturn=m_StrF.strToCsvStruct(readData,itemLineBreak,lineBreak);
 m_StrF.freeStr(&readData);
 return FILECONTROL_ERRO_NOERRO;
};

ENUM_FILECONTROL_ERRO c_FileControl::fileWriteCsv(const mystr fileName,
                                                const ENUM_FILECONTROL_WRITEMODE writeMode,
                                                const csvInfo*csvInfoSource,
                                                const char itemLineBreak,
                                                const char lineBreak
                                                ){
  mystr csvStr=m_StrF.csvStructToStr(csvInfoSource,itemLineBreak,lineBreak);
  if(csvStr==NULL)return FILECONTROL_ERRO_CONVERTCSVERRO;
  ENUM_FILECONTROL_ERRO erro=fileWriteString(fileName,csvStr,writeMode);
  m_StrF.freeStr(&csvStr);
  return erro;
}


#endif
