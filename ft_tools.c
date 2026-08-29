
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}
int  parse_line(char *line, char **key, char **value)
{
    int colon;                      /* position du ':'                      */
    int len;                        /* longueur totale de la ligne          */

    *key = 0;                       /* on vide les deux sorties par sécurité */
    *value = 0;
    len = 0;
}