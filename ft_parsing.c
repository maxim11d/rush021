


int is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return(1);
    return(0);
}

int is_digits(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return(1);
}

int key_is_valid(char *key)
{
    int i;

    if (key[0] == '\0')             /* rien du tout                         */
        return (0);
    if (key[0] == '0' && key[1] != '\0')
        return (0);                 /* commence par 0 ET a une suite        */
    i = 0;
    while (key[i] != '\0')
    {
        if (!is_digit(key[i]))      /* un caractere qui n'est pas un chiffre */
            return (0);
        i++;
    }
    return (1);                     /* tout est bon                         */
}

void get_key(char *key, char *line)
{
    int i;
    int j;

    i = 0;
    while (is_space(line[i]))
        i++;

    j = 0;
    while(line[i] != ':' && line[i] != '\0')
    {
        key[j] = line[i];
        j++;
        i++;
    }
    
    while (j > 0 && is_space(key[j - 1]))
        j--;                        /* on recule sur les espaces de la fin  */
    key[j] = '\0';
}

void    get_value(char *line, char *value)
{
    int i;
    int j;

    i = 0;
    while (line[i] != ':' && line[i] != '\0')
        i++;                        /* on avance jusqu'au ':'               */
    if (line[i] == ':')
        i++;                        /* on saute le ':' lui-meme             */
    while (is_space(line[i]))
        i++;                        /* on saute les espaces du debut        */
    j = 0;
    while (line[i] != '\0')
    {
        value[j] = line[i];         /* on recopie tout le reste             */
        i++;
        j++;
    }
    while (j > 0 && is_space(value[j - 1]))
        j--;                        /* on recule sur les espaces de la fin  */
    value[j] = '\0';
}

