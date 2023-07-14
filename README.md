# Installer

A library for installing files from your github repository.

# How to use

Create "files" file:

> The "files" file will contain all files you want to be downloaded that are in the repository seperated by newlines.
1. Create a file named "files" (you can specify if you want a different name) in your github repository.
2. Paste each filename seperated by a newline into the file.


Some steps to manually use the InstallPath struct:

1. Create a struct InstallPath with the init_install function.
   * The first argument will be a string in the syntax of "your username/your repository/branch".
   * The second argument is the name of your "files" file, if it is just "files" you can leave this as NULL.
2. Remember to check if the InstallPath is NULL and catch any errors.
3. Run the install_files function.
    * The first argument is a pointer to your InstallPath struct you made in step 1.
    * The second argument can be left as NULL for the current working directory, or can be a custom directory. (this directory must already exist otherwise it will not install).
4. When you are finished with the InstallPath struct you made, run finish_install to free any remaining memory blocks.
    * The only argument is a pointer to your InstallPath struct.

# Example

The high-level install function:

```c
#include "install.h"

int main(void)
{
    // presume repo and files are already defined (files can be set to NULL for default "files")
    install(repo, files, "folder name"); // installs into "folder name"
    //install(repo, files, NULL); // installs into current working directory.
    return 0;
}
```

A typical low level installer might look like this. (repo and files may be pre-defined) - it is recommended to use the high-level isntall function in most cases.

```c
#include "install.h"

int main(void)
{
    // presume repo and files are already defined (files can be set to NULL for default "files")
    InstallPath *ip = init_install(repo, files); // CREATE InstallPath STRUCT

    if (!ip)
        return 1; // CHECK IF ANY ERRORS OCCURRED

    //install_files(ip, "folder name"); // Install into folder.
    install_files(ip, NULL); // Install into current working directory.

    finish_install(ip);

    return 0;
}
```

# Compiling

- You must link install.c with your main file, that is easily done by running `compiler main.c install.c flags`.
- You must link the library urlmon like: `compiler ... -lurlmon`.

> Replace compiler with your compiler (e.g. "gcc" for gcc or "clang" for clang).
