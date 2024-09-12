# tools-examples

- [tools-examples](#tools-examples)
  - [About the project](#about-the-project)
  - [Project Structure](#project-structure)
  - [Getting Started](#getting-started)
    - [Tools needed](#tools-needed)
    - [Project Installation](#project-installation)
  - [Usage](#usage)
      - [cmake\_example](#cmake_example)
      - [boost unit testing example](#boost-unit-testing-example)
      - [googletest unit testing examples](#googletest-unit-testing-examples)
      - [github actions examples](#github-actions-examples)
      - [README template](#readme-template)
      - [cmake template](#cmake-template)
      - [dllist with simple template](#dllist-with-simple-template)
      - [ModernCppStarter](#moderncppstarter)
      - [dllist with modern cpp template](#dllist-with-modern-cpp-template)
  - [Roadmap](#roadmap)
  - [Contributing](#contributing)
  - [Contact](#contact)
  - [LICENSE](#license)
  - [Other Links](#other-links)

## About the project

This is a project that provides some examples on the usage of some C++ project development tools with `CMake`, and ends with a C++ project template.

The development of this project is incremental. First we build a simple C++ project, with files in clear project strucuture, and we gradully add more tool configurations to it.

During the process, you may learn about the usage of some important tools. All these tools configurations are combined with `CMake`.

## Project Structure

Tools examples in this project include:

- `CMake` building tools
  - basic `CMake` project configuration
  - `CMake` project with subprojects
- static analysis tools with `CMake`
  - `clang-format`
  - `cppcheck`
- unit testing framework with `CMake`
  - `Boost` unit testing framework
  - `googletest` unit testing framework
- documentation with `CMake`
  - `CMake` with `doxygen`
- packing and installation in `CMake`
- `README.md` template
- `CI/CD` tools configuration with `CMake`
  - `github actions`

## Getting Started

### Tools needed

- `Mingw-w64` or `Mingw`
- `CMake`
- `vscode`
- `clang-format`
- `cppcheck`
- `clang-tidy`
- `boost`
- `googletest`
- `CMake`
- `doxygen`

### Project Installation

```bash
git clone https://github.com/Salvely/tools-examples.git
```

For each example, there's maybe a `run.sh` in there, you may directly enter

```bash
./run.sh
```

all the commands that build the project is in there. Or you can build the example mannually.

## Usage

> [!WARNING]
>
> To run the project on your computer, replace the library path in the project with your own. Otherwise, some CMake commands may not find the library or `.clang-format`. Besides, be sure that your local environment such as Visual Studio Code text editor is set up.

We recommend that you learn from this project in the following order:

#### [cmake_example](./cmake_example/)

this is a `CMake` example project with :

- basic cpp configuration
- clear project structures, with `bin`, `build`, `cmake`, `include`, `lib`, `src` , `test` ,`subdirs` and `CMakeLists.txt`
- code analysis tools embedded with `CMake`, such as `clang-format`, `cppcheck`, `doxygen`, etc.
- subprojects with `CMake` configured
- unit testing using `boost` and `googletest`
- auto build script called `run.sh`

#### [boost unit testing example](./boost_test_example/)

> [!TIP]
>
> Change the path of `boost` to your boost library on your computer.

this is a `CMake` example with `boost` unit testing framework. `Boost` installled locally, with no `github actions` CI/CD.

#### [googletest unit testing examples](./googletest_test_example/)

> [!TIP]
>
> Change the path of `googletest` to the local library on your computer.

this is a `CMake` example with `googletest` unit testing framework. `googletest` installled locally, with no `github` actions` CI/CD.

#### [github actions examples](./github_actions_example/)

this is a `CMake` example with `github actions` to auto build the project in the `cmake_example`. Using the tool [cmake-action](https://github.com/marketplace/actions/cmake-action)

#### [README template](./README_template/)

this directory contains links to some awesome `README` template, and include a `README.md` template created by my own.

#### [cmake template](./cmake_template/)

this is a `cmake` template.

#### [dllist with simple template](./dllist/)

this is a `dllist` project using the [cmake template](./cmake_template/).

#### [ModernCppStarter](./ModernCppStarter/)

this directory links to an awesome modern cpp template.

#### [dllist with modern cpp template](./big_dllist/)

this is a `dllist` project using the [ModernCppStarter](./ModernCppStarter/).

## Roadmap

- [x] basic cmake example project with unit testing
- [x] dllist implementation
- [x] cmake example subproject configuration
- [x] static analysis add into cmake example
  - [x] `clang-tidy`
  - [x] `clang-format`
  - [x] `cpplint`
  - [x] `cppcheck`
- [x] unit testing
  - [x] add boost unit testing into cmake examples
  - [x] add googletest unit testing into cmake examples
- [x] documentation
  - [x] doxygen documentation configuration add into cmake examples
- [x] project packing and installation process add into cmake examples
- [x] boost unit testing framework examples
- [x] googletest unit testing framework examples
- [x] README.md template written
- [x] README.md finished
- [x] learn some github actions
- [x] build a cmake template from [cmake_example](./cmake_example/)
- [x] add github actions to the cmake_example
- [ ] add README.md to the cmake_example
- [ ] apply the cmake template into `dllist` project
- [ ] get familiar with the [ModernCppStarter](https://github.com/TheLartians/ModernCppStarter.git)
- [ ] configure the `dllist` project with the [ModernCppStarter template](https://github.com/TheLartians/ModernCppStarter.git)
- [ ] refine the project template
- [ ] publish the project template

## Contributing

To contribute to [tools-example](https://github.com/Salvely/tools-examples), follow these steps:

1. Fork it `https://github.com/Salvely/tools-examples`
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request

Alternatively see the GitHub documentation on [creating a pull request](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request).

## Contact

If you want to contact me you can reach me at <iamgwen9@gmail.com>.

## LICENSE

This project uses the [MIT LICENSE](./LICENSE).

## Other Links

- [ModernCppStarter](https://github.com/TheLartians/ModernCppStarter.git)
- [README-template.md](https://github.com/scottydocs/README-template.md.git)
- [README-Templates](https://github.com/Fernanda-Kipper/Readme-Templates.git)
- [readme-template](https://github.com/dbader/readme-template)
- [Best-README.Template](https://github.com/othneildrew/Best-README-Template.git)
