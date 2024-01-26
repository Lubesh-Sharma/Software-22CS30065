#include "social.h"

struct social *Convert_ID_to_Pointer(struct social *head, int ID)
{
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->id == ID)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return ptr;
}

char *create_string(char *name)
{
    int bufferSize = 10;
    name = (char *)malloc(bufferSize * sizeof(char));
    if (name == NULL)
    {
        printf("Memory allocation failed in name\n");
        return NULL;
    }

    char ch;
    int index = 0;
    char c;
    scanf("%c", &c);
    do
    {
        scanf("%c", &ch);
        name[index++] = ch;
        if (index == bufferSize - 1)
        {
            bufferSize *= 2;
            name = (char *)realloc(name, bufferSize * sizeof(char));
            if (name == NULL)
            {
                printf("Memory reallocation failed in name\n");
                return "\0";
            }
        }
    } while (ch != '\n');
    name[index - 1] = '\0';
    name = (char *)realloc(name, (strlen(name) + 2) * sizeof(char));
    if (name == NULL)
    {
        printf("Memory reallocation failed in name\n");
        return "\0";
    }

    return name;
}

struct social *create_individual(struct social *social)
{
    social->individual = (struct individual *)malloc(sizeof(struct individual));
    if (social->individual == NULL)
    {
        printf("Memory Allocation error in individual\n");
    }
    social->individual->visited = 0;
    printf("Enter the Birthday date(dd mm yyyy)\n");
    scanf("%d %d %d", &social->individual->birthday.day, &social->individual->birthday.month, &social->individual->birthday.year);
    printf("\n");
    return social;
}

struct social *create_group(struct social *social)
{
    social->group = (struct group *)malloc(sizeof(struct group));
    if (social->group == NULL)
    {
        printf("Memory allocation error in group\n");
    }
    int x;
    int size = 0;
    social->group->size = size;
    social->group->linked = (int *)malloc(sizeof(int));
    if (social->group->linked == NULL)
    {
        printf("Memory Allocation Error in storing Ids in group\n");
    }
    while (1)
    {
        char link_check;
        printf("Do you want to wish to link an ID? (Y/N)\n");
        scanf(" %c", &link_check);
        if (link_check == 'y' || link_check == 'Y')
        {
            size++;
            social->group->size = size;
            social->group->linked = (int *)realloc(social->group->linked, size * sizeof(int));
            if (social->group->linked == NULL)
            {
                printf("Memory Allocation Error in storing Ids in group\n");
            }
            printf("ID =  ");
            scanf("%d", &social->group->linked[size - 1]);
        }
        else
        {
            printf("\n");
            break;
        }
    }
    return social;
}

struct social *create_business(struct social *social)
{
    social->business = (struct business *)malloc(sizeof(struct business));
    if (social->business == NULL)
    {
        printf("Memory allocation error in business\n");
    }
    printf("Enter the Location(x y)\n");
    scanf("%f %f", &social->business->location.x, &social->business->location.y);
    int x;
    int size = 0;
    social->business->size_owner = size;
    int size2 = 0;
    social->business->size_customer = size2;
    social->business->owner = (int *)malloc(sizeof(int));
    if (social->business->owner == NULL)
    {
        printf("Memory allocation error in business owner array\n");
    }
    social->business->customer = (int *)malloc(sizeof(int));
    if (social->business->customer == NULL)
    {
        printf("Memory allocation error in business customer array\n");
    }
    while (1)
    {
        printf("Enter 1 to link individual as owners 2 to link individuals as customers and 0 to exit\n");
        scanf("%d", &x);
        if (x == 0)
        {
            printf("\n");
            break;
        }
        else if (x == 1)
        {
            size++;
            social->business->size_owner = size;
            social->business->owner = (int *)realloc(social->business->owner, size * sizeof(int));
            if (social->business->owner == NULL)
            {
                printf("Memory allocation error in business owner array\n");
            }
            printf("ID =  ");
            scanf("%d", &social->business->owner[size - 1]);
        }
        else
        {
            size2++;
            social->business->size_customer = size2;
            social->business->customer = (int *)realloc(social->business->customer, size2 * sizeof(int));
            if (social->business->customer == NULL)
            {
                printf("Memory allocation error in business customer array\n");
            }
            printf("ID =  ");
            scanf("%d", &social->business->customer[size2 - 1]);
        }
    }

