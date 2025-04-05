/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-minishell1-alban.lembrez
** File description:
** test_unit_tests.c
*/
#include <tools.h>
#include <struct.h>
#include <main.h>
#include <tests.h>
#include <command.h>

void redirect_all(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

void simulate_input(const char *input) {
    FILE *input_stream = fmemopen((void *)input, my_strlen(input), "r");
    if (!input_stream) {
        perror("fmemopen failed");
        exit(1);
    }
    stdin = input_stream;
}

Test (my_tcsh, test_ls, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("ls");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_usr_bin_ls, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("/usr/bin/ls");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd_home, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd ~");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd_dash, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd -");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd_dotdot, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd ..");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd_home_dir, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd /home");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd_invalid, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_yo_yo, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv yo yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_shell_yo, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv SHELL yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_no_args, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_invalid_args, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv yo yoy oy");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_invalid_syntax, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv yo= yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_one_argument, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_invalid_name, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv 1yo yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_setenv_good_name, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("setenv PATH yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_unsetenv_no_args, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("unsetenv");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_unsetenv_path, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("unsetenv PATH");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_env, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("env");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_env_invalid, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("env yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_invalid_command, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("/home");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_invalid_command_yo, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd_file, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd /etc/sudoers");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_exit, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("exit");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_echo_status, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("echo $?");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_empty_input, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_empty_input2, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("\n");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_empty_input3, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("\t");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_help, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("\t");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_squeezie, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("squeezie");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_antoine, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("antoine");
    my_tcsh(argc, argv, env);
}

Test(mini_printf, test_printf, .init=redirect_all)
{
    mini_printf("%s %c %% %i %d\n", "yo", 'c', -100, 100);
}

Test(handle_signal, test_signal, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;
    all_t *all = malloc(sizeof(all_t));
    init_all(all, env);

    all->status = 11;
    get_status(all, 139);
}

Test (my_tcsh, test_exit1, .init=redirect_all)
{
    char *commande[] = {"exit", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_tcsh, test_exit2, .init=redirect_all)
{
    char *commande[] = {"exit", "1", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_tcsh, test_exit3, .init=redirect_all)
{
    char *commande[] = {"exit", "0", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_tcsh, test_exit4, .init=redirect_all)
{
    char *commande[] = {"exit", "100", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_tcsh, test_exit5, .init=redirect_all)
{
    char *commande[] = {"exit", "-1", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_tcsh, test_exit6, .init=redirect_all)
{
    char *commande[] = {"exit", "lol", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_tcsh, test_exit7, .init=redirect_all)
{
    char *commande[] = {"exit", "1", "1", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_tcsh, test_exit8, .init=redirect_all)
{
    char *commande[] = {"exit", "1", "lol", NULL};
    all_t *all = malloc(sizeof(all_t));
    my_exit(all, commande);
}

Test (my_getnbr, test_getnbr)
{
    cr_assert_eq(my_getnbr("1"), 1);
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr("-1"), -1);
    cr_assert_eq(my_getnbr("100"), 100);
    cr_assert_eq(my_getnbr("-100"), -100);
    cr_assert_eq(my_getnbr("lol"), 0);
    cr_assert_eq(my_getnbr("1lol"), 1);
    cr_assert_eq(my_getnbr("lol1"), 0);
    cr_assert_eq(my_getnbr("1lol1"), 1);
    cr_assert_eq(my_getnbr("---100"), -100);
    cr_assert_eq(my_getnbr("100---"), 100);
    cr_assert_eq(my_getnbr("-+--+-+-100"), -100);
    cr_assert_eq(my_getnbr("-2147483647"), -2147483647);
}

Test (my_cd, test_cdhome1)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "HOME=/home", NULL};
    init_all(all, env);
    int argc = 1;
    simulate_input("cd");
    my_tcsh(argc, argv, env);
}

Test (my_cd, test_cdhome2)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "HOME=/home", NULL};
    init_all(all, env);
    int argc = 1;
    simulate_input("cd ~");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cd1, .init=redirect_all)
{
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    int argc = 1;

    simulate_input("cd yo yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_cdoldpwd, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", NULL};
    int argc = 1;
    init_all(all, env);

    simulate_input("cd -");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_nothing, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", NULL};
    int argc = 1;
    init_all(all, env);

    simulate_input("");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_env_numbers, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", NULL};
    int argc = 1;
    init_all(all, env);

    simulate_input("setenv A1A1 1");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_print_help, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", "-h", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", NULL};
    int argc = 2;
    init_all(all, env);

    simulate_input("setenv A1A1 1");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_unsetenv, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", "-h", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", "HOME=/home", NULL};
    int argc = 2;
    init_all(all, env);

    simulate_input("unsetenv OLDPWD");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_pipe, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", "HOME=/home", NULL};
    int argc = 1;

    init_all(all, env);
    simulate_input("ls -l|grep yo");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_pipe1, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", "HOME=/home", NULL};
    int argc = 1;

    init_all(all, env);
    simulate_input("ls -l|grep yo|grep 2");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_pipe2, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", "HOME=/home", NULL};
    int argc = 1;

    init_all(all, env);
    simulate_input("ls -l|grep yo > txt");
    my_tcsh(argc, argv, env);
}

Test (my_tcsh, test_pipe3, .init=redirect_all)
{
    all_t *all = malloc(sizeof(all_t));
    char *argv[] = {"./mysh", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", "OLDPWD=/home", "HOME=/home", NULL};
    int argc = 1;

    init_all(all, env);
    simulate_input("ls -l; ls -l; ls -l");
    my_tcsh(argc, argv, env);
}
