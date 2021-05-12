#include "monty.h"

/**
 * _errorSubStackTooShort - display when stack is too short
 */
void _errorSubStackTooShort(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", appData->lineNumber);
}
