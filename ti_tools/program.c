#include "program.h"

#pragma CHECK_MISRA("-17.4") /*Relaksirano u MISRA 2012*/
#pragma CHECK_MISRA("-20.9") /*Ignorišemo jer nam je potreban printf.*/

void check_parentheses(const char* expression) {
    Stack stack = {0};
    stack_init(&stack);
    int8_t has_parentheses = 0;
    int8_t error_occured = 0;

    uint16_t index;

    for (index = (uint16_t)0; expression[index] != '\0'; ++index) {
        char current_char = expression[index];

        if ((current_char == '(') || (current_char == ')')) {
            has_parentheses++;
        }

        if (current_char == '(') {
            push(&stack, (char)index);
        } else if (current_char == ')') {
            if (is_empty(&stack)) {
                printf("Višak zatvorene zagrade na indeksu %zu\n", index);
                error_occured++;
                break;
            }
            char open_index = pop(&stack);
            printf("Par zagrada: otvorena na indeksu %d, zatvorena na indeksu %zu\n", (uint16_t)open_index, index);
        }
    }

    char open_indexe;

    if (error_occured){
         while (!is_empty(&stack)) {
            open_indexe = pop(&stack);
            printf("Neodgovarajuća otvorena zagrada na indeksu %d\n", open_indexe);
        }
    }else{
        if ((has_parentheses == 1) && is_empty(&stack)) {
            printf("Sve zagrade su pravilno uparene.\n");
        } else if (has_parentheses == 0) {
            printf("Izraz ne sadrži zagrade.\n");
        } else {
            while (!is_empty(&stack)) {
                open_indexe = pop(&stack);
                printf("Neodgovarajuća otvorena zagrada na indeksu %d\n", open_indexe);
            }
        }
    }
}

