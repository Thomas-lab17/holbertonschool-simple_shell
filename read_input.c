#include "main.h"

/**
 * read_input - Reads a line of input from the user.
 * Return: A pointer to the input string, or NULL on failure or EOF.
 */

char *read_input(void)
{
char *line = NULL;/* Buffer où getline va stocker la commande */
size_t bufsize = 0; /* Taille du buffer (getline s'occupe de l'allouer) */
ssize_t nread; /* Nombre de caractères lus */


/* getline alloue la mémoire automatiquement car line est NULL */
nread = getline(&line, &bufsize, stdin);

/* Vérification : est-ce que ça a fonctionné ? */
if (nread == -1)
{
/* Si nread == -1, c'est soit une erreur, soit Ctrl+D (EOF) */
free(line); /* On libère la mémoire allouée par getline */
return (NULL);
}

return (line);/* On retourne la commande (à libérer plus tard) */
}
