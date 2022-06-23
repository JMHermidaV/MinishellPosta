// LIBERAR MEMORIA (names, path_directory, absolute_path)
#include "minish.h"

char permission_array[] = {'x', 'w', 'r'};
char permisos[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
DIR *d;
char *path_directory;
char archivo[MAXLINE][MAXLINE];

// Inprime los permisos del archivo
void permissions(int n){

    for(unsigned int i = 0; i < sizeof(n)*CHAR_BIT; i++){
        int bit = (n >> i) & 1;
        if(i < 9){
            if(bit == 0){
                permisos[i] = '-';
            }
            else permisos[i] = permission_array[i % 3];
        }
    }
    for(int i = 8; i >= 0; i = i - 1){
        printf("%c", permisos[i]);
    }
}


int list(char *path, char *filter){
    d = opendir(path);
    if(d){ // If is a directory:
        int n;
        for(n = 0; path[n] != '\0'; n++);
        if(path[n-1] != '/'){
            //path = realloc(path, sizeof(char)*(n+1));
            path[n] = '/';
            path[n+1] = '\0';
        }
        path_directory = strdup(path);
        struct dirent *dir;
        int i = 0;
        while((dir = readdir(d)) != NULL){

            if(filter == NULL){
                if(dir->d_name[0] != '.'){
                    strcpy(archivo[i], dir->d_name);
                    i++;
                }
            }
            
            else{
                if(dir->d_name[0] != '.' && strstr(dir->d_name, filter) != NULL){
                    strcpy(archivo[i], dir->d_name);
                    i++;
                }
            }
        }

        return i; // cantidad de elementos en el array de nombres
    }

    else{
        return -1;
    }
}

int builtin_dir(int argc, char **argv){

    int length;
    path_directory = malloc(sizeof(char)*PATH_MAX);
    
    if(argc == 1){
        if((length = list("./", NULL)) == -1){
            free(path_directory);
            return EXIT_FAILURE;
        }
    }

    else if(argc == 2){

        if((length = list(argv[1], NULL)) == -1 ){ // Si devuelve error, argv[1] es un texto filtro:
            if((length = list("./", argv[1])) == -1){
                free(path_directory);
                fprintf(stderr, "ERROR: invalid directory %s, type 'help dir' for more info\n", argv[1]);
                return EXIT_FAILURE;
            }
        }
    }

    else if(argc == 3){
        if((length = list(argv[1], argv[2])) == -1){
            free(path_directory);
            fprintf(stderr, "ERROR: when two arguments passed, the firts one must be a path to a directory\n");
            return EXIT_FAILURE;
        }
    }

    else {
        fprintf(stderr, "ERROR: too many arguments, type 'help dir' for more info\n");
        return 1;
    }

    bubblesort(archivo, length);

    struct stat fs;
    int x;

    char absolute_path[MAXLINE];
    strcpy(absolute_path, path_directory);
    char time[100];

    // Imprimimos los resultados:
    for(int i = 0; i < length; i++){


        strcat(absolute_path, archivo[i]);
        x = stat(absolute_path, &fs);
        strcpy(absolute_path, path_directory);
        if(x == -1){
            return EXIT_FAILURE;
        }

        if(S_ISDIR(fs.st_mode) == 1){
            printf("d");
        }else{
            printf("-");
        }

        permissions(fs.st_mode);
        

        strftime(time, sizeof(time), "%b %d %H:%M", localtime(&fs.st_mtim.tv_sec));
        printf("  %ld", fs.st_nlink);
        printf("  %15s  %15s  %6ld", getpwuid(fs.st_uid)->pw_name, getgrgid(fs.st_gid)->gr_name, fs.st_size);
        printf("  %s", time);
        printf("  %s\n", archivo[i]);
    }

    
    free(path_directory);
    return EXIT_SUCCESS;
}



