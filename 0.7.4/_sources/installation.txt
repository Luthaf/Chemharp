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
also compiled sucessfully with Intel C++ compilers. Please report any sucessfull
compilation with other compilers!

Some optional functionalities of chemfiles needs aditional library:

* The `NetCDF`_ library is needed to read and write the AMBER NetCDF format.
  It is available in all the package managers.

Finally, chemfiles needs uses the `CMake`_ build system, which is available in
all the package managers.

On UNIX-like systems (Linux, OS X, ...)
"""""""""""""""""""""""""""""""""""""""

All these dependencies can be installed in one command:

.. code-block:: bash

    # On apt-get based distributions
    apt-get update
    apt-get install cmake libnetcdf-dev

    # On yum based distribution (CentOS/RHEL)
    yum install epel-release # The EPEL repository contains the netcdf lib
    yum install cmake netcdf-devel

    # On dnf based distribution (Fedora)
    dnf install cmake netcdf-devel

    # On OS X with Homebrew
    brew tap homebrew/science
    brew install cmake netcdf

.. _NetCDF: https://www.unidata.ucar.edu/software/netcdf/
.. _CMake: https://cmake.org/

On Windows
""""""""""

You can use either MSVC 2015 compiler, or `mingw-w64`_ provided gcc. `MSYS2`_
offer a package manager to install all the needed libraries. I recomend using it
if you have no preference over your compiler. After the initial installation
steps, you can run the following to install a recent C++ compiler:

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

For instance, to install to :file:`$HOME/local`, use:

.. code-block:: bash

    cmake -DCMAKE_INSTALL_PREFIX=$HOME/local ..

.. _doxygen: http://doxygen.org/
.. _sphinx: http://sphinx-doc.org/
