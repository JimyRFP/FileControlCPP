#ifndef FILECONTROL_FILEREADSTRING
#define FILECONTROL_FILEREADSTRING
#include<stdio.h>
ENUM_FILECONTROL_ERRO c_FileControl::fileReadString(const mystr name,mystr *data){
 FILE *fHandle=fopen(name,FILECONTROL_READ);
 if(fHandle==NULL)return FILECONTROL_ERRO_OPENFILEERRO;
 c_StringFunctions strF;
 mystr read=NULL;
 char fChar=fgetc(fHandle);
 while(fChar!=EOF){
 strF.strAdd(&read,&fChar,0,1);
 fChar=fgetc(fHandle);
 }
 *data=read;
 fclose(fHandle);
 return FILECONTROL_ERRO_NOERRO;
};


#endif
