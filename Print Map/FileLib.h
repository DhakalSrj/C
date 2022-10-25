// FileLib.h
//Suraj Dhakal. 1001765507
#include "ListLib.h"
#ifndef _FILELIB_H_
#define _FILELIB_H_

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead);
FILE *OpenFile(int argc, char *argv[]);

#endif