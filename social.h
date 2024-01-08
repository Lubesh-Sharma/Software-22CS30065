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
    int id;
    char *name;
    struct date creation_date;
    struct date birthday;
    char **content;
    struct individial *next_individual;
    // struct group *next_group;
    // struct organisation *next_organisation;
    // struct individial *next_business;
};

struct group
{
    int id;
    char *name;
    struct date creation_date;
    char **content;
    // struct individual *head;
    struct group *next_group;
    int *linked;
};

struct business
{
    int id;
    char *name;
    struct date creation_date;
    struct location location;
    char **content;
    // struct individual *head;
    struct business *next_business;
    int *owner;
    int *customer;
};

struct organisation
{
    int id;
    char *name;
    struct date creation_date;
    struct location location;
    char **content;
    // struct organisation *next;
    // struct individual *head;
    struct organisation *next_organisation;
    int *linked;
};