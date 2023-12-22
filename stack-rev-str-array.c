/*
Problem: CBASIC_NVTUNG_STACK_REVERSE_STR_ARR
Description
Câì đặt cấu trúc dữ liệu Stack bằng cách sử dụng mảng để chứa được chuỗi tối đa 20 kí tự có nghĩa để giải quyết bài toán sau:
Stack chỉ có thể chứa 500 kí tự.
Biết chuỗi chỉ chứa kí tự chữ và số (alphanumeric).
1. Nhập 1 chuỗi từ bàn phím
2. In nội dung chuỗi ra màn hình theo thứ tự ngược lại
Ngoại lệ: Nếu chuỗi rỗng in ra 1
Nếu Stack full in ra 2
Ví dụ:
Input: Nguyen
Output: neyugN
Input:
Output:1
Input: TheruleusedinlinesandistoprintanoperandwhenitisreadTheruleforlineistopushanoperatorontothestackifitisemptyTheruleforlineisiftheoperatoronthetopofthestackhashigherprecedencethantheonebeingreadpopandprinttheoneontopandthenpushthenewoperatoronTheruleforlineisthatwhentheendoftheexpressionhasbeenreachedpoptheoperatorsonthestackoneatatimeandprintthemHeretheorderoftheoperatorsmustbereversedThestackissuitableforthissinceoperatorswillbepoppedoffinthereverseorderfromthatinwhichtheywerepushedInlinethesigna
Output:2
*/
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 500
#define MAX_STRING_SIZE 20

struct Stack {
    char data[MAX_STACK_SIZE];
    int top;
};

void initialize(struct Stack* stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}

int isFull(struct Stack* stack)
{
    return (stack->top == MAX_STACK_SIZE - 1);
}

void push(struct Stack* stack, char item)
{
    if (!isFull(stack)) {
        stack->data[++stack->top] = item;
    }
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    char input[MAX_STRING_SIZE + 1];

    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    if (strlen(input) == 0) {
        printf("1\n");
        return 0;
    }

    if (strlen(input) > MAX_STRING_SIZE) {
        printf("2\n");
        return 0;
    }

    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}
/*
 * Wrong 2 test cases?
 */
