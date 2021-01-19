#ifndef FILECONTROL_GETFILENAME
#define FILECONTROL_GETFILENAME
#include "fileControl.h"
 mystr c_FileControl::getFileName(const mystr fileName,const int fileIndex=0){
   mystr fileNameBase=NULL;
   mystr fileNameExtension=NULL;
   mystr returnName=NULL;
   if(!getNameExt(&fileNameBase,&fileNameExtension,fileName))return NULL;
   m_StrF.strAdd(&returnName,fileNameBase);
   if(fileIndex>0){
    m_StrF.strAdd(&returnName,(mystr)"(",1);
    m_StrF.strAdd(&returnName,m_StrF.integer2String(fileIndex));
    m_StrF.strAdd(&returnName,(mystr)")",1);
   }
   if(fileNameExtension!=NULL){
    m_StrF.strAdd(&returnName,fileNameExtension);
   }
   m_StrF.freeStr(&fileNameBase);
   m_StrF.freeStr(&fileNameExtension);
   return returnName;
  };

#endif
