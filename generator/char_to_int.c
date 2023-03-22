/*
** EPITECH PROJECT, 2022
** convert char to int
** File description:
** char to int
*/

int makeintt(const char *format, int i,int bob)
{
    char chiffre[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    for (int y = 0; chiffre[y] != '\0'; y++)
        if (format[i + 1] == chiffre[y]) {
            bob = bob * 10 + format[i +1] - 48;
            bob = makeintt(format, i + 1, bob);
            }
    return (bob);
}

int my_natoi(const char *format, int i)
{
    for (int y = 0; format[y]; y++)
        if (!(format[y] >= 48 && format[y] <= 57))
            return (-1);
    int bob = format[i] - 48;
    bob = makeintt(format, i, bob);
    return (bob);
}

int my_atoi(const char *format)
{
    for (int y = 0; format[y]; y++)
        if (!(format[y] >= 48 && format[y] <= 57))
            return (-1);
    int bob = format[0] - 48;
    bob = makeintt(format, 0, bob);
    return (bob);
}