    return social;
}

struct social *create_organisation(struct social *social)
{
    social->organisation = (struct organisation *)malloc(sizeof(struct organisation));
    if (social->organisation == NULL)
    {
        printf("Memory allocation error in organisation\n");
    }
    printf("Enter the Location(x y)\n");
    scanf("%f %f", &social->organisation->location.x, &social->organisation->location.y);

    int x;
    int size = 0;
    social->organisation->size = size;
    social->organisation->linked = (int *)malloc(sizeof(int));
    if (social->organisation->linked == NULL)
    {
        printf("Memory allocation error in storing ids in organisation\n");
    }
    while (1)
    {
        char link_check;
        printf("Do you want to wish to link an ID? (Y/N)\n");
        scanf(" %c", &link_check);
        if (link_check == 'y' || link_check == 'Y')
        {
            size++;
            social->organisation->size = size;
            social->organisation->linked = (int *)realloc(social->organisation->linked, size * sizeof(int));
            if (social->organisation->linked == NULL)
            {
                printf("Memory allocation error in storing ids in organisation\n");
            }
            printf("ID =  ");
            scanf("%d", &social->organisation->linked[size - 1]);
        }
        else
        {
            printf("\n");
            break;
        }
    }
    return social;
}

struct social *create_social(struct social *head)
{
    struct social *social = NULL;
    social = (struct social *)malloc(sizeof(struct social));
    char *input;
    printf("Enter the node type you wish to create (individual, group, business, organisation)\n");
    input = create_string(input);

    while (1)
    {
        printf("Enter the ID\n");
        scanf("%d", &social->id);
        if (Convert_ID_to_Pointer(head, social->id) != NULL)
        {
            printf("This ID is already present\n");
        }
        else
        {
            break;
        }
    }

    printf("Enter the name\n");
    social->name = create_string(social->name);

    printf("Enter the creation date(dd mm yyyy)\n");
    scanf("%d %d %d", &social->creation_date.day, &social->creation_date.month, &social->creation_date.year);

    social->content = NULL;

    char v;
    printf("Do you wish to enter the content right now? (Y|N)\n");
    scanf(" %c", &v);
    if (v == 'Y' || v == 'y')
    {
        printf("Enter the content of the node\n");
        social->content = create_string(social->content);
    }

    social->individual = NULL;
    social->group = NULL;
    social->organisation = NULL;
    social->business = NULL;

    if (!strcmp("individual", input))
    {
        social = create_individual(social);
    }
    else if (!strcmp("group", input))
    {
        social = create_group(social);
    }
    else if (!strcmp("business", input))
    {
        social = create_business(social);
    }
    else if (!strcmp("organisation", input))
    {
        social = create_organisation(social);
    }
    else
    {
        printf("Wrong input\tenter again!\n");
        free(social);
        return head;
    }
    social->next = head;
    return social;
}

struct social *delete_social(struct social *head, int ID)
{
    int count = 0;
    struct social *current = head;
    struct social *previous = NULL;
    while (current != NULL)
    {
        if (current->id == ID)
        {
            count = 1;
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);

            printf("group with ID %d deleted.\n", ID);
            return head;
        }
        previous = current;
        current = current->next;
    }
    if (count == 0)
    {
        printf("The Id is not found\n");
    }
    return head;
}

int search_id_type(int ID, struct social *head)
{
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->id == ID)
        {
            if (ptr->individual != NULL)
            {
                return 1;
            }
            else if (ptr->business != NULL)
            {
                return 2;
            }
            else if (ptr->group != NULL)
            {
                return 3;
            }
            else if (ptr->organisation != NULL)
            {
                return 4;
            }
        }
        ptr = ptr->next;
    }
    return 0;
}

