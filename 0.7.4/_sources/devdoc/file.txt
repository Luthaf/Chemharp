.. _class-File:

``File`` classes
================

The ``File`` classes provide abstraction of the IO operation, allowing for the
same format to be used with on-disk files, network files, memory-mapped files,
compressed files, *etc.*

Interface for files
-------------------

.. doxygenclass:: chemfiles::File
    :members:

.. doxygenclass:: chemfiles::TextFile
    :members:

Implemented classes
-------------------

These classes implement the ``File`` interface defined previously.

.. doxygenclass:: chemfiles::BasicFile

.. doxygenclass:: chemfiles::NcFile

.. doxygenclass:: chemfiles::TNGFile
