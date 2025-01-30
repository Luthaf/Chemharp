Installation
============

Pre-compiled binaries
^^^^^^^^^^^^^^^^^^^^^

We provide compiled packages of the latest release for muliple Linux
distributions using the `OpenSUSE build service`_.

.. raw:: html
    <p>You can download them directly below:</p>

    <iframe
        src="https://software.opensuse.org/download/package.iframe?project=home%3ALuthaf&package=chemfiles"
        width="100%" height="400px" frameborder="0"
    ></iframe>

We also provide three `conda`_ packages in the `conda-forge` community channel for
Linux and Os X.

- `chemfiles <https://github.com/conda-forge/chemfiles-feedstock>`_ package
  contains both the C++ and Python libraries. This is the one you want most of
  the time.
- `chemfiles-lib <https://github.com/conda-forge/chemfiles-lib-feedstock>`_
  package contains the C++ library alone;
- `chemfiles-python <https://github.com/conda-forge/chemfiles-feedstock>`_
  package contains the Python binding to Chemfiles alone.

.. code-block:: bash

    # Get all the packages
    conda install -c conda-forge chemfiles

    # Get the C++ and C library
    conda install -c conda-forge chemfiles-lib

.. _conda: https://conda.pydata.org/docs/
.. _OpenSUSE build service: https://software.opensuse.org/download.html?project=home%3ALuthaf&package=chemfiles

Building from sources
^^^^^^^^^^^^^^^^^^^^^

Provided you have all the required depenencies, you can also build chemfiles
from sources.

Core library dependencies
-------------------------

In order to build the core library, you will need a C++11 capable compiler.
Chemfiles is automatically tested agaist GCC (>= 4.8) on Linux, OSX and Windows
(mingw-w64); clang (>= 3.3) on Linux and OS X and MSCV 14 on Windows. It was
also compiled sucessfuly with Intel C++ compilers. Please report any sucessful
compilation with other compilers! Chemfiles also uses the `CMake`_ build system,
which is available in all the package managers.

On UNIX-like systems (Linux, OS X, ...)
"""""""""""""""""""""""""""""""""""""""

All these dependencies can be installed in one command:

.. code-block:: bash

    # On apt-get based distributions
    apt-get update
    apt-get install build-essential cmake

    # On yum based distribution (CentOS/RHEL)
    yum install gcc gcc-c++ make cmake

    # On dnf based distribution (Fedora)
    dnf install @development-tools cmake

    # On OS X with Homebrew
    brew install cmake

.. _CMake: https://cmake.org/

On Windows
""""""""""

You can use either MSVC 2015 compiler, or gcc as provided by `mingw-w64`_.
`MSYS2`_ offer a package manager to install all the needed libraries. After the
initial installation steps, you can run the following to install a recent C++
compiler:

.. code-block:: bash

    # On 64-bits windows
    pacman -S mingw64/mingw-w64-x86_64-gcc

    # On 32-bits windows
    pacman -S mingw32/mingw-w64-i686-gcc

You will also need to install cmake, which can be found `here <https://www.cmake.org/download/>`_.

.. _mingw-w64: https://mingw-w64.org/doku.php
.. _MSYS2: https://msys2.github.io/

Build steps
-----------

You can get the source code from either git, or from the `release`_ page of
Github. In the later case, just unpack the archive wherever you want the source
code to live. To get the latest developpement version, use git:

.. code-block:: bash

    cd where/you/whant/chemfiles/to/live
    git clone https://github.com/chemfiles/chemfiles
    cd chemfiles

.. _release: https://github.com/Luthaf/chemfiles/releases

The following command build and install chemfiles

.. code-block:: bash

    cd chemfiles
    mkdir build
    cd build
    cmake .. # various options are allowed here
    cmake --build .
    # if you whant to run the tests before installing:
    ctest
    cmake --build . --target install

The :command:`cmake` step can be further configured by using the curse-based GUI
(:command:`ccmake .`) or providing some command-line arguments. Here are the
most important options:

