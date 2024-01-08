#include <social.h>

char *create_name(char *name)
{
    int bufferSize = 10; // Initial buffer size
    char *name = (char *)malloc(bufferSize * sizeof(char));
    if (name == NULL)
    {
        printf("Memory allocation failed in name\n");
        return NULL;
    }

    char ch;
    int index = 0;
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

struct individual *create_individual(struct individual *ptr)
{
    struct individual *ind = NULL;
    ind = (struct individual *)malloc(sizeof(struct individual));

    printf("Enter the ID\n");
    scanf("%d", &ind->id);

    printf("Enter the name of the individual\n");
    ind->name = create_name(ind->name);

    printf("Enter the creation date(dd mm yyyy)\n");
    scanf("%d %d %d\n", &ind->creation_date.day, &ind->creation_date.month, &ind->creation_date.year);

    printf("Enter the Birthday date(dd mm yyyy)\n");
    scanf("%d %d %d\n", &ind->birthday.day, &ind->birthday.month, &ind->birthday.year);

    ind->next_individual = ptr;
    return ind;
}

struct group *create_group(struct group *ptr)
{
    struct group *grp = NULL;
    grp = (struct individual *)malloc(sizeof(struct individual));

    printf("Enter the ID\n");
    scanf("%d", &grp->id);

    printf("Enter the name of the individual\n");
    grp->name = create_name(grp->name);

    printf("Enter the creation date(dd mm yyyy)\n");
    scanf("%d %d %d\n", &grp->creation_date.day, &grp->creation_date.month, &grp->creation_date.year);

    grp->next_group = ptr;
    return grp;

    int x;
    int size = 0;
    grp->linked = (int *)malloc(sizeof(int));
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
            grp->linked = (int *)realloc(grp->linked, x * sizeof(int));
            scanf("%d", &grp->linked[size - 1]);
        }
    }
}

struct business *create_business(struct business *ptr)
{
    struct business *buss = NULL;
    buss = (struct individual *)malloc(sizeof(struct individual));

    printf("Enter the ID\n");
    scanf("%d", &buss->id);

    printf("Enter the name of the individual\n");
    buss->name = create_name(buss->name);

    printf("Enter the creation date(dd mm yyyy)\n");
    scanf("%d %d %d\n", &buss->creation_date.day, &buss->creation_date.month, &buss->creation_date.year);

    printf("Enter the Location(x y)\n");
    scanf("%f %f", &buss->location.x, &buss->location.y);

    int x;
    int size = 0;
    int size2 = 0;
    buss->owner = (int *)malloc(sizeof(int));
    buss->customer = (int *)malloc(sizeof(int));
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
            buss->owner = (int *)realloc(buss->owner, size * sizeof(int));
            scanf("%d", &buss->owner[size - 1]);
        }
        else
        {
            size2++;
            buss->customer = (int *)realloc(buss->customer, size2 * sizeof(int));
            scanf("%d", &buss->customer[size2 - 1]);
        }
    }

    buss->next_business = ptr;
    return buss;
}

struct organisation *create_organisation(struct organisation *ptr)
{
    struct organisation *org = NULL;
    org = (struct individual *)malloc(sizeof(struct individual));

    printf("Enter the ID\n");
    scanf("%d", &org->id);

    printf("Enter the name of the individual\n");
    org->name = create_name(org->name);

    printf("Enter the creation date(dd mm yyyy)\n");
    scanf("%d %d %d\n", &org->creation_date.day, &org->creation_date.month, &org->creation_date.year);

    printf("Enter the Location(x y)\n");
    scanf("%f %f", &org->location.x, &org->location.y);

    int x;
    int size = 0;
    org->linked = (int *)malloc(sizeof(int));
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
            org->linked = (int *)realloc(org->linked, x * sizeof(int));
            scanf("%d", &org->linked[size - 1]);
        }
    }

    org->next_organisation = ptr;
    return org;
}

struct organisation *delete_organisation(struct organisation *head, int ID)
{
    // Initialize pointers for traversal
    struct organisation *current = head;
    struct organisation *previous = NULL;

    // Traverse the linked list
    while (current != NULL)
    {
        // Check if the current node has the specified ID
        if (current->id == ID)
        {
            // If it's the head node, update the head
            if (previous == NULL)
            {
                head = current->next_organisation;
            }
            else
            {
                // Otherwise, update the previous node's next pointer
                previous->next_organisation = current->next_organisation;
            }

            // Free the memory of the node to be deleted
            free(current);

            printf("Organization with ID %d deleted.\n", ID);

            // Return the updated head of the linked list
            return head;
        }

        // Move to the next node
        previous = current;
        current = current->next_organisation;
    }

