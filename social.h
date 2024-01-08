#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct date birthday;
};

struct group
{
    int *linked;
};

struct business
{
    struct location location;
    int *owner;
    int *customer;
};

struct organisation
{
    struct location location;
    int *linked;
};

struct social
{
    int id;
    char *name;
    struct date creation_date;
    char *content;
    struct social *next;

    struct individual *individual;
    struct group *group;
    struct business * business;
    struct organisation *organisation;
};