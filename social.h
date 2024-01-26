/*
    The structure date is used to store the input date in form of day, month and year.

    The structure location is used to store the location ain form of x and y coordinates.

    The structure individual is used to store the things which are defined for individuals only. Also, it has a variable to track that i had came over it or not, which is helpful in my part 6 question.

    The structure group is used to store the IDs of all those nodes which are linked to it. The Ids are stored in mallocaly defined array known as linked and its size is stored is size.

    The structure business store the location of the businesss by calling the structure location. It also stores the ID's which are owners of the businesss in the dynamicallly defined array owner and customers ID's in customer array. Their sizes are stored in size_owner and size_customer respectively.

    The structure organisation is used to store the IDs of all those nodes which are linked to it. The Ids are stored in dynamically defined array known as linked and its size is stored is size. It also stores the location of the organisation by called the structure location.
    
    The structure social is the main structure which stores all types of nodes. For all nodes it stores their ID in an integer, name in a dynamically defined string, creation_date by calling structure location, content in a dynamically defined string and For the things which are defined only for a particular node, It call their respective nodes. This structure all keeps track of its next structure by storing a pointer next over the next node.
*/

/*
    The function create_string takes a pointer to a string and then dynamically creates a string by first defined an arbitrary size and then if size of string exceeds then it realloc it to double the memory and at final the size is again reallocated to original size by calculating string length. This function adds character to the string until the enter key is entered. This is kept intact by do-while loop.

    The function create_individual is used to add details to a node which are specific to individual only. It takes a pointer to a node and add individual details to it and return the same pointer.

    The function create_group is used to add details to a node which are specific to group only. It takes a pointer to a node and add group details to it and return the same pointer. The while loop is used to dynamically store the iD's which are linked to group in an array.

    The function create_business is used to add details to a node which are specific to business only. It takes a pointer to a node and add business details to it and return the same pointer. The while loop is used to dynamically store the iD's which are linked to business in two arrays. THe array owner is used to store owner ID's and the array customer to store customer ID's. Both are dynamically defined.

    The function create_organisation is used to add details to a node which are specific to organisation only. It takes a pointer to a node and add organisation details to it and return the same pointer. The while loop is used to dynamically store the iD's which are linked to organisation in an array.

    The function create_social is used to add a node of any type to existing linked list. It takes the pointer to the start of linked list and an ID and add a new node to very start ,i.e., the head will point to added node and previous nodes are linked to head. It takes the required details from user. For details added to a prticular type of node it calls the respective node.

    The function delete_social is used to delete a particular node containing a particular ID. This functions takes the starting pointer of linked list and also the ID which is gonaa to be deleted. It then uses simple deletiion of a linked list node mechanism to delete the node with the ID.

    The function search_id_type is used to check which type of node it is. It takes head of linked list and an ID. It iterates over the whole list and if ID is matched it check its type by checking which one is not NULL. It returns a unique integer corresponding to the each type.

    The function Convert_ID_to_Pointer takes head of the linked list and an ID. If a node with same ID is present then it return the pointer to that node else will return NULL.

    The function print_details is used to print all the details which can be there regarding a particualar node for this it takes an pointer to a node and also pointer to start of the linked list. If the pointer is not NULL, it prints the things which are coomon to ny type of node. It then checks it type by checking which type pointer is NULL. If it is individual then it searches in each of the rest type of nodes whether it is linked to anny of them or not. IF found linked then print the ID of that node type. If it is of any other type then the all ID's stored in the respective arrays are printed but before printing it will also check whether that ID is deleted or not. IF not then print the ID. The int x is used to check whether we to print hoff list or full details.

    The function match_strings is used to check whether a string search is a substring (sub part) of the string "string". For this it first calculate the length of both the strings and stores it in two vriables. Now if the length of "string" is less than the length of "search" then it will return 0 as "search" cannot be found in the "string". else it iterates over the whole "string" and uses a predefined function strncmp to check the goal. The strncmp takes start pointer of parent string and checker string,i.e., search and also the length of the "search string". It returns 0 if in "string" from the start pointer to start+length part is equal to "search".

    The function search_name takes head of the linked list as parameter. It then takes a string as input "search" and then iterates over the whole list until it finds that the "search" is a subpart of a nodes' name. it do so by calling match_strings function. IF it finds the "search" got matched with some name then it print the details of that node by calling print details.

    The function search_type takes head of the linked list as parameter. It then takes a string as input taking the type of the node.It then compares the input with each type name. It then print details of alll the nodes that inputed types by calling print_details function for each node.

    The function search_birthday is used to find that any individual node has same birthday as that of inputed date. For this it takes over head of the linked list and iterates over it untill it finds the same birthday. If same birthday is found then the details of that node is printed by calling print_details function.

    The function add_content is used to add a content to a node with a particular ID. For this it takes head of linked list and an ID as parameter. It then Iterates over the liniked list untill that ID is found. IF that ID is found, it then adds a new content to that ID by calling create_string function. Note that this function adds a content if previously the content was not there and if a content is already present then it reoplaces the old content with the new one.

    The function print_content_organisation takes parameter as the head of the linked list and also an ID. It then checks whether that ID is a ID of individual or not. If found of individual it then iterates over the linked list again to find that to which organisation does this ID is linked with. If it founds a organisation it then print the content of all the individual nodes present in that organisation. To check a node's content is not printed twice we keep a visited pointer for this. IF it is 1 it means that it has been previously visited else it is not visited.

    The function print_content_group takes parameter as the head of the linked list and also an ID. It then checks whether that ID is a ID of individual or not. If found of individual it then iterates over the linked list again to find that to which group does this ID is linked with. If it founds a group it then print the content of all the individual nodes present in that group. To check a node's content is not printed twice we keep a visited pointer for this. IF it is 1 it means that it has been previously visited else it is not visited.

    The function print_contet takes head of the linked list as parameter. It then takes input an ID. The use of this function is to print the content of the individuals that are linked with the given inputted ID. This is done by calling print_content_group and print_content_organisation.

    The function search_content takes parameters as a pointer to a string and the pointer to the head of the linked list. The Aim of this function is to print all the contents and their respective ID's in which the string "search" is part of. It acheives its goal by iterating over the whole linked list and calling the match_strings function.

    The main() function is used to take sme inputs and called the respective functions to utilize all the above functionalities.
*/
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
    int visited;
};

struct group
{
    int *linked;
    int size;
};

struct business
{
    struct location location;
    int *owner;
    int size_owner;
    int *customer;
    int size_customer;
};

struct organisation
{
    struct location location;
    int *linked;
    int size;
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
    struct business *business;
    struct organisation *organisation;
};

struct social *Convert_ID_to_Pointer(struct social *head, int ID);

char *create_string(char *name);

struct social *create_individual(struct social *social);

struct social *create_group(struct social *social);

struct social *create_business(struct social *social);

struct social *create_organisation(struct social *social);

struct social *create_social(struct social *head);

struct social *delete_social(struct social *head, int ID);

int search_id_type(int ID, struct social *head);

void print_details(struct social *ptr, struct social *head,int x);

int match_strings(char *string, char *search);

void search_name(struct social *head);

void search_type(struct social *head);

void search_birthday(struct social *head);

struct social *add_content(struct social *head, int ID);

void print_content_organisation(struct social *head, int ID);

void print_content_group(struct social *head, int ID);

void print_content(struct social *head);

void search_content(char *search, struct social *head);