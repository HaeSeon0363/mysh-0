#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
   
  chdir(argv[1]);
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char current[8096];
  getcwd(current,8096);
  printf("%s\n",current);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
	struct stat dir;
	if(strcmp(argv[0],"cd")==0 && argc==2){
		if(access(argv[1],F_OK | R_OK)==0){
			if(stat(argv[1],&dir)==0 && S_ISDIR(dir.st_mode)==1){
				 return 1;
			}	
		}
	}
	
	return 0;
}

int validate_pwd_argv(int argc, char** argv) {
	if(strcmp(argv[0],"pwd")==0 && argc==1)  return 1;

	return 0;
}