    // If the ID was not found, print a message
    printf("Organization with ID %d not found.\n", ID);

    // Return the original head since no deletion occurred
    return head;
}

struct business *delete_business(struct business *head, int ID)
{
    // Initialize pointers for traversal
    struct business *current = head;
    struct business *previous = NULL;

    // Traverse the linked list
    while (current != NULL)
    {
        // Check if the current node has the specified ID
        if (current->id == ID)
        {
            // If it's the head node, update the head
            if (previous == NULL)
            {
                head = current->next_business;
            }
            else
            {
                // Otherwise, update the previous node's next pointer
                previous->next_business = current->next_business;
            }

            // Free the memory of the node to be deleted
            free(current);

            printf("business with ID %d deleted.\n", ID);

            // Return the updated head of the linked list
            return head;
        }

        // Move to the next node
        previous = current;
        current = current->next_business;
    }
    // Return the original head since no deletion occurred
    return head;
}

struct group *delete_group(struct group *head, int ID)
{
    // Initialize pointers for traversal
    struct group *current = head;
    struct group *previous = NULL;

    // Traverse the linked list
    while (current != NULL)
    {
        // Check if the current node has the specified ID
        if (current->id == ID)
        {
            // If it's the head node, update the head
            if (previous == NULL)
            {
                head = current->next_group;
            }
            else
            {
                // Otherwise, update the previous node's next pointer
                previous->next_group = current->next_group;
            }

            // Free the memory of the node to be deleted
            free(current);

            printf("group with ID %d deleted.\n", ID);

            // Return the updated head of the linked list
            return head;
        }

        // Move to the next node
        previous = current;
        current = current->next_group;
    }
    return head;
}

struct individual *delete_individual(struct individual *head, struct group *grp, struct business *buss, struct organisation *org, int ID)
{
    // Initialize pointers for traversal
    struct individual *current = head;
    struct individual *previous = NULL;

    // Traverse the linked list
    while (current != NULL)
    {
        // Check if the current node has the specified ID
        if (current->id == ID)
        {
            int size= sizeof(grp->linked)/4;
            for(int i=0; i<size;i++)
            {
                if(grp->linked[i]==ID)
                {
                    grp->linked[i]=-1;
                }
            }
            size= sizeof(org->linked)/4;
            for(int i=0; i<size;i++)
            {
                if(org->linked[i]==ID)
                {
                    org->linked[i]=-1;
                }
            }
            size= sizeof(buss->owner)/4;
            for(int i=0; i<size;i++)
            {
                if(buss->owner[i]==ID)
                {
                    buss->owner[i]=-1;
                }
            }
            size= sizeof(buss->customer)/4;
            for(int i=0; i<size;i++)
            {
                if(buss->customer[i]==ID)
                {
                    buss->customer[i]=-1;
                }
            }
            // If it's the head node, update the head
            if (previous == NULL)
            {
                head = current->next_individual;
            }
            else
            {
                // Otherwise, update the previous node's next pointer
                previous->next_individual = current->next_individual;
            }

            // Free the memory of the node to be deleted
            free(current);

            printf("individual with ID %d deleted.\n", ID);

            // Return the updated head of the linked list
            return head;
        }

        // Move to the next node
        previous = current;
        current = current->next_individual;
    }
    return head;
}

int main()
{
    struct individual *ind = NULL;
    struct group *grp = NULL;
    struct business *buss = NULL;
    struct organisation *org = NULL;
    while (1)
    {
        int y;
        printf("Input 0 to exit\n      1 to create a node\n      2 to delete a node\n");
        scanf("%d", &y);
        if (y == 0)
        {
            return 0;
        }
        else if (y == 1)
        {
            printf("Input 1 for individual, 2 for group, 3 for business, 4 for organisation\n");
            scanf("%d", &y);
            if (y == 1)
            {
                ind = create_individual(ind);
            }
            else if (y == 2)
            {
                grp = create_group(grp);
            }
            else if (y == 3)
            {
                buss = create_business(buss);
            }
            else
            {
                org = create_organisation(org);
            }
        }
        else if (y == 2)
        {
            printf("Input 1 for individual, 2 for group, 3 for business, 4 for organisation\n");
            scanf("%d", &y);
            int delete_Id;
            printf("Enter the Id you wish to delete\n");
            scanf("%d", &delete_Id);
            if (y == 1)
            {
                ind = delete_individual(ind, grp, buss, org, delete_Id);
            }
            else if (y == 2)
            {
                grp = delete_group(grp, delete_Id);
            }
            else if (y == 3)
            {
                buss = delete_business(buss, delete_Id);
            }
            else
            {
                org = delete_organisation(org, delete_Id);
            }
        }
    }
}