void print_details(struct social *ptr, struct social *head, int x)
{
    if (ptr != NULL)
    {
        printf("ID = %d\n", ptr->id);
        if (x == 0)
        {
            printf("name = %s\n", ptr->name);
            printf("creation_date = %2d-%2d-%4d\n", ptr->creation_date.day, ptr->creation_date.month, ptr->creation_date.year);
            printf("\nThe content posted by this node is\n%s\n\n", ptr->content);
        }
        if (ptr->individual != NULL)
        {
            if (x == 0)
            {
                printf("The birthdate of individual is %2d-%2d-%4d\n", ptr->individual->birthday.day, ptr->individual->birthday.month, ptr->individual->birthday.year);
            }
            printf("The group in which the individual is a member of are ID no.\t");
            struct social *checker = head;
            while (checker != NULL)
            {
                if (checker->group != NULL)
                {
                    for (int i = 0; i < checker->group->size; i++)
                    {
                        if (checker->group->linked[i] == ptr->id)
                        {
                            printf("%d ", checker->id);
                        }
                    }
                }
                checker = checker->next;
            }
            printf("\n");

            printf("The organisation in which the individual is a member of are ID no.\t");
            struct social *checker1 = head;
            while (checker1 != NULL)
            {
                if (checker1->organisation != NULL)
                {
                    for (int i = 0; i < checker1->organisation->size; i++)
                    {
                        if (checker1->organisation->linked[i] == ptr->id)
                        {
                            printf("%d ", checker1->id);
                        }
                    }
                }
                checker1 = checker1->next;
            }
            printf("\n");

            printf("The business in which the individual is a owner are ID no.\t");
            struct social *checker2 = head;
            while (checker2 != NULL)
            {
                if (checker2->business != NULL && checker2->business->owner != NULL)
                {
                    for (int i = 0; i < checker2->business->size_owner; i++)
                    {
                        if (checker2->business->owner[i] == ptr->id)
                        {
                            printf("%d ", checker2->id);
                        }
                    }
                }
                checker2 = checker2->next;
            }
            printf("\n");

            printf("The business in which the individual is a customer are ID no.\t");
            struct social *checker3 = head;
            while (checker3 != NULL)
            {
                if (checker3->business != NULL && checker3->business->customer != NULL)
                {
                    for (int i = 0; i < checker3->business->size_customer; i++)
                    {
                        if (checker3->business->customer[i] == ptr->id)
                        {
                            printf("%d ", checker3->id);
                        }
                    }
                }
                checker3 = checker3->next;
            }
            printf("\n");
        }
        else if (ptr->group != NULL)
        {
            printf("The business' members of this group are ID no.\t");
            for (int i = 0; i < ptr->group->size; i++)
            {
                if (search_id_type(ptr->group->linked[i], head) == 2)
                {
                    printf("%d  ", ptr->group->linked[i]);
                }
            }
            printf("\n");
            printf("The Individual members of this group are ID no.\t");
            for (int i = 0; i < ptr->group->size; i++)
            {
                if (search_id_type(ptr->group->linked[i], head) == 1)
                {
                    printf("%d  ", ptr->group->linked[i]);
                }
            }
            printf("\n");
        }
        else if (ptr->business != NULL)
        {
            if (x == 0)
            {
                printf("The location of the business is (%f , %f)\n", ptr->business->location.x, ptr->business->location.y);
            }
            printf("The Owners of this business are ID no.\t");
            for (int i = 0; i < ptr->business->size_owner; i++)
            {
                if (search_id_type(ptr->business->owner[i], head) == 1)
                {
                    printf("%d  ", ptr->business->owner[i]);
                }
            }
            printf("\n");
            printf("The Customers of this business are ID no.\t");
            for (int i = 0; i < ptr->business->size_customer; i++)
            {
                if (search_id_type(ptr->business->customer[i], head) == 1)
                {
                    printf("%d  ", ptr->business->customer[i]);
                }
            }
            printf("\n");
        }
        else if (ptr->organisation != NULL)
        {
            if (x == 0)
            {
                printf("The location of the organisation is (%f , %f)\n", ptr->organisation->location.x, ptr->organisation->location.y);
            }
            printf("The Individual members of this organisation are ID no.\t");
            for (int i = 0; i < ptr->organisation->size; i++)
            {
                if (search_id_type(ptr->organisation->linked[i], head) == 1)
                {
                    printf("%d  ", ptr->organisation->linked[i]);
                }
            }
            printf("\n");
        }
    }
    printf("\n************************************************************************************************************************************************\n");
}

