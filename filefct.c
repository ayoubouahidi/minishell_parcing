#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

char** output_redirection_files(char *command_attributes)
{

	char** paths = { "/file1" , "/file2" , "file2" , NULL  };


	return paths;

}



void output_redirection(char **paths)
{
	int i;
	int fd;

		i =0;
	while(paths[i])
	{
		dup2(fd,STDOUT_FILENO);
		// dup2(fd,STDOUT_NO);
		i++;
	}
}
