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

    social->content = NULL;
    printf("Enter the content of the node\n");
    social->content = create_name(social->content);

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

int search_id(int ID, struct social *head)
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
    }
    return 0;
}

struct social *convert_idTO_pointer(struct social *head, int ID)
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
    if (ptr == NULL)
    {
        printf("The ID is not found\n");
    }
    return ptr;
}

void print_details(struct social *ptr, struct social *head)
{
    printf("ID = %d\n", ptr->id);
    printf("name = %s\n", ptr->name);
    printf("creation_date = %2d-%2d-%4d\n", ptr->creation_date.day, ptr->creation_date.month, ptr->creation_date.year);
    printf("The content posted by this node is\n%s\n", ptr->content);
    int size;
    if (ptr->individual != NULL)
    {
        printf("The birthdate of individual is %2d-%2d-%4d\n", ptr->individual->birthday.day, ptr->individual->birthday.month, ptr->individual->birthday.year);

        printf("The group in which the individual is a member of are\n");
        struct social *checker = head;
        while (checker != NULL)
        {
            if (checker->group != NULL)
            {
                size = sizeof(checker->group->linked) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker->group->linked[i] == ptr->id)
                    {
                        printf("%d ", &checker->id);
                    }
                }
                checker = checker->next;
            }
        }

        printf("The organisation in which the individual is a member of are\n");
        struct social *checker1 = head;
        while (checker1 != NULL)
        {
            if (checker1->organisation != NULL)
            {
                size = sizeof(checker1->organisation->linked) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker1->organisation->linked[i] == ptr->id)
                    {
                        printf("%d ", &checker1->id);
                    }
                }
                checker1 = checker1->next;
            }
        }

        printf("The business in which the individual is a owner are\n");
        struct social *checker2 = head;
        while (checker2 != NULL)
        {
            if (checker2->business != NULL)
            {
                size = sizeof(checker2->business->owner) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker2->business->owner[i] == ptr->id)
                    {
                        printf("%d ", &checker2->id);
                    }
                }
                checker2 = checker2->next;
            }
        }

        printf("The business in which the individual is a customer are\n");
        struct social *checker3 = head;
        while (checker3 != NULL)
        {
            if (checker3->business != NULL)
            {
                size = sizeof(checker3->business->customer) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker3->business->customer[i] == ptr->id)
                    {
                        printf("%d ", &checker2->id);
                    }
                }
                checker3 = checker3->next;
            }
        }
    }
    else if (ptr->group != NULL)
    {
        printf("The business' members of this group are \n");
        size = sizeof(ptr->group->linked) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->group->linked[i], head) == 2)
            {
                printf("%d  ", ptr->group->linked[i]);
            }
        }
        printf("The Individual members of this group are \n");
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->group->linked[i], head) == 1)
            {
                printf("%d  ", ptr->group->linked[i]);
            }
        }
    }
    else if (ptr->business != NULL)
    {
        printf("The location of the business is (%f , %f)", ptr->business->location.x, ptr->business->location.y);
        printf("The Owners of this business are \n");
        size = sizeof(ptr->business->owner) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->business->owner[i], head) == 1)
            {
                printf("%d  ", ptr->business->owner[i]);
            }
        }
        printf("\n");
        printf("The Customers of this business are \n");
        size = sizeof(ptr->business->customer) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->business->customer[i], head) == 1)
            {
                printf("%d  ", ptr->business->customer[i]);
            }
        }
        printf("\n");
    }
    else if (ptr->organisation != NULL)
    {
        printf("The location of the organisation is (%f , %f)", ptr->organisation->location.x, ptr->organisation->location.y);
        printf("The Individual members of this organisation are \n");
        size = sizeof(ptr->organisation->linked) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->organisation->linked[i], head) == 1)
            {
                printf("%d  ", ptr->organisation->linked[i]);
            }
        }
        printf("\n");
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
            print_hop_list(ptr, head);
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
                print_hop_list(ptr, head);
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
                print_hop_list(ptr, head);
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
                print_hop_list(ptr, head);
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
                print_hop_list(ptr, head);
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
            print_hop_list(ptr, head);
        }
        ptr = ptr->next;
    }
}

