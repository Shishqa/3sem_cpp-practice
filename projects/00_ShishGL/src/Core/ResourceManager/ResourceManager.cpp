/*============================================================================*/
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ResourceManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ResourceManager::ResourceMap& ResourceManager::Resources() {
    static ResourceMap MAP;
    return MAP;
}

/*----------------------------------------------------------------------------*/

void ResourceManager::load(const std::string_view& filename) {

    if (Resources().count(filename)) {
        return;
    }

    printf("RESOURCE LOADING!!!!\n");

    struct stat fstat = {};
    if (-1 == lstat(filename.data(), &fstat)) {
        perror("lstat");
        exit(1);
    }

    int fd = open(filename.data(), O_RDWR);

    auto* data = reinterpret_cast<uint8_t*>(
            mmap(NULL, static_cast<size_t>(fstat.st_size),
                 PROT_READ | PROT_WRITE,
                 MAP_SHARED, fd, 0)
                 );

    Resources()[filename] = Resource{filename, static_cast<size_t>(fstat.st_size), data};
}

/*----------------------------------------------------------------------------*/

const ResourceManager::Resource&
ResourceManager::get(const std::string_view& filename) {

    if (!Resources().count(filename)) {
        load(filename);
    }

    return Resources()[filename];
}

/*----------------------------------------------------------------------------*/

void ResourceManager::forget(const std::string_view&) {


}

/*============================================================================*/