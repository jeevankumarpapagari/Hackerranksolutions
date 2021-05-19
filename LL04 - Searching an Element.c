//-------------------- head of the code ------------------------


#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if (!head) {
        head = malloc(sizeof(LinkedListNode));

        head->val = val;
        head->next = NULL;

        tail = head;
    } else {
        LinkedListNode *node = malloc(sizeof(LinkedListNode));

        node->val = val;
        node->next = NULL;

        tail->next = node;
        tail = tail->next;
    }

    return tail;
}

//-------------------- body of the code ------------------------


/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
int getIndex(LinkedListNode* head, int value) 
{
    LinkedListNode *temp = head;
    int index = 0;
    while(temp!=NULL)//temp
    {
        if(value == temp->val)
            return index;
        index++;
        temp = temp->next;
    }
    return -1;
}

//-------------------- tail of the code ------------------------


int main()
{
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");

    char* head_size_endptr;
    char* head_size_str = readline();
    int head_size = strtol(head_size_str, &head_size_endptr, 10);

    if (head_size_endptr == head_size_str || *head_size_endptr != '\0') { exit(EXIT_FAILURE); }

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;
    int head_i;
    for (head_i = 0; head_i < head_size; head_i++) {
        char* head_item_endptr;
        char* head_item_str = readline();
        int head_item = strtol(head_item_str, &head_item_endptr, 10);

        if (head_item_endptr == head_item_str || *head_item_endptr != '\0') { exit(EXIT_FAILURE); }
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if (!head_i) {
            head = head_tail;
        }
    }

    char* value_endptr;
    char* value_str = readline();
    int value = strtol(value_str, &value_endptr, 10);

    if (value_endptr == value_str || *value_endptr != '\0') { exit(EXIT_FAILURE); }

    int res = getIndex(head, value);

    fprintf(f, "%d\n", res);


    fclose(f);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
