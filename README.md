# Installer

A library for installing files from your github repository.

# How to use

It is very simple:

1. Create a file named "files" (you can specify if you want a different name) in your github repository.
2. Paste each filename seperated by a newline into the file.
3. Create a struct InstallPath with the init_install function.
   * The first argument will be a string in the syntax of "your username/your repository/branch".
   * The second argument is the name of your "files" file, if it is just "files" you can leave this as NULL.
4. Remember to check if the InstallPath is NULL and catch any errors.
5. Run the install_files function.
    * The first argument is a pointer to your InstallPath struct you made in step 3.
    * The second argument can be left as NULL for the current working directory, or can be a custom directory. (this directory must already exist otherwise it will not install).
6. When you are finished with the InstallPath struct you made, run finish_install to free any remaining memory blocks.
    * The only argument is a pointer to your InstallPath struct.

# Example

A typical installer might look like this. (repo and files may be pre-defined)

```c
#include "install.h"

int main(void)
{
    // Get user input of repository, and files name.
    char repo[64];
    char files[64];

    printf("Enter your repository: ");
    scanf("%63s[^\n]", repo);

    printf("Enter the name of the text file with your files: ");
    scanf("%63s[^\n]", files);


    // Start installation.

    InstallPath *ip = init_install(repo, files); // CREATE InstallPath STRUCT

    if (!ip)
        return 1; // CHECK IF ANY ERRORS OCCURRED

    //install_files(ip, "folder name"); // Install into folder.
    install_files(ip, NULL); // Install into current working directory.

    finish_install(ip);

    return 0;
}
```
