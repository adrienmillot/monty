#include "monty.h"

data_t *appData;

int main(int prmArgc, char **prmArgv)
{
	FILE *fileDescriptor;
	void (*func)(stack_t **, unsigned int);

	_initAppData();

	if (prmArgc != 2)
		_errorHandler(INVALID_ARGUMENT_NUMBER);	/** @TODO: memory free to think **/

	fileDescriptor = fopen(prmArgv[1], "r");

	if (fileDescriptor == NULL)
		_errorHandler(INVALID_FILE); /** @TODO: memory free to think **/

	appData->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);

	if (appData->buffer == NULL)
		return (EXIT_FAILURE);

	while (fgets(appData->buffer, BUFFER_SIZE, fileDescriptor))
	{
		appData->arguments = _strtow(appData->buffer, COMMAND_SEPARATOR, NULL);

		if (appData->arguments == NULL)
		{
			fclose(fileDescriptor);
			_errorHandler(INVALID_PARSING_ARGUMENT);
		}

		func = _getCustomFunction(appData->arguments[0]);

		if (func != NULL)
			func(&appData->queue, 1);
		_freeCharDoublePointer(appData->arguments);
		appData->arguments = NULL;
	}

	fclose(fileDescriptor);
	_freeAppData();

	exit(EXIT_SUCCESS);
}
