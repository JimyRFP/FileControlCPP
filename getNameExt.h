#ifndef FILECONTROL_GETNAMEEXT
#define FILECONTROL_GETNAMEEXT

bool c_FileControl::getNameExt(mystr* fileBaseName,mystr* fileExtension,const mystr fileName){
 const int size=m_StrF.getStringLen(fileName);
 if(size<1)return false;
 int i=0;
 while(i<size){
    if(fileName[i]==FILECONTROL_DOT_ASC2)break;
    i++;
 }
 if(i>0)
 m_StrF.strAdd(fileBaseName,(const mystr)fileName,i);
 if(i+1<size)
 m_StrF.strAdd(fileExtension,(const mystr)&fileName[i]);
 return true;
};


#endif
