#include "holberton.h"
/**
 * DoExec - function called by __execvp to execute args
 * @file: char pointer
 * @argv: arg vector
 *
 * Return: void
 */
void DoExec(char *file, char *argv[])
{
	int i = 0;
	char *newArgv[MAX_ARGS + 1];

	execve(file, argv, environ);
	if (errno == ENOEXEC)
	{
		for (i = 0; argv[i] != 0; i++)
		{
		}
		if (i >= MAX_ARGS)
		{
			return;
		}
		newArgv[0] = "sh";
		newArgv[1] = file;
		for (i = 1; argv[i] != 0; i++)
		{
			newArgv[i + 1] = argv[i];
		}
		newArgv[i + 1] = NULL;
		execve("/bin/sh", newArgv, environ);
	}
}
/**
 * __execvp - implentation of the "execvp" function
 * @name: char pointer
 * @argv: argument vector
 *
 *
 * Return: -1
 */
int __execvp(char *name, char *argv[])
{
	char *path = pEnv("PATH");
	char fullName[MAX_NAME_SIZE + 1];

	register char *first, *last;
	int size = 0, noAccess = 0;

	if (_strchr(name, '/') != 0)
	{
		DoExec(name, argv);
		return (-1);
	}
	if (path == 0)
		path = "/usr/local/bin:/bin:/usr/bin";
	for (first = path; ; first = last + 1)
	{
		for (last = first; (*last != 0) && (*last != ':'); last++)
		{
		}
		size = last - first;
		_strncpy(fullName, first, size);
		if (last[-1] != '/')
			fullName[size++] = '/';
		_strcpy(fullName + size, name);
		DoExec(fullName, argv);
		if (errno == EACCES)
		{
			noAccess = 1;
		}
		else if (errno != ENOENT)
			break;
		if (*last == 0)
		{
			if (noAccess)
			{
				errno = EACCES;
			}
			break;
		}
	}
	return (-1);
}
/**
 * launch - launch child process and call __execvp
 * @token: char double pointer
 *
 *
 * Return: 1
 */
int launch(char **token)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (__execvp(token[0], token) == -1)
			perror("Error");
			exit(1);
	}
	if (pid > 0)
		wait(&status);
	return (1);
}