struct social *content(struct social *head, int ID, int num)
{
    struct social *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->id == ID)
        {
            if (num == 0)
            {
                printf("Enter the content\n");
                ptr->content = create_name(ptr->content);
            }
            else
            {
                if (ptr->content == NULL)
                {
                    printf("Node does not have any content.\n");
                }
                else
                {
                    printf("The content is\n%s\n", ptr->content);
                }
            }
        }
        ptr = ptr->next;
    }
    return head;
}

void print_content(struct social *head, struct social *ptr)
{
    int size;
    if (ptr->individual != NULL)
    {
        struct social *checker = head;
        while (checker != NULL)
        {
            if (checker->group != NULL)
            {
                size = sizeof(checker->group->linked) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker->group->linked[i] == ptr->id)
                    {
                        head = content(head, ptr->id, 1);
                    }
                }
                checker = checker->next;
            }
        }
        struct social *checker1 = head;
        while (checker1 != NULL)
        {
            if (checker1->organisation != NULL)
            {
                size = sizeof(checker1->organisation->linked) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker1->organisation->linked[i] == ptr->id)
                    {
                        head = content(head, ptr->id, 1);
                    }
                }
                checker1 = checker1->next;
            }
        }
        struct social *checker2 = head;
        while (checker2 != NULL)
        {
            if (checker2->business != NULL)
            {
                size = sizeof(checker2->business->owner) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker2->business->owner[i] == ptr->id)
                    {
                        head = content(head, ptr->id, 1);
                    }
                }
                checker2 = checker2->next;
            }
        }
        struct social *checker3 = head;
        while (checker3 != NULL)
        {
            if (checker3->business != NULL)
            {
                size = sizeof(checker3->business->customer) / 4;
                for (int i = 0; i < size; i++)
                {
                    if (checker3->business->customer[i] == ptr->id)
                    {
                        head = content(head, ptr->id, 1);
                    }
                }
                checker3 = checker3->next;
            }
        }
    }
    else if (ptr->group != NULL)
    {
        size = sizeof(ptr->group->linked) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->group->linked[i], head) == 2)
            {
                head = content(head, ptr->group->linked[i], 1);
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->group->linked[i], head) == 1)
            {
                head = content(head, ptr->group->linked[i], 1);
            }
        }
    }
    else if (ptr->business != NULL)
    {
        size = sizeof(ptr->business->owner) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->business->owner[i], head) == 1)
            {
                head = content(head, ptr->business->owner[i], 1);
            }
        }
        size = sizeof(ptr->business->customer) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->business->customer[i], head) == 1)
            {
                head = content(head, ptr->business->customer[i], 1);
            }
        }
    }
    else if (ptr->organisation != NULL)
    {
        size = sizeof(ptr->organisation->linked) / 4;
        for (int i = 0; i < size; i++)
        {
            if (search_id(ptr->organisation->linked[i], head) == 1)
            {
                head = content(head, ptr->organisation->linked[i], 1);
            }
        }
        printf("\n");
    }
}

int main()
{
    struct social *head = NULL;
    while (1)
    {
        int y;
        printf("Input 0 to exit\n      1 to create a node\n      2 to delete a node\n      3 to search using name\n      4 to search using type\n      5 to search using birthday\n      6 to print hop_list\n      7 to add content to a node\n      8 to search a node\n      9 to print the content of nodes linked to a given node\n      10 to print all the nodes\n");
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
            scanf("%d", &Hop_id);
            struct social *ptr = convert_idTO_pointer(head, Hop_id);
            print_hop_list(ptr, head);
        }
        else if (y == 7)
        {
            int ID;
            printf("Enter the ID in which you wish to add content\n");
            scanf("%d", &ID);
            head = content(head, ID, 0);
        }
        else if (y == 8)
        {
            int ID;
            printf("Enter the node you wish to print the content\n");
            scanf("%d", &ID);
            head = content(head, ID, 1);
        }
        else if (y == 9)
        {
            int ID;
            printf("Enter the ID\n");
            scanf("%d", &ID);
            struct social *ptr = convert_idTO_pointer(head, ID);
            print_content(head, ptr);
        }
        else if (y == 10)
        {
            struct social *ptr = head;
            while (ptr != NULL)
            {
                print_hop_list(ptr, head);
                ptr = ptr->next;
            }
        }
        else
        {
            printf("You inputed wrong input\n\n");
        }
    }
}