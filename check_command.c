#include "simple_shell.h"

int check_command(char *path)
{
	struct stat st;

	if (stat(path, &st) == -1)
		return (0);

	if (!(st.st_mode & (S_IXUSR || S_IXGRP || S_IXOTH)))
		return (0);

	return (1);
}