#include "main.h"

/**
 * get_path_value - Récupère la valeur de la variable d'environnement PATH.
 *
 * Return: Un pointeur vers la valeur du PATH (après le '='), ou NULL.
 */
char *get_path_value(void)
{
    int i = 0;
    char *name = "PATH=";
    extern char **environ; /* Accès global à l'environnement */

    if (environ == NULL)
        return (NULL);

    while (environ[i])
    {
        /* On compare les 5 premiers caractères pour trouver "PATH=" */
        if (strncmp(environ[i], name, 5) == 0)
        {
            /* On retourne l'adresse juste après le '=' */
            return (environ[i] + 5);
        }
        i++;
    }
    return (NULL);
}
