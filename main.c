#include "op.h"

int main(int argc, char **argv)
{
	char *filename, ch, buffer[200];
	FILE *input;
	int value, i = -1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	input = fopen(filename, "r");
	if (input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(input)) != EOF)
	{
		if (isalpha(ch))
		{
			while (ch != ' ' && ch != '	' && ch != EOF)
			{
				buffer[++i] = ch;
				ch = fgetc(input);
			}
			buffer[i + 1] = '\0';
			printf("%s\n",buffer);
			if (strncmp(buffer, "push", sizeof(buffer))== 0)
			{
				ch = fgetc(input);
				value = atoi(&ch);
				printf("Okay:%d\n", value);
				head = _push(&head, value);
			}
			else if (strcmp(buffer, "pall") == 0)
			{
				pall(&head);
				printf("PALL\n");
			}
			i = -1;
		}
		else if (ch == ' ')
			continue;
	}
	printf("done\n");

	fclose(input);
}
stack_t *_push(stack_t **current, int num)
{
	stack_t *temp = malloc(sizeof(stack_t));

	temp->prev = NULL;
	temp->next = *current;
	temp->n = num;
	if (*current != NULL)
		(*current)->prev = temp;
	return temp;
}
void pall (stack_t **head)
{
	if (*head == NULL)
	{
		perror("Stack is empty");
		return;
	}
	stack_t *current = *head;
	while (current != NULL)
	{
		printf("%d\n",current->n);
		current = current->next;
	}
}
