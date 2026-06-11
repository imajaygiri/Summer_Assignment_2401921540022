#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100000] = {0};
int count = 0;
int top = -1;

void reverse_arr(char* arr, int len) {
    int left = 0;
    int right = len - 1;
    while (left < right) {
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void stack_reverse() {
    int left = 0;
    int right = top;

    while (left < right) {
        int temp = stack[left];
        stack[left] = stack[right];
        stack[right] = temp;
        left++;
        right--;
    }
}

void stack_pop() {
    assert(count > 0);
    stack[top] = 0;
    count--;
    top--;
}

void stack_push(char element) {
    assert(count < 100000);
    stack[++top] = element;
    count++;
}

char stack_top() {
    assert(top >= 0);
    return stack[top];
}

char* decodeString(char* s) {
    int slen = strlen(s);
    for (int i = 0; i < slen; i++) {
        char ch = s[i];
        if (ch == ']') {
            int idx = 0;
            char pattern[100000] = {0};
            // pop until ]
            while (stack_top() != '[') {
                pattern[idx++] = stack_top();
                stack_pop();
            }
            stack_pop();  // removing [
                          // now makes number

            // reverse the pattern
            reverse_arr(pattern, idx);

            int num = {0};
            int place = 1;
            while (top >= 0 && isdigit(stack_top())) {
                num += place * (stack_top() - '0');
                place *= 10;

                stack_pop();
            }
            // now build the pattern and push back to stack
            // push pattern num times
            for (int i = 0; i < num; i++) {
                for (int j = 0; j < idx; j++) {
                    stack_push(pattern[j]);
                }
            }

        } else {
            stack_push(ch);
        }
    }

    char* ans = malloc(sizeof(char) * (count + 1));

    for (int i = 0; i < count; i++) {
        ans[i] = stack[i];
    }
    ans[count] = '\0';

    count = 0;
    top = -1;
    return ans;
}

typedef struct {
    char* args;
    char* expected;
} test_t;

int main(void) {
    test_t t[3] = {{.args = "3[a]2[bc]", .expected = "aaabcbc"},
                   {.args = "3[a2[c]]", .expected = "accaccacc"},
                   {
                       .args = "2[abc]3[cd]ef",
                       .expected = "abcabccdcdcdef",
                   }};

    for (int i = 0; i < 3; i++) {
        char* ans = decodeString(t[i].args);
        assert(strcmp(ans, t[i].expected) == 0);
        free(ans);
    }
    return 0;
}