+---------------------------------------+---------------------+------------------------------+
| Option                                | Default value       | Effect/Informations          |
+=======================================+=====================+==============================+
| ``-DCMAKE_INSTALL_PREFIX=prefix``     | :file:`/usr/local`  | Set the installation prefix  |
|                                       |                     | to ``prefix``                |
+---------------------------------------+---------------------+------------------------------+
| ``-DCMAKE_BUILD_TYPE=type``           | ``release``         | Set to ``debug`` for debug   |
|                                       |                     | informations                 |
+---------------------------------------+---------------------+------------------------------+
| ``-DBUILD_SHARED_LIBS=ON|OFF``        | ``OFF``             | Build shared library instead |
|                                       |                     | of static one.               |
+---------------------------------------+---------------------+------------------------------+
| ``-DCHFL_BUILD_DOCUMENTATION=ON|OFF`` | ``OFF``             | Build the documentation.     |
|                                       |                     | This needs `sphinx`_ and     |
|                                       |                     | `doxygen`_ to be installed   |
+---------------------------------------+---------------------+------------------------------+
| ``-DCHFL_BUILD_TESTS=ON|OFF``         | ``OFF``             | Build the test suite.        |
+---------------------------------------+---------------------+------------------------------+
| ``-DCHFL_SYSTEM_NETCDF=ON|OFF``       | ``OFF``             | Use the system-provided      |
|                                       |                     | netcdf library.              |
+---------------------------------------+---------------------+------------------------------+
| ``-DCHFL_SYSTEM_LZMA=ON|OFF``         | ``OFF``             | Use the system-provided      |
|                                       |                     | lzma library.                |
+---------------------------------------+---------------------+------------------------------+
| ``-DCHFL_SYSTEM_ZLIB=ON|OFF``         | ``OFF``             | Use the system-provided zlib |
+---------------------------------------+---------------------+------------------------------+

For instance, to install chemfiles to :file:`$HOME/local`, you should use:

.. code-block:: bash

    cmake -DCMAKE_INSTALL_PREFIX=$HOME/local ..

.. _doxygen: http://doxygen.org/
.. _sphinx: http://sphinx-doc.org/


Using chemfiles in your project
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are multiple ways to use chemfiles in your own code:

- adding the include path and library manually (in a Makefile, or a Visial Studio project);
- using the CMake configuration file;
- including chemfiles inside a CMake based-project.

Manually setting include and library path
-----------------------------------------

After installing chemfiles on your computer, you can start using it with your
own C or C++ program by passing the corresponding include path and library path
to your compiler. For example, on \*nix (GNU/Linux or OS X) you can compile any
code depending on chemfiles with the following command

.. code-block:: bash

    # change <PREFIX> to the location where you installed chemfiles
    # (default is /usr/local)
    g++ my-code.cpp -o my-code -I<PREFIX>/include -lchemfiles -L<PREFIX>/lib

Here, ``-I <PREFIX>/include`` tells the compiler where to look for chemfiles
headers, ``-lchemfiles`` tells it to link the chemfiles library in the final
executable, and ``-L <PREFIX>/lib`` tells the compiler where to look for the
chemfiles library.

The same strategy should be possible to use with Visual Studio on Windows, or
any other IDE. Refer to your IDE documentation about how to add external
libraries.

Using cmake and ``find_package``
--------------------------------

If your project is already using CMake, and you installed chemfiles on your
computer, you can use the standard ``find_package`` to find the code and
automatically set the right include and library path.

.. code-block:: cmake

    add_executable(my-code my-code.cpp)

    find_package(chemfiles 0.8)
    # chemfiles_FOUND will be TRUE if the code was found

    target_link_library(my-code chemfiles)

Including chemfiles as a CMake subproject
-----------------------------------------

If your project is already using CMake, but you don't want to require your users
to install chemfiles separatedly, you can use cmake support for external
projects or subdirectories to include chemfiles sources directly inside your own
project. All CMake variables controling chemfiles behaviour are prefixed with
``CHFL_`` to prevent variable pollution.
