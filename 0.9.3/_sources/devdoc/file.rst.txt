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
    :protected-members:

.. doxygenclass:: chemfiles::TextFile
    :members:
    :protected-members:

Implemented classes
-------------------

These classes implement the ``File`` interface defined previously.

.. doxygenclass:: chemfiles::PlainFile
    :members:

.. doxygenclass:: chemfiles::GzFile
    :members:

.. doxygenclass:: chemfiles::XzFile
    :members:

.. doxygenclass:: chemfiles::NcFile
    :members:

.. doxygenclass:: chemfiles::TNGFile
    :members:
