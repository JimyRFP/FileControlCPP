#ifndef FILECONTROL_GETFILENAME
#define FILECONTROL_GETFILENAME
#include "fileControl.h"
 mystr c_FileControl::getFileName(const mystr name,const int ind=0){
   c_StringFunctions strF;
   const int size=strF.getStringLen(name);
   if(size<1)return NULL;
   mystr base=NULL;
   mystr ext=NULL;
   if(!getNameExt(&base,&ext,name))return NULL;
   mystr ret=NULL;
   strF.strAdd(&ret,base);
   if(ind>0){
    strF.strAdd(&ret,(mystr)"(");
    strF.strAdd(&ret,strF.integer2String(ind));
    strF.strAdd(&ret,(mystr)")");
   }
   if(ext!=NULL){
    strF.strAdd(&ret,ext);
   }
   free(ext);
   free(base);
   return ret;
  };

#endif
