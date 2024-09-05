#include <iostream>
#include "static/hello.h"
#include "subdir1.h"
#include "subdir2.h"
#include "subdir3.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Hello Third Party Include!" << std::endl;

    // use a shared ptr
    boost::shared_ptr<int> isp(new int(4));

    // trivial use of boost filesystem
    boost::filesystem::path path = "/usr/share/cmake/modules";
    if (path.is_relative())
    {
        std::cout << "Path is relative" << std::endl;
    }
    else
    {
        std::cout << "Path is not relative" << std::endl;
    }

    subdir1::greetsubdir();
    subdir2::greetsubdir();
    subdir3::greetsubdir();

    return 0;
}