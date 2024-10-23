#include "program.h"

#pragma CHECK_MISRA("-20.9") /*Potreban nam je printf, stoga ignorišemo ovo upozorenje.*/
#pragma CHECK_MISRA("-8.1") /*Nema potebe za deklarisanje main-a.*/

/*
 * Autor: Žarko Marić RA225/2021
 * 
 * Napraviti modul koji predstavlja stek. 
 * Modul izvesti kao statičku biblioteku. 
 * Zatim, oslanjajući se na taj stek, napraviti funkciju koja prima znakovni niz čiji sadržaj predstavlja matematičku formulu.
 * U takvom znakovnom nizu funkcija proverava da li svaka otvorena zagrada '(' ima svoju odgovarajuću zatvorenu zagradu ')',
 * i na standardni izlaz ispisuje indekse (indekse znakova u zadatkom znakovnom nizu) parova zagrada.
 * 
 * Ograničenja:
 * - Maksimalna dužina izraza je ograničena sa STACK_MAX_SIZE.
 * 
 * Uputstvo za pokretanje:
 * - Potrebno je pozicionirati se u folder sa projektom, preciznije u folder ../ti_tools/ , 
 * a potom kompajlovati program uz pomoć gcc main.c program.c -L. -lstack. Program možemo pokrenuti komandom ./a.out.
 * - Kako bismo proverili MISRA standard, potrebno je pozicionirati se u ti_tools folder, potom pokrenuti komandu source set_env.sh,
 * potom pokrenuti komandu cl6x --include_path=$TI_INCLUDE --compile_only --check_misra=all ime_programa.c
 */

int32_t main(void) {
    /* Unos korisnikove funkcije. */
    char input[STACK_MAX_SIZE] = {0};
    printf("Unesite matematičku funkciju: \n");
    fgets(input, (int32_t)sizeof(input), stdin);

    printf("Provera zagrada za uneti izraz: %s\n", input);
    check_parentheses(input);

    printf("\n");

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
