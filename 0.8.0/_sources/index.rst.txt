Chemfiles, a modern library for chemistry file reading and writing
==================================================================

Chemfiles is a multi-language library written in modern C++ for reading and
writing from and to molecular trajectory files. These files are created by your
favorite theoretical chemistry program, and contains informations about atomic
or residues names and positions. Some format also have additional informations,
such as velocities, forces, energy, …

The main targeted audience of chemfiles are chemistry researchers working on
their own code to do some kind of awesome science, and who do not want to bother
about handling all the files format that may exist in the world.

Running simulation (either Quantum Dynamic, Monte Carlo, Molecular Dynamic, or
any other method) often produce enormous amounts of data, which had to be
post-processed in order to extract informations. This post-processing step
involve reading and parsing the data, and computing physical values with the
help of statistical thermodynamic. Chemfiles tries to help you on the first
point, by providing the same interface to all the trajectory formats. If you
ever need to change your output format, your analysis tools will still work the
same way. Chemfiles is efficient because it allow you to write and debug your
code only once, and then to re-use it as needed.

Even if chemfiles is written in C++, it can be used from the most popular
scientific programming languages: C, Fortran, Python, … You can just pick up
your favorite language to use it. This part of the documentation presents the
data model used by chemfiles to store information about the trajectories, and
how to acess that data in C and C++. The documentation for the other languages
interfaces to chemfiles are accessibles at the following places:

* `Python interface`_, usable with Python 2 and 3;
* `Fortran interface`_, for Fortran 2003;
* `Julia interface`_, for `Julia`_ 0.4+;
* `Rust interface`_, for the `Rust`_ language;

.. note::

    Chemfiles follow `semantic versionning <http://semver.org/>`_. This means
    that all 0.x.y versions are compatible for all y, but 0.x and 0.(x+1) are
    not compatible. This also means that when chemfiles reaches 1.0.0, all code
    using 1.0.0 will be compatible with 1.x.y for any x and y.

.. _Python interface: https://chemfiles.github.io/chemfiles.py/latest/
.. _Fortran interface: https://chemfiles.github.io/chemfiles.f03/latest/
.. _Julia interface: https://chemfiles.github.io/Chemfiles.jl/latest/
.. _Rust interface: https://chemfiles.github.io/chemfiles.rs/latest/
.. _Julia: http://julialang.org/
.. _Rust: https://www.rust-lang.org/

User manual
-----------

This section of the documentation will cover how to install chemfiles, give an
high-level overview of the functionalities and the supported formats. In order
to use chemfiles in your code, you should refer to the :ref:`classes-reference`.
If you need help installing or using chemfiles, do not hesitate to ask questions
in our `Gitter chat room <https://gitter.im/chemfiles/chemfiles>`_.

.. toctree::
    :maxdepth: 2

    installation
    overview
    cxx-tutorials
    c-tutorials
    formats
    selections
    configuration
    properties
    others

.. _classes-reference:

Classes and functions reference
-------------------------------

All the public classes (for the C++ interface) and functions (for the C
interface) are extensively documented here.

.. toctree::
   :maxdepth: 2

   classes/index
   capi/index

Developer documentation
-----------------------

.. toctree::
   :maxdepth: 2

   devdoc/contributing
   devdoc/internals
   devdoc/file
   devdoc/format
