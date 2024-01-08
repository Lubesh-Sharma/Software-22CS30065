#include "social.h"

char *create_name(char *name)
{
    int bufferSize = 10; // Initial buffer size
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

        // Check if the buffer is full, reallocate if necessary
        if (index == bufferSize - 1)
        {
            bufferSize *= 2; // Double the buffer size
            name = (char *)realloc(name, bufferSize * sizeof(char));
            if (name == NULL)
            {
                printf("Memory reallocation failed in name\n");
                return "\0";
            }
        }
    } while (ch != '\n');
    name[index] = '\0';
    name = (char *)realloc(name, (strlen(name) + 2) * sizeof(char));
    if (name == NULL)
    {
        printf("Memory reallocation failed in name\n");
        return "\0";
    }

    return name;
}

struct social *create_social(struct social *head)
{
    struct social *social = NULL;
    social = (struct social *)malloc(sizeof(struct social));
    int y;

    printf("Input 1 for individual, 2 for group, 3 for business, 4 for organisation\n");
    scanf("%d", &y);

    printf("Enter the ID\n");
    scanf("%d", &social->id);

    printf("Enter the name\n");
    social->name = create_name(social->name);

    printf("Enter the creation date(dd mm yyyy)\n");
    scanf("%d %d %d", &social->creation_date.day, &social->creation_date.month, &social->creation_date.year);

    social->individual = NULL;
    social->group = NULL;
    social->organisation = NULL;
    social->business = NULL;

    if (y == 1)
    {
        social->individual = (struct individual *)malloc(sizeof(struct individual));
        printf("Enter the Birthday date(dd mm yyyy)\n");
        scanf("%d %d %d", &social->individual->birthday.day, &social->individual->birthday.month, &social->individual->birthday.year);
    }
    else if (y == 2)
    {
        social->group = (struct group *)malloc(sizeof(struct group));
        int x;
        int size = 0;
        social->group->linked = (int *)malloc(sizeof(int));
        while (1)
        {
            printf("Enter 1 to link individual to group and 0 to exit\n");
            scanf("%d", &x);
            if (x == 0)
            {
                break;
            }
            else
            {
                size++;
                social->group->linked = (int *)realloc(social->group->linked, x * sizeof(int));
                printf("ID =  ");
                scanf("%d", &social->group->linked[size - 1]);
            }
        }
    }
    else if (y == 3)
    {
        social->business = (struct business *)malloc(sizeof(struct individual));
        printf("Enter the Location(x y)\n");
        scanf("%f %f", &social->business->location.x, &social->business->location.y);
        int x;
        int size = 0;
        int size2 = 0;
        social->business->owner = (int *)malloc(sizeof(int));
        social->business->customer = (int *)malloc(sizeof(int));
        while (1)
        {
            printf("Enter 1 to link individual as owners 2 to link individuals as customers and 0 to exit\n");
            scanf("%d", &x);
            if (x == 0)
            {
                break;
            }
            else if (x == 1)
            {
                size++;
                social->business->owner = (int *)realloc(social->business->owner, size * sizeof(int));
                printf("ID =  ");
                scanf("%d", &social->business->owner[size - 1]);
            }
            else
            {
                size2++;
                social->business->customer = (int *)realloc(social->business->customer, size2 * sizeof(int));
                printf("ID =  ");
                scanf("%d", &social->business->customer[size2 - 1]);
            }
        }
    }
    else
    {
        social->organisation = (struct organisation *)malloc(sizeof(struct organisation));
        printf("Enter the Location(x y)\n");
        scanf("%f %f", &social->organisation->location.x, &social->organisation->location.y);

        int x;
        int size = 0;
        social->organisation->linked = (int *)malloc(sizeof(int));
        while (1)
        {
            printf("Enter 1 to link individual to group and 0 to exit\n");
            scanf("%d", &x);
            if (x == 0)
            {
                break;
            }
            else
            {
                size++;
                social->organisation->linked = (int *)realloc(social->organisation->linked, x * sizeof(int));
                printf("ID =  ");
                scanf("%d", &social->organisation->linked[size - 1]);
            }
        }
    }
    social->next = head;
    return social;
}

