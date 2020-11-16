#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void directory_all(DIR *p_dir, char *path);

int main(int argc, char *argv[]){
    DIR *directory;
    char *dir_name;

    if (argc == 1){strcpy(dir_name ,".");}
    if (argc == 2) {strcpy(dir_name, argv[1]);}
    if((directory = opendir(dir_name)) == NULL)
    {
        perror("opendir");
        exit(1);
    }
        
    directory_all(directory, dir_name);
    printf("\n");
    return 0;
}

void directory_all(DIR *p_dir, char *path){
    DIR *temp;
    struct dirent *pd;
    char *buffer[512];
    char *buffer2[512];
    while((pd = readdir(p_dir)) != NULL){
        if(!strcmp(pd->d_name, ".") || !strcmp(pd->d_name, "..")){ continue; }
        
	if(pd->d_type == 4){
            sprintf(buffer2, "%s-Directory    ", pd->d_name);
            sprintf(buffer, "%s/%s", path, pd->d_name);
            
            if((temp = opendir(buffer)) == NULL){ perror("opendir");}
            
		directory_all(temp, buffer);
        }
        else{ sprintf(buffer2, "%s-File    ", pd->d_name);}
        printf("%s", buffer2);
    }
}


