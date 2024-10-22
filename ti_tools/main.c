#include "program.h"

/*
 * Autor: Žarko Marić RA225/2021
 * 
 * Ovaj program implementira modul steka i koristi ga za proveru da li su
 * zagrade u zadatom matematičkom izrazu pravilno uparene. Program poštuje C17 sandrad i MISRA-C:2004
 * gde god je moguće.
 *
 * Pretpostavke:
 * - Izraz se sastoji od ASCII karaktera.
 * - Proveravaju se samo zagrade '(' i ')'.
 * 
 * Ograničenja:
 * - Maksimalna dužina izraza je ograničena sa STACK_MAX_SIZE.
 * 
 * Uputstvo za pokretanje:
 * -Potrebno je pozicionirati se folder sa projektom, preciznije u folder ../ti_tools/ i pokrenuti komandu source set_env.sh,
 *  a potom kompajlovati program uz pomoć gcc main.c stack.c program.c. Program možemo pokrenuti komandom ./a.out.
 */

int32_t main(void) {
    /* Unos korisnikove funkcije. */
    char input[STACK_MAX_SIZE];
    printf("Unesite matematičku funkciju: \n");
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && (input[len - 1] == '\n'))
    {
        input[len - 1] = '\0';
    }

    printf("Provera zagrada za uneti izraz: %s\n", input);
    check_parentheses(input);

    /* Test 1: Ispravno uparene zagrade */
    const char* test1 = "(1 + 2) * (3 + (4 - 5))";
    printf("Test 1: Provera zagrada za izraz: %s\n", test1);
    check_parentheses(test1);

    /* Test 2: Nedostaje zatvorena zagrada */
    const char* test2 = "((1 + 2) * (3 + (4 - 5)";
    printf("\nTest 2: Provera zagrada za izraz: %s\n", test2);
    check_parentheses(test2);

    /* Test 3: Višak zatvorenih zagrada */
    const char* test3 = "(1 + 2)) * (3 + (4 - 5))";
    printf("\nTest 3: Provera zagrada za izraz: %s\n", test3);
    check_parentheses(test3);

    /* Test 4: Nema zagrada */
    const char* test4 = "1 + 2 * 3 + 4 - 5";
    printf("\nTest 4: Provera zagrada za izraz: %s\n", test4);
    check_parentheses(test4);

    const char* test5 = "((((((((((";
    printf("\nTest 5: Provera zagrada za izraz: %s\n", test5);
    check_parentheses(test5);

    const char* test6 = "))))))))))";
    printf("\nTest 6: Provera zagrada za izraz: %s\n", test6);
    check_parentheses(test6);
    

    return 0;
}