struct social *delete_social(struct social *head, int ID)
{
    // Initialize pointers for traversal
    struct social *current = head;
    struct social *previous = NULL;

    // Traverse the linked list
    while (current != NULL)
    {
        // Check if the current node has the specified ID
        if (current->id == ID)
        {
            if (current->individual != NULL)
            {
                int size = sizeof(head->group->linked) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (head->group->linked[i] == ID)
                    {
                        head->group->linked[i] = -1;
                    }
                }
                size = sizeof(head->organisation->linked) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (head->organisation->linked[i] == ID)
                    {
                        head->organisation->linked[i] = -1;
                    }
                }
                size = sizeof(head->business->owner) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (head->business->owner[i] == ID)
                    {
                        head->business->owner[i] = -1;
                    }
                }
                size = sizeof(head->business->customer) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (head->business->customer[i] == ID)
                    {
                        head->business->customer[i] = -1;
                    }
                }
            }
            // If it's the head node, update the head
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                // Otherwise, update the previous node's next pointer
                previous->next = current->next;
            }

            // Free the memory of the node to be deleted
            free(current);

            printf("group with ID %d deleted.\n", ID);

            // Return the updated head of the linked list
            return head;
        }

        // Move to the next node
        previous = current;
        current = current->next;
    }
    return head;
}

void print_details(struct social *head)
{
    printf("ID = %d\n", head->id);
    printf("name = %s\n", head->name);
    printf("creation_date = %2d-%2d-%4d", head->creation_date.day, head->creation_date.month, head->creation_date.year);
    // to be left to print content
    if (head->individual != NULL)
    {
    }
    else if (head->group != NULL)
    {
        printf("The ID's members of this group are \n");//To be left in  median
        int size = sizeof(head->group->linked) / 4;
        for (int i = 0; i < size; i++)
        {
            if (head->individual !=NULL)
            {
                printf("%d ",head->id);
            }
        }
    }
}

void search_name(struct social *head)
{
    char *search = NULL;
    printf("Enter name\n");
    search = create_name(search);
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->name, search))
        {
            print_details(ptr);
        }
        ptr = ptr->next;
    }
}

void search_type(struct social *head)
{
    char *search = NULL;
    printf("Enter type\n");
    search = create_name(search);
    struct social *ptr = head;
    if (strcmp("organisation", search))
    {
        while (ptr != NULL)
        {
            if (ptr->organisation != NULL)
            {
                print_details(ptr);
            }
            ptr = ptr->next;
        }
    }
    else if (strcmp("business", search))
    {
        while (ptr != NULL)
        {
            if (ptr->business != NULL)
            {
                print_details(ptr);
            }
            ptr = ptr->next;
        }
    }
    else if (strcmp("individual", search))
    {
        while (ptr != NULL)
        {
            if (ptr->individual != NULL)
            {
                print_details(ptr);
            }
            ptr = ptr->next;
        }
    }
    else if (strcmp("group", search))
    {
        while (ptr != NULL)
        {
            if (ptr->group != NULL)
            {
                print_details(ptr);
            }
            ptr = ptr->next;
        }
    }
}

void search_birthday(struct social *head)
{
    struct date search;
    printf("Enter date(dd mm yy)\n");
    scanf("%d %d %d", &search.day, &search.month, &search.year);
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (search.day == ptr->individual->birthday.day && search.month == ptr->individual->birthday.month && search.year == ptr->individual->birthday.year)
        {
            print_details(ptr);
        }
        ptr = ptr->next;
    }
}

void print_hop_list(struct social *head)
{
    printf("The Hop Linke list is \n");
    struct social *ptr = head;
    while (ptr != NULL)
    {
        print_details(ptr);
    }
}

int main()
{
    struct social *head = NULL;
    while (1)
    {
        int y;
        printf("Input 0 to exit\n      1 to create a node\n      2 to delete a node\n      3 to search using name\n      4 to search using type\n      5 to search using birthday\n");
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
        print_hop_list(head);
    }
}