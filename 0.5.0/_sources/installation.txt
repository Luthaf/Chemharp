Installation
============

Pre-compiled binaries
^^^^^^^^^^^^^^^^^^^^^

A few precompiled binary of the latest release are provided through the `conda`_
cross-plateform package manager. These binary provide the C++, C and Python
interfaces. To install them, you can use:

.. code-block:: bash

    conda install -c https://conda.anaconda.org/luthaf chemfiles

.. _conda: http://conda.pydata.org/docs/

Building from sources
^^^^^^^^^^^^^^^^^^^^^

If you want full control over the way the code is built, you can built chemfiles from
sources.

Core library dependencies
-------------------------

In order to build the core library, you will need a C++11 compiler, like g++>4.9 or
clang++>3.3. Chemfiles is tested against GCC, Clang and Intel C++ compilers, and
is ISO C++11, so it should compile with other compilers as well. Please report
any sucessfull compilation with other compilers!

Some optional functionalities of chemfiles needs aditional library. As the
functionalities are activated when configuring the build, these additionals libraries
are optionals. Here is the list of these libraries:

* The `NetCDF`_ library is needed to read and write the AMBER NetCDF format.
  It is available in all the package managers.

Finally, chemfiles needs uses the `CMake`_ build system, which is also available
in all the package managers.

On UNIX-like systems (Linux, OS X, ...)
"""""""""""""""""""""""""""""""""""""""

All these dependencies can be installed in one command:

.. code-block:: bash

    # On apt-get based distributions
    apt-get update
    apt-get install cmake libnetcdf-dev

    # On yum based distributions
    yum install epel-release # The EPEL repository have the netcdf lib
    yum install cmake netcdf-devel netcdf-cxx-devel

    # On OS X with Homebrew
    brew tap homebrew/science
    brew install cmake netcdf

.. _NetCDF: http://www.unidata.ucar.edu/software/netcdf/
.. _CMake: http://cmake.org/

On Windows
""""""""""

You can use either MSVC 2015 compiler, or `mingw-w64`_ provided gcc. `MSYS2`_ offer a
package manager to install all the needed libraries. I recomend using it if you have
no preference over your compiler. After the initial installation steps, you can run
the following to install a recent C++ compiler:

.. code-block:: bash

    # On 64-bits windows
    pacman -S mingw64/mingw-w64-x86_64-gcc

    # On 32-bits windows
    pacman -S mingw32/mingw-w64-i686-gcc

You will also need to install cmake, which can be found `here <http://www.cmake.org/download/>`_.

.. _mingw-w64: http://mingw-w64.org/doku.php
.. _MSYS2: http://msys2.github.io/

Build steps
-----------

You can get the source code from either git, or from the `release`_ page of Github.
In the later case, just unpack the archive wherever you want the source code to live.
To get the latest developpement version, use git:

.. code-block:: bash

    cd where/you/whant/chemfiles/to/live
    git clone https://github.com/chemfiles/chemfiles
    cd chemfiles

If you want to run the unit and regression tests, you will need the tests data files,
which are provided as submodules.

.. code-block:: bash

    git submodule update --init

.. _release: https://github.com/Luthaf/chemfiles/releases

The following command can build and install chemfiles on a standard POSIX environement.

.. code-block:: bash

    cd chemfiles
    mkdir build
    cd build
    cmake .. # various options are allowed here
    make
    # if you whant to run the tests before installing:
    ctest
    make install

To use the other generator from CMake (XCode, VisualStudio, …), please refer to
the doccumentation of CMake.

The :command:`cmake` step can be further configured by using the curse-based GUI
(:command:`ccmake .`) or providing some command-line arguments. Here are the
most important options:

+------------------------------------+---------------------+------------------------------+
| Option                             | Default value       | Effect/Informations          |
+====================================+=====================+==============================+
| ``-DCMAKE_INSTALL_PREFIX=prefix``  | :file:`/usr/local`  | Set the installation prefix  |
|                                    |                     | to ``prefix``                |
|                                    |                     |                              |
+------------------------------------+---------------------+------------------------------+
| ``-DCMAKE_BUILD_TYPE=type``        | ``release``         | Set to ``debug`` for debug   |
|                                    |                     | informations                 |
+------------------------------------+---------------------+------------------------------+
| ``-DBUILD_SHARED_LIBS=ON|OFF``     | ``OFF``             | Build shared library instead |
|                                    |                     | of static one.               |
+------------------------------------+---------------------+------------------------------+
| ``-DBUILD_DOCUMENTATION=ON|OFF``   | ``OFF``             | Build the documentation.     |
|                                    |                     | This needs `sphinx`_ and     |
|                                    |                     | `doxygen`_ to be installed   |
+------------------------------------+---------------------+------------------------------+
| ``-DBUILD_TESTS=ON|OFF``           | ``OFF``             | Build the test suite.        |
+------------------------------------+---------------------+------------------------------+
| ``-DENABLE_NETCDF=ON|OFF``         | ``OFF``             | Enable the Amber NetCDF      |
|                                    |                     | format                       |
+------------------------------------+---------------------+------------------------------+

For instance, to install to :file:`$HOME/local`, use:

.. code-block:: bash

    cmake -DCMAKE_INSTALL_PREFIX=$HOME/local ..

.. _doxygen: http://doxygen.org/
.. _sphinx: http://sphinx-doc.org/
