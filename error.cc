/*
	error.cc
	
	(c) Richard Thrippleton
	Licensing terms are in the 'LICENSE' file
	If that file is not included with this source then permission is not given to use this source in any way whatsoever.
*/

#include <string.h>
#include <stdio.h>
#include <signal.h>
#include "error.h"

error::error(const char* str)
{
	strncpy(this->str, str, 128);
	this->str[128] = '\0';
}

void error::debug(const char* str,long num)
{
	printf("%s  %ld\n",str,num);
	fflush(NULL);
}
