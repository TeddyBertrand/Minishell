# Minishell2: Custom Shell Implementation

## 📜 Description

**Minishell2** is a simple Unix shell implementation, built as part of the **Epitech** curriculum. It mimics a basic shell interface where users can execute commands, navigate directories, and manage processes.

This project aims to develop a deeper understanding of how shells work and how to manage processes and system calls in a Unix-like environment.

## 💻 Project Features

### ✅ Core Features

- **Command Execution**: Users can run shell commands by typing them in and executing them directly in the shell.
- **Pipe Support**: Executes multiple commands in a pipeline, i.e., `command1 | command2`.
- **Redirection**: Supports input and output redirection, i.e., `command > file` or `command < file`.
- **Environment Variables**: Manages environment variables and allows users to set, modify, and unset them.
- **Custom Prompts**: The shell shows a customizable prompt for users to interact with.
- **Exit Command**: Implements an `exit` command to close the shell with a proper exit code.

### 🔧 Additional Features (if applicable)

- **Background Execution**: Execute commands in the background with `&`.
- **Signal Handling**: Properly handles signals (e.g., `Ctrl+C` to interrupt commands).
- **Multiple Commands**: Supports running multiple commands in a single line, separated by semicolons (`;`).
- **Custom Built-ins**: Implements built-in commands such as `cd`, `exit`, `setenv`, `unsetenv`, etc.

---

## ⚙️ Compilation

### Prerequisites

- **C Compiler (gcc)**: Make sure you have a C compiler installed (e.g., `gcc`).
- **Make**: The project uses `Make` to automate the build process.

