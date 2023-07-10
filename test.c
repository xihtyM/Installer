#include "install.h"
#include <stdio.h>

int main(void)
{
    InstallPath *ip = init_install("xihtyM/Pang/main", NULL);

    if (!ip)
        exit(1);
    
    install_files(ip, "test");

    finish_install(ip);

    return 0;
}
