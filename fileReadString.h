#ifndef FILECONTROL_FILEREADSTRING
#define FILECONTROL_FILEREADSTRING
#include<stdio.h>
ENUM_FILECONTROL_ERRO c_FileControl::fileReadString(const mystr fileName,mystr *returnData){
 FILE *fileHandle=fopen(fileName,FILECONTROL_READ);
 if(fileHandle==NULL)return FILECONTROL_ERRO_OPENFILEERRO;
 mystr readData=NULL;
 char fChar=fgetc(fileHandle);
 while(fChar!=EOF){
 m_StrF.strAdd(&readData,(const mystr)&fChar,1);
 fChar=fgetc(fileHandle);
 }
 *returnData=readData;
 fclose(fileHandle);
 return FILECONTROL_ERRO_NOERRO;
};


#endif
