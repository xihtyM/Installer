#include <urlmon.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define RAW "https://raw.githubusercontent.com/"
#define RAWLEN 34


/// @brief Downloads data from a url into the file.
/// @param url url to download data from.
/// @param file path of file to be downloaded (including the filename) - directory must be valid.
/// @return Nonzero on failure.
int16_t _download(
    const char *url,
    const char *file);


/// @brief Gets the line at the given index.
/// @param str the string that is split.
/// @param line the line number.
/// @return The substring of the nth line. Empty string on failure or end of file.
char *getline(
    char *str,
    uint32_t line);


typedef struct InstallPath
{
    char *url;
    const char *files;
} InstallPath;


/// @brief Initializes the InstallPath struct.
/// @param url in the syntax "github username/repo/branch" (for example "xihtyM/Pang/main").
/// @param files the name of the text file inside the repo containing every file to be downloaded (seperated by newlines).
/// @return Pointer to InstallPath struct - NULL on failure.
InstallPath *init_install(
    char *url,
    const char *files);


/// @brief Reads repo/ip->files.
/// @param ip pointer to InstallPath struct.
/// @return Contents of repo/ip->files - NULL on failure
char *read_files_dat(
    InstallPath *ip);


/// @brief Installs all files in ip->url/ip->files file onto computer. (files must be seperated by newline).
/// @param ip pointer to InstallPath struct.
/// @param path the path of installation - NULL indicates the current working directory.
/// @return Nonzero on failure.
/// @warning The path must be a valid path, otherwise the files will not be downloaded.
int16_t install_files(
    InstallPath *ip,
    const char *path);


/// @brief Frees InstallPath struct and sets it to NULL.
/// @param ip pointer to InstallPath struct.
void finish_install(
    InstallPath *ip);
