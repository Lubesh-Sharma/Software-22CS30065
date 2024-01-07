#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

struct location
{
    float x;
    float y;
};

struct individual
{
    int id;
    char *name;
    struct date creation_date;
    int *birthday;
    char **content;
    struct individial *next_group;
    struct individial *next_organisation;
    struct individial *next_business;
};

struct group
{
    int id;
    char *name;
    struct date creation_date;
    char **content;
    struct individual *head;
};

struct business
{
    int id;
    char *name;
    struct date creation_date;
    struct location location;
    char **content;
    struct individual *head;
};

struct organisation
{
    int id;
    char *name;
    struct date creation_date;
    struct location location;
    char **content;
    struct organisation *next;
    struct individual *head;
};