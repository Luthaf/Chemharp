Chemfiles internals
===================

Sources organisation
--------------------

You may find the following directory in the chemfiles sources :

- ``cmake``: some CMake modules used for build configuration;
- ``doc``: this documentation;
- ``examples``: usage examples for C and C++ interfaces;
- ``external``: external libraries used by chemfiles;
- ``include``: the headers of chemfiles;
- ``scripts``: some python scripts used for developpement.
- ``src``: the sources of the library;
- ``tests``: the sources of the unit tests;

Classes organisation
--------------------

Chemfiles is written in C++11, in an object-oriented fashion. A ``Trajectory``
is built on the top of two other private classes: a :ref:`File <file-class>` and a
:ref:`Format <format-class>`. The ``File`` classes provides IO operation, and the
``Format`` classes do all the work for reading/writing information from the ``File``.

.. image:: /static/img/classes.*
    :align: center

.. toctree::
   :maxdepth: 2

   file
   format

All the File to Format associations are managed by the TrajectoryFactory class.

.. doxygenclass:: chemfiles::TrajectoryFactory
    :members:
