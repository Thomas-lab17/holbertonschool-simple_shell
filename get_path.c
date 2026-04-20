#include "main.h"
#include <sys/stat.h>

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
