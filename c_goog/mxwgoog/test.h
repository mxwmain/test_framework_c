/*************************************************************************
> File Name: test.h
> Author: 
> Mail: 
> Created Time: Thu Dec 31 14:02:04 2020
************************************************************************/
#ifndef _TEST_H
#define _TEST_H

#include <mxwgoog/linklist.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31) 
#define BLUE(a) COLOR(a, 34) 
#define YELLOW(a) COLOR(a, 33)
#define PURPLE(a) COLOR(a, 35)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31) 
#define BLUE_HL(a) COLOR_HL(a, 34) 
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define PURPLE_HL(a) COLOR_HL(a, 35)

#define TEST(a, b)\
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "_haizei_" #b);\
}\
void a##_haizei_##b()

#define Type(a) _Generic((a), \
    int : "%d",\
    char : "%c",\
    float : "%f",\
    double : "%lf",\
    char * : "%s",\
    long long : "%lld",\
    const char * : "%s"\
)

#define Print(a, color) {\
    char *str;\
    str = (char *)malloc(sizeof(char) * 1000);\
    sprintf(str, color("%s"), Type(a));\
    printf(str, a);\
    free(str);\
}

#define EXPECT(a, b, comp){\
   __typeof(a) _a = (a);\
   __typeof(b) _b = (b);\
   haizei_test_info.total += 1;\
   if (_a comp _b) haizei_test_info.success += 1;\
   else {\
        printf(YELLOW_HL("\t%s : %d : failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " " #comp " " #b "\n\t\t" "actula : "));\
        Print(a,YELLOW_HL)\
        printf(YELLOW_HL("  vs  "));\
        Print(b, YELLOW_HL);\
        printf("\n");\
   }\
   printf(GREEN("[-----------]"));\
   printf(BLUE_HL("%s %s %s") " %s \n", #a, #comp, #b, _a comp _b ? GREEN("True") : RED("False"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)

typedef void (*TestFuncT)();

typedef struct Function {
    TestFuncT func;
    const char *str;
    struct LinkNode p;
} Function;

struct FunctionInfo {
    int total, success;  
};

extern struct FunctionInfo haizei_test_info;
int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
