.. _file-class:

``File`` classes
================

The ``File`` classes provide abstraction of the IO operation, allowing for the same
format to be used with on-disk files, network files, memory-mapped files,
compressed files, *etc.*

Depending on the kind of format, either a ``TextFile`` or a ``BinaryFile`` is needed,
and will provide different informations.

Abstract classes
----------------

These classes only define the interface, which as to be implemented by all sub-classes.

.. doxygenclass:: chemfiles::File
    :members:
    :protected-members:

.. doxygenclass:: chemfiles::TextFile
    :members:
    :protected-members:

.. doxygenclass:: chemfiles::BinaryFile
    :members:
    :protected-members:

Implemented classes
-------------------

These classes implement the interface defined previously.

.. doxygenclass:: chemfiles::BasicFile
    :members:

.. doxygenclass:: chemfiles::NCFile
    :members:

.. TODO:: adding a new file class
