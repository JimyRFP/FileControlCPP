#ifndef FILECONTROL_FILEWRITESTRING
#define FILECONTROL_FILEWRITESTRING

ENUM_FILECONTROL_ERRO c_FileControl::fileWriteString(const mystr fileName,
                                                     const mystr writeData,
                                                     const ENUM_FILECONTROL_WRITEMODE writeMode){
 if(m_StrF.getStringLen(writeData)<1)return FILECONTROL_ERRO_NODATA;
 mystr writeFileName=NULL;
 switch(writeMode){
  case FILECONTROL_WRITEMODE_REWRITE:
   writeFileName=getFileName(fileName,0);
   break;
  case FILECONTROL_WRITEMODE_NEWFILE:
   for(int i=0;i<FILECONTROL_MAXEQUALFILENAME;i++){
    writeFileName=getFileName(fileName,i);
    if(!fileExist(writeFileName))break;
    m_StrF.freeStr(&writeFileName);
   }
   break;
  default:
    return FILECONTROL_ERRO_INVALIDWRITEMODE;
 };
 if(writeFileName==NULL)return FILECONTROL_ERRO_FILENAMEERRO;
 FILE *fileHandle=fopen(writeFileName,FILECONTROL_WRITE);
 m_StrF.freeStr(&writeFileName);
 if(fileHandle==NULL){
    return FILECONTROL_ERRO_OPENFILEERRO;
 }
 int fPutsResult=fputs((char*)writeData,fileHandle);
 fclose(fileHandle);
 if(fPutsResult==EOF){
    return FILECONTROL_ERRO_WRITEFILEERRO;
 }else{
    return FILECONTROL_ERRO_NOERRO;
 }
};

#endif
