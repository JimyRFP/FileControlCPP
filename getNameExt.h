#ifndef FILECONTROL_GETNAMEEXT
#define FILECONTROL_GETNAMEEXT

bool c_FileControl::getNameExt(mystr* base,mystr* ext,const mystr name){
 c_StringFunctions str;
 const int size=str.getStringLen(name);
 if(size<1)return false;
 int i=0;
 while(i<size){
    if(name[i]==FILECONTROL_DOT_ASC2)break;
    i++;
 }
 mystr baseRet=NULL;
 mystr extRet=NULL;
 if(i>0)
 str.strAdd(&baseRet,name,0,i);
 if(i+1<size)
 str.strAdd(&extRet,name,i,size-i);
 *base=baseRet;
 *ext=extRet;
 return true;
};


#endif
