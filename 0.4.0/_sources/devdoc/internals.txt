Chemfiles internals
===================

Sources organisation
--------------------

You may find the following directory in the chemfiles sources :

- ``bin``: the sources of the binary frontend to chemfiles;
- ``cmake``: some CMake modules used for build configuration;
- ``doc``: this documentation;
- ``examples``: usage examples;
- ``include``: the headers of chemfiles;
- ``scripts``: some python scripts used for developpement.
- ``src``: the sources of the library;
- ``tests``: the sources of the unit tests;

Classes organisation
--------------------

Chemfiles is written in C++11, in an object-oriented fashion. In addition to the
:ref:`5 public classes <classes-reference>`, other classes are used. A ``Trajectory``
is built on the top of two other classes: a :ref:`File <file-class>` and  a
:ref:`Format <format-class>`. The ``File`` classes provides IO operation, and the
``Format`` classes do all the work for reading/writing information from the ``File``.
For more informations, read the following:

.. toctree::
   :maxdepth: 2

   file
   format

All the File to Format associations are managed by the TrajectoryFactory class.

.. doxygenclass:: chemfiles::TrajectoryFactory
    :members:
