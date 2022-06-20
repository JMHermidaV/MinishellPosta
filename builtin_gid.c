#include "minish.h"
int builtin_gid (int argc, char ** argv){
if(argc ==1){


    printf("La ID del grupo principal es: %d  Nombre del grupo: %s \n", getgid(), getgrgid(getgid())->gr_name);
    gid_t grouplist[NGROUPS_MAX];
    int ngroups = getgroups(NGROUPS_MAX, grouplist);
    for(int i=0; i < ngroups; i++){
        printf("La ID del grupo secundario %d es: %d - Nombre del grupo: %s\n", i, grouplist[i],getgrgid(grouplist[i])->gr_name);
    }
    return 0; 
}
else{
    printf("BUILTIN_GID ERROR");
    return 1;
}
   
}