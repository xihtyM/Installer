#include "install.h"

int main(void)
{
    char repo[64];
    char files[64];

    printf("Enter your repository: ");
    scanf("%63s[^\n]", repo);

    printf("Enter the name of the text file with your files: ");
    scanf("%63s[^\n]", files);

    InstallPath *ip = init_install(repo, files); // CREATE InstallPath STRUCT

    if (!ip)
        return 1; // CHECK IF ANY ERRORS OCCURRED

    //install_files(ip, "folder name"); // Install into folder.
    install_files(ip, NULL); // Install into current working directory.

    finish_install(ip);

    return 0;
}
