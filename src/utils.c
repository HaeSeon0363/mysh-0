#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  char newCom[8096];
	strcpy(newCom,command);
	*argv=(char **)malloc(sizeof(char*)*16);
	int count=0;
	char *token = strtok(newCom," \n\t");
	
	while(token!=NULL){
		*(*argv+count)=(char*)malloc(sizeof(char)*(strlen(token)));
		strcpy(*(*argv+count),token);
		count++;

		token=strtok(NULL," \n\t");
	}
        
	if (count==0)
	{
		*(*argv+count)=(char *)malloc(sizeof(char));
		strcpy(*(*argv+count),"");
		count++;
	}

       *argc=count;
}
