#include "program.h"

#pragma CHECK_MISRA("-17.4") /*Relaksirano u MISRA 2012.*/
#pragma CHECK_MISRA("-20.9") /*Potreban nam je printf, stoga ignorišemo ovo upozorenje.*/
#pragma CHECK_MISRA("-6.1") 

void check_parentheses(const char* expression)
{
	Stack stack = {0};
	stack_init(&stack);

	int8_t has_parentheses = 0;
	int8_t error_occured = 0;
	uint16_t index;

	for (index = (uint16_t)0; expression[index] != '\0'; ++index)
	{
		char current_char = expression[index];

		if ((current_char == '(') || (current_char == ')'))
		{
			has_parentheses++;
		}

		if (current_char == '(')
		{
			push(&stack, (int16_t)index);
		}
		else if (current_char == ')')
		{
			if (is_empty(&stack))
			{
				printf("Neodgovarajuća zatvorena zagrada na indeksu %d\n", index);
				error_occured++;
			}
			else
			{
				uint16_t open_index = (uint16_t)pop(&stack);
				printf("Par zagrada: otvorena na indeksu %d, zatvorena na indeksu %d\n", open_index, index);
			}
		}
		else
		{

		}
	}

	while (!is_empty(&stack))
	    {
	        uint16_t open_indexe = (uint16_t)pop(&stack);
	        printf("Neodgovarajuća otvorena zagrada na indeksu %d\n", open_indexe);
	        error_occured++;
	    }

	if (has_parentheses == 0)
	{
		printf("Izraz ne sadrži zagrade.\n");
	}
	else if ((error_occured == 0) && (has_parentheses > 0))
	{
		printf("Sve zagrade su pravilno uparene.\n");
	}
	else
	{

	}
}
