/*
** EPITECH PROJECT, 2025
** B-PSU-200-MPL-2-1-minishell1-teddy.bertrand
** File description:
** set_fork
*/
#include <struct.h>
#include <tools.h>

void get_status(all_t *bools, int status)
{
    if (WIFEXITED(status)) {
        bools->status = WEXITSTATUS(status);
        return;
    }
    if (WIFSIGNALED(status)) {
        bools->segmented = WTERMSIG(status);
        if (bools->segmented == SIGSEGV)
        my_putstr_error("Segmentation fault (core dumped)\n", 2);
        if (bools->segmented == SIGBUS)
        my_putstr_error("Bus error (core dumped)\n", 2);
        if (bools->segmented == SIGFPE)
        my_putstr_error("Floating point exception (core dumped)\n", 2);
        bools->status = status;
    }
}

int permission_denied(char **commande, all_t *bools)
{
    if (access(commande[0], F_OK) == 0) {
        if (errno == 8) {
            my_putstr_error(commande[0], 2);
            my_putstr_error(": Exec format error. Binary"
            " file not executable.\n", 2);
            bools->status = 1;
            return (0);
        } else {
            my_putstr_error(commande[0], 2);
            my_putstr_error(": Permission denied.\n", 2);
            bools->status = 1;
            return (0);
        }
    } else {
        my_putstr_error(commande[0], 2);
        my_putstr_error(": Command not found.\n", 2);
        bools->status = 1;
    }
    return (1);
}

void set_fork(all_t *bools, char **commande)
{
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        execve(commande[0], commande, bools->env);
        permission_denied(commande, bools);
        exit(1);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        get_status(bools, status);
    } else {
        perror("fork");
        exit(1);
    }
}
