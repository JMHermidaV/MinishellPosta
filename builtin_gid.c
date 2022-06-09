#include "minish.h"
int builtin_gid (int argc, char ** argv){
if(argc ==1){


    printf("La ID del grupo principal es: %d \n Nombre del grupo: %s ", getgid(), getgrgid(getgid())->gr_name);
    gid_t grouplist[NGROUPS_MAX];
    int ngroups = getgroups(NGROUPS_MAX, grouplist);
    for(int i=0; i < ngroups; i++){
        printf("La ID del grupo secundaro %d es: %d - Nombre del grupo: %s", i, grouplist[i],getgrgid(grouplist[i])->gr_name);
    }
    return 0; 
}
else{print("ERROR");}
   
}