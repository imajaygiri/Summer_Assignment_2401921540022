#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define let __auto_type

#define stack_push(stack, __val)           \
    do {                                   \
        __typeof__(__val) _temp = (__val); \
        Stack_push(stack, &_temp);         \
    } while (0)

typedef struct Stack {
    void* data;
    size_t len;
    size_t cap;
    size_t element_size;
} Stack;

Stack* Stack_init_with_cap(const size_t element_size,
                           size_t capacity) {
    Stack* stack = malloc(sizeof(Stack));
    if (!stack) {
        perror("Error allocating memory in init Stack");
        exit(-1);
    }
    stack->cap = capacity > 0 ? capacity : 1;
    stack->data = malloc(element_size * stack->cap);
    if (!stack->data) {
        perror("Error allocating memory for stack");
        exit(-1);
    }
    stack->len = 0;
    stack->element_size = element_size;
    return stack;
}

Stack* Stack_init(const size_t element_size) {
    return Stack_init_with_cap(element_size, 1);
}

bool Stack_push(Stack* stack, const void* val) {
    if (stack->len == stack->cap) {
        size_t new_cap = stack->cap * 2;
        void* newData =
            realloc(stack->data, stack->element_size * new_cap);

        if (newData != NULL) {
            stack->data = newData;
            stack->cap = new_cap;
        } else {
            fprintf(stderr,
                    "Error allocating new memory for Stack %s: %d\n",
                    __FILE__,
                    __LINE__);
            return false;
        }
    }

    char* dst = (char*)stack->data + stack->element_size * stack->len;
    memcpy(dst, val, stack->element_size);
    stack->len++;
    return true;
}

void Stack_destroy(Stack* stack) {
    free(stack->data);
    free(stack);
}

void* Stack_peek(Stack* stack) {
    if (stack->len < 1)
        return NULL;
    char* target =
        (char*)stack->data + stack->element_size * (stack->len - 1);
    return target;
}

bool Stack_pop(Stack* stack) {
    if (stack->len < 1)
        return false;
    stack->len--;
    return true;
}

size_t Stack_len(Stack* stack) {
    return stack->len;
}

bool Stack_is_empty(Stack* stack) {
    return stack->len == 0;
}

static void transer(Stack* dst, Stack* src) {
    while (!Stack_is_empty(src)) {
        let val = Stack_peek(src);
        Stack_push(dst, val);
        Stack_pop(src);
    }
}

typedef struct {
    Stack* stack1;
    Stack* stack2;
} MyQueue;

MyQueue* myQueueCreate() {
    let queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (!queue) {
        perror("Error Initing Queueu");
        return NULL;
    }
    queue->stack1 = Stack_init(sizeof(int));
    queue->stack2 = Stack_init(sizeof(int));
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    stack_push(obj->stack1, x);
}

int myQueuePop(MyQueue* obj) {
    if (Stack_is_empty(obj->stack2)) {
        transer(obj->stack2, obj->stack1);
    }
    let poped_val = Stack_peek(obj->stack2);
    Stack_pop(obj->stack2);
    return *(int*)poped_val;
}

int myQueuePeek(MyQueue* obj) {
    if (Stack_is_empty(obj->stack2)) {
        transer(obj->stack2, obj->stack1);
    }
    let peek_val = Stack_peek(obj->stack2);
    return *(int*)peek_val;
}

bool myQueueEmpty(MyQueue* obj) {
    if (Stack_is_empty(obj->stack1) && Stack_is_empty(obj->stack2))
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    Stack_destroy(obj->stack1);
    Stack_destroy(obj->stack2);
    free(obj);
}

int main(void){
    let queue = myQueueCreate();
    myQueuePush(queue, 10);
    myQueuePush(queue, 20);
    let val = myQueuePop(queue);
    printf("poped val: %d\n", val);
    val = myQueuePop(queue);
    printf("poped val: %d\n", val);

    myQueuePush(queue, 20);
    myQueuePush(queue, 5);
    val = myQueuePop(queue);
    printf("poped val: %d\n", val);
    val = myQueuePeek(queue);
    printf("peek val: %d\n", val);
    return 0;
}
