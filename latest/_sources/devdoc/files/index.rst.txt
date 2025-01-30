.. _class-File:

``File`` classes
================

The ``File`` classes provide abstraction of the IO operation, allowing for the
same format to be used with on-disk files, network files, memory-mapped files,
compressed files, *etc.*


.. doxygenclass:: chemfiles::File
    :members:
    :protected-members:

.. doxygenclass:: chemfiles::TextFile
    :members:
    :protected-members:

.. doxygenclass:: chemfiles::BinaryFile
    :members:
    :protected-members:

.. toctree::
   :maxdepth: 1

   text-files
   binary-files
