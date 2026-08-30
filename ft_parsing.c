#include "list.h"
#include "string.h"

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        return (1);
    return (0);
}


int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

/*
** Trois refus :
**     ""      -> cle vide
**     "007"   -> un zero devant alors qu'il y a d'autres chiffres apres
**     "4a"    -> il y a autre chose qu'un chiffre
*/
int key_is_valid(char *key)
{
    int i;

    if (key[0] == '\0')
        return (0);
    if (key[0] == '0' && key[1] != '\0')
        return (0);
    i = 0;
    while (key[i] != '\0')
    {
        if (!is_digit(key[i]))
            return (0);
        i++;
    }
    return (1);
}

/*
** get_key : remplit "key" avec le nombre situe AVANT le ':'.
** Rend 1 si la cle est valide, 0 sinon.
*/
int get_key(char *line, char *key)
{
    int i;
    int j;

    i = 0;
    while (is_space(line[i]))  /* on saute les espaces du debut */
        i++;
    j = 0;
    while (line[i] != ':' && line[i] != '\0')
    {
        key[j] = line[i];  /* on recopie caractere par caractere */
        i++;
        j++;
    }
    if (line[i] != ':') /* on est arrive au bout sans ':'  */
        return (0);
    while (j > 0 && is_space(key[j - 1]))
        j--;                        /* on recule sur les espaces de la fin  */
    key[j] = '\0';                  /* on ferme la chaine                   */
    return (key_is_valid(key));     /* et on verifie ce qu'on a recupere    */
}

/*
** get_value : remplit "value" avec le nom situe APRES le ':'.
**   "  42  :  forty two  "
**               ce morceau, sans les espaces des bords
** l'espace au MILIEU de "forty two" doit rester.
*/
int get_value(char *line, char *value)
{
    int i;
    int j;

    i = 0;
    while (line[i] != ':' && line[i] != '\0')
        i++; 
    if (line[i] != ':') 
        return (0);
    i++;
    while (is_space(line[i]))
        i++;
    j = 0;
    while (line[i] != '\0')
    {
        value[j] = line[i];
        i++;
        j++;
    }
    while (j > 0 && is_space(value[j - 1]))
        j--;                        /* on recule sur les espaces de la fin  */
    value[j] = '\0';                /* on ferme la chaine                   */
    return (value[0] != '\0');      /* 0 si la valeur est vide              */
}

int double_array(char *str)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while(str[i])
    {
        if (str[i] == '\n')
            j++;
        i++;
    }
    return(j);
}

char **malloc_str(char **str, int count)
{
    str = malloc(sizeof(char *)* count);
    if (!str)
        return(0);
}
#include <stdio.h>

int main(void)
{
    char    line[] = "  42  :  forty two  ";
    char    key[1024];
    char    value[1024];

    /*
    ** get_key lit line, ecrit dans key, et rend 1 ou 0.
    ** On compare a 0 : si la fonction a rendu 0, la cle est inutilisable
    **
    ** On arrete tout de suite : inutile de chercher la valeur si la cle
    ** est deja mauvaise.
    */
    if (get_key(line, key) == 0)
    {
        printf("cle invalide\n");
        return (1);            /* 1 = le programme s'arrete en erreur      */
    }

    /*
    ** Meme chose pour la valeur. Elle peut etre vide alors que la cle est
    ** bonne, par exemple avec la ligne "42 :    ".
    */
    if (get_value(line, value) == 0)
    {
        printf("valeur vide\n");
        return (1);
    }

    /*
    ** Arrive ici, les deux fonctions ont reussi : key et value contiennent
    ** des chaines propres, terminees par '\0'.
    */
    printf("key   = [%s]\n", key);
    printf("value = [%s]\n", value);

    return (0);
}