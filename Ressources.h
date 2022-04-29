//
// Created by ldeir on 28-04-2022.
//

#ifndef YUKON_RESSOURCES_H
#define YUKON_RESSOURCES_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

const char* getWorkingDirectory() {
    static char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return cwd;
    } else {
        perror("getcwd() error");
        return "";
    }
}

SDL_Texture* loadTexture(const char* path) {
    return IMG_LoadTexture(gRenderer, path); // TODO: Use relative path
}

#endif //YUKON_RESSOURCES_H