int match_strings(char *string, char *search)
{
    int stringLen = 0;
    if (string != NULL)
    {
        stringLen = strlen(string);
    }
    int searchLen = 0;
    if (search != NULL)
    {
        searchLen = strlen(search);
    }

    if (searchLen > stringLen)
    {
        return 0;
    }

    for (int i = 0; i <= stringLen - searchLen; ++i)
    {
        if (strncasecmp(string + i, search, searchLen) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void search_name(struct social *head)
{
    int count = 0;
    char *search = NULL;
    printf("Enter name\n");
    search = create_string(search);
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (match_strings(ptr->name, search) == 1)
        {
            count = 1;
            print_details(ptr, head,0);
        }
        ptr = ptr->next;
    }
    if (count == 0)
    {
        printf("There is no ID with the given name\n");
    }
}

void search_type(struct social *head)
{
    int count = 0;
    char *search = NULL;
    printf("Enter type\n");
    search = create_string(search);
    struct social *ptr = head;
    if (!strcmp("organisation", search))
    {
        while (ptr != NULL)
        {
            if (ptr->organisation != NULL)
            {
                count = 1;
                print_details(ptr, head,0);
            }
            ptr = ptr->next;
        }
    }
    else if (!strcmp("business", search))
    {
        while (ptr != NULL)
        {
            if (ptr->business != NULL)
            {
                count = 1;
                print_details(ptr, head,0);
            }
            ptr = ptr->next;
        }
    }
    else if (!strcmp("individual", search))
    {
        while (ptr != NULL)
        {
            if (ptr->individual != NULL)
            {
                count = 1;
                print_details(ptr, head,0);
            }
            ptr = ptr->next;
        }
    }
    else if (!strcmp("group", search))
    {
        while (ptr != NULL)
        {
            if (ptr->group != NULL)
            {
                count = 1;
                print_details(ptr, head,0);
            }
            ptr = ptr->next;
        }
    }
    if (count == 0)
    {
        printf("There is no %s node present\n", search);
    }
}

void search_birthday(struct social *head)
{
    int count = 0;
    struct date search;
    printf("Enter date(dd mm yy)\n");
    scanf("%d %d %d", &search.day, &search.month, &search.year);
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->individual != NULL)
        {
            if ((search.day == ptr->individual->birthday.day) && (search.month == ptr->individual->birthday.month) && (search.year == ptr->individual->birthday.year))
            {
                print_details(ptr, head,0);
                count = 1;
            }
        }
        ptr = ptr->next;
    }
    if (count == 0)
    {
        printf("There is no indivial with the birthdate %2d-%2d-%4d\n", search.day, search.month, search.year);
    }
}

struct social *add_content(struct social *head, int ID)
{
    int count = 0;
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->id == ID)
        {
            count = 1;
            printf("Enter the content\n");
            ptr->content = NULL;
            ptr->content = create_string(ptr->content);
        }
        ptr = ptr->next;
    }
    if (count == 0)
    {
        printf("The Id you had given is not found enter again\n");
    }
    return head;
}

