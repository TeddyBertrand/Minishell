/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** my_cd
*/
#include <struct.h>
#include <tools.h>
#include <command.h>

int changeenv(all_t *bools, char **commande)
{
    struct stat path_stat;

    stat(commande[1], &path_stat);
    if (access(commande[1], F_OK) == 0) {
        if (S_ISDIR(path_stat.st_mode)) {
            bools->status = 0;
            chdir(commande[1]);
            return (0);
        } else {
            bools->status = 1;
            mini_printf("%s: Not a directory.\n", commande[1]);
            return (1);
        }
    }
    bools->status = 1;
    mini_printf("%s: No such file or directory.\n", commande[1]);
    return (1);
}

int cd_back(char **commande, all_t *bools)
{
    char *OLDPWD;

    if (my_strcmp(commande[1], "-") == 0) {
        OLDPWD = get_oldpwd_parser(bools->env);
        if (OLDPWD == NULL) {
            mini_printf("%s: No such file or directory.\n");
            bools->status = 1;
            bools->erroroldpwd = true;
            return (0);
        }
        bools->status = 0;
        chdir(bools->oldpwd);
        return (0);
    }
    return (1);
}

int cd_home(char **commande, all_t *bools)
{
    char *HOME;

    if (my_strcmp(commande[1], "~") == 0) {
        HOME = get_home_parser(bools->env);
        if (HOME == NULL) {
        mini_printf("%s: No such file or directory.\n");
        bools->status = 1;
        bools->errorhome = true;
        return (0);
        }
        bools->status = 0;
        chdir(HOME);
        bools->oldpwd = my_strdup(bools->pwd);
        return (0);
    }
    return (1);
}

void init_bools(all_t *bools)
{
    bools->speflag = false;
    bools->errorhome = false;
    bools->erroroldpwd = false;
}

int commande_cd(char **commande, all_t *bools)
{
    char PWD[BUFSIZ + 1];
    char NEWPWD[BUFSIZ + 1];

    init_bools(bools);
    getcwd(PWD, (BUFSIZ + 1));
    bools->pwd = my_strdup(PWD);
    if (cd_back(commande, bools) == 0)
    bools->speflag = true;
    if (cd_home(commande, bools) == 0)
    bools->speflag = true;
    if (bools->speflag == false) {
    bools->oldpwd = my_strdup(bools->pwd);
    changeenv(bools, commande);
    }
    if (bools->errorhome == false && bools->erroroldpwd == false) {
    getcwd(NEWPWD, (BUFSIZ + 1));
    set_env(bools, "OLDPWD", PWD);
    set_env(bools, "PWD", NEWPWD);
    }
    return (0);
}
