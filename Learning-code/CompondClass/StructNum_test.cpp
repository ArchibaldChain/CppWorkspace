#include <iostream>
#include <cstring>
#include <string>
#include <string.h>

struct StructNum_test
{
    int type;
    union if_val {
        long id_num;
        char id_char[20];
    } id;
    union {
        long ID;
        char name[10];
    };
};

int main()
{
    StructNum_test a;
    a.id.id_num = 123;
    a.name[1] = 'd';
    strcpy(a.name, "dsfs");
}