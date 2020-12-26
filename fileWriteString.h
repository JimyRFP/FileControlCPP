#ifndef FILECONTROL_FILEWRITESTRING
#define FILECONTROL_FILEWRITESTRING

ENUM_FILECONTROL_ERRO c_FileControl::fileWriteString(const mystr fname,const mystr data,const ENUM_FILECONTROL_WRITEMODE wMode){
 c_StringFunctions strC;
 mystr writeFileName=NULL;
 switch(wMode){
  case FILECONTROL_WRITEMODE_REWRITE:
   writeFileName=getFileName(fname,0);
   break;
  case FILECONTROL_WRITEMODE_NEWFILE:
   for(int i=0;i<FILECONTROL_MAXEQUALFILENAME;i++){
    writeFileName=getFileName(fname,i);
    if(!fileExist(writeFileName))break;
    free(writeFileName);
    writeFileName=NULL;
   }
   break;
  default:
    return FILECONTROL_ERRO_INVALIDWRITEMODE;
 };
 if(writeFileName==NULL)return FILECONTROL_ERRO_FILENAMEERRO;
 if(strC.getStringLen(data)<1)return FILECONTROL_ERRO_NODATA;
 FILE *fileH=fopen(writeFileName,FILECONTROL_WRITE);
 if(fileH==NULL)return FILECONTROL_ERRO_OPENFILEERRO;
 if(fputs((char*)data,fileH)==EOF){
    fclose(fileH);
    remove(writeFileName);
    return FILECONTROL_ERRO_WRITEFILEERRO;
 }
 fclose(fileH);
 return FILECONTROL_ERRO_NOERRO;
};

#endif
