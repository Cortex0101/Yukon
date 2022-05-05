//
// Created by ldeir on 28-04-2022.
//

#ifndef YUKON_RESSOURCES_H
#define YUKON_RESSOURCES_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

char* executable_location;
char* resources_folder;

const char* getWorkingDirectory() {
    static char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return cwd;
    } else {
        perror("getcwd() error");
        return "";
    }
}

char* getRessourcesFolder(const char* executable_loc) {
    const char* end_path = "cmake-build-debug\\Yukon.exe";
    size_t end_path_length = strlen(end_path);
    size_t full_path_length = strlen(executable_loc);
    const size_t length = full_path_length - end_path_length;
    const size_t extraPathLength = strlen("ressources\\");
    char* resourceFolder = malloc(length + 1 + extraPathLength);
    strncpy(resourceFolder, executable_loc, length);
    strcpy(&resourceFolder[length], "ressources\\");
    resourceFolder[length + extraPathLength] = '\0';
    return resourceFolder;
}

SDL_Texture* loadTexture(const char* path) {
    SDL_Texture* texture = IMG_LoadTexture(gRenderer, path); // TODO: Use relative path
    if (texture == NULL) {
        printf("Failed to load texture!");
    }
    return texture;
}

#endif //YUKON_RESSOURCES_H