void print_content_organisation(struct social *head, int ID)
{
    if (search_id_type(ID, head) == 1)
    {
        struct social *ptr = NULL;
        ptr = Convert_ID_to_Pointer(head, ID);
        ptr->individual->visited = 1;
        struct social *nptr = head;
        while (nptr != NULL)
        {
            if (nptr->organisation != NULL)
            {
                for (int i = 0; i < nptr->organisation->size; i++)
                {
                    if (nptr->organisation->linked[i] == ID)
                    {
                        for (int j = 0; j < nptr->organisation->size; j++)
                        {
                            struct social *nnptr = Convert_ID_to_Pointer(head, nptr->organisation->linked[j]);
                            if (nnptr != NULL)
                            {
                                if (nnptr->individual != NULL)
                                {
                                    if (nnptr->individual->visited == 0)
                                    {
                                        printf("ID =%d CONTENT=\n%s\n\n", nnptr->id, nnptr->content);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            nptr = nptr->next;
        }
    }
    else
    {
        printf("Wrong ID\n");
    }
}

void print_content_group(struct social *head, int ID)
{
    if (search_id_type(ID, head) == 1)
    {
        struct social *ptr = NULL;
        ptr = Convert_ID_to_Pointer(head, ID);
        ptr->individual->visited = 1;
        struct social *nptr = head;
        while (nptr != NULL)
        {
            if (nptr->group != NULL)
            {
                for (int i = 0; i < nptr->group->size; i++)
                {
                    if (nptr->group->linked[i] == ID)
                    {
                        for (int j = 0; j < nptr->group->size; j++)
                        {
                            struct social *nnptr = Convert_ID_to_Pointer(head, nptr->group->linked[j]);
                            if (nnptr != NULL)
                            {
                                if (nnptr->individual != NULL)
                                {
                                    if (nnptr->individual->visited == 0)
                                    {
                                        printf("ID =%d CONTENT=\n%s\n\n", nnptr->id, nnptr->content);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            nptr = nptr->next;
        }
    }
    else
    {
        printf("Wrong ID\n");
    }
}

void print_content(struct social *head)
{

    int ID;
    printf("Enter the ID\t");
    scanf("%d", &ID);
    print_content_group(head, ID);
    print_content_organisation(head, ID);
}

void search_content(char *search, struct social *head)
{
    int count = 0;
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (match_strings(ptr->content, search))
        {
            count = 1;
            printf("ID = %d Content is \n%s\n", ptr->id, ptr->content);
        }
        ptr = ptr->next;
    }
    if (count == 0)
    {
        printf("NO ID's with same content found\n");
    }
}

int main()
{
    struct social *head = NULL;
    while (1)
    {
        int y;
        printf("Input 0 to exit\n      1 to create a node\n      2 to delete a node\n      3 to search using name\n      4 to search using type\n      5 to search using birthday\n      6 to print hop_list\n      7 to add content to a node\n      8 to search a node's content\n      9 to print the content of nodes linked to a given node\n      10 to print all the nodes\n");
        scanf("%d", &y);
        if (y == 0)
        {
            return 0;
        }
        else if (y == 1)
        {
            head = create_social(head);
        }
        else if (y == 2)
        {
            int delete_Id;
            printf("Enter the Id you wish to delete\n");
            scanf("%d", &delete_Id);
            head = delete_social(head, delete_Id);
        }
        else if (y == 3)
        {
            search_name(head);
        }
        else if (y == 4)
        {
            search_type(head);
        }
        else if (y == 5)
        {
            search_birthday(head);
        }
        else if (y == 6)
        {
            int Hop_id;
            printf("Enter the ID you wish to print details\n");
            scanf("%d", &Hop_id);
            struct social *ptr = Convert_ID_to_Pointer(head, Hop_id);
            if (ptr == NULL)
            {
                printf("THe ID is not found\n");
            }
            print_details(ptr, head, 1);
        }
        else if (y == 7)
        {
            int ID;
            printf("Enter the ID in which you wish to add content\n");
            scanf("%d", &ID);
            head = add_content(head, ID);
        }
        else if (y == 8)
        {
            char *search = NULL;
            printf("Enter the content to be searched\n");
            search = create_string(search);
            search_content(search, head);
        }
        else if (y == 9)
        {
            print_content(head);
        }
        else if (y == 10)
        {
            struct social *ptr = head;
            if (ptr == NULL)
            {
                printf("There is no nodes present\n");
                printf("***********************************************************************************************************************************************\n");
            }
            while (ptr != NULL)
            {
                print_details(ptr, head,0);
                ptr = ptr->next;
            }
        }
        else
        {
            printf("You inputed wrong input\n\n");
        }
    }
    return 0;
}