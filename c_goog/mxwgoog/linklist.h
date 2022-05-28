/*************************************************************************
	> File Name: mxwgoog/linklist.h
	> Author: 
	> Mail: 
	> Created Time: Tue Jan  5 15:54:51 2021
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) (long long)(&(((T *)(NULL))->name))
#define Head(p, T, name) (T *)((char *)(p) - offset(T, name))

struct LinkNode {
    struct LinkNode *next;
};

#endif
