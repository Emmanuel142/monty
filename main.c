#include "op.h"

int main(int argc, char **argv)
{
	char *filename;
	FILE *input;

	if (argc != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	input = fopen(filename, 'r');
	if (input == NULL)
	{
		perror("Error: Can't open file <file>");
		exit(EXIT_FAILURE);
	}

	fclose(input);

}
stack_t *push(stact_t **current, int num)
{
	stack_t *temp = malloc(sizeof(stact_t));

	temp->prev = *current;
	temp->next = NULL;
	temp->n = num;
	current->next = temp;
	return temp;
}
