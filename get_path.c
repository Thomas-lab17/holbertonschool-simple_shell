#include "main.h"
#include <sys/stat.h>
/**
 * get_path - find the full path of a command in thePATH
 * @command: the name of the command to find (e.g., "ls")
 *
 * Return: A pointer to the full path (e.g., "/bin/ls"), or NULL if not found.
 */

char *get_path(const char *command)
{
char *path_env, *path_copy, *dir, *full_path;
struct stat st;

/* 1. Récupérer le contenu du PATH */
path_env = get_path_value(); /* La fonction qu'on a vue juste avant */

if (!path_env)
return (NULL);

/* 2. Copier le PATH pour ne pas modifier l'original avec strtok */
path_copy = strdup(path_env);

/* 3. Découper le PATH en dossiers (séparateur ':') */
dir = strtok(path_copy, ":");
while (dir != NULL)
{
/* Créer le chemin complet : dossier + / + commande */
/* Exemple : /bin + / + ls = /bin/ls */
full_path = malloc(strlen(dir) + strlen(command) + 2);
sprintf(full_path, "%s/%s", dir, command);

/* 4. Vérifier si le fichier existe à cet endroit */
if (stat(full_path, &st) == 0)
{
free(path_copy);
return (full_path); /* On a trouvé ! On renvoie le chemin */
}

free(full_path); /* Pas trouvé ici, on libère et on continue */
dir = strtok(NULL, ":");
}

free(path_copy);
return (NULL); /* La commande n'a été trouvée nulle part */
}

/**
 * get_path_value - takes the value of the PATH environnement
 *
 * Return: A pointer to the value of PATH (after the '='), or NULL.
 */
char *get_path_value(void)
{
int i = 0;
char *name = "PATH=";


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
