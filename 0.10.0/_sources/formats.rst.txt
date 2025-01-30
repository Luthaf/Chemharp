Supported formats
=================

List of supported formats
-------------------------

This page list the supported formats in chemfiles, with a link to the format
specification. For each format, it is also indicated which kind of data can be
read or written with |yes| for 'yes' and |no| for 'no'. Even if chemfiles can
read some type of data from a file, this does not mean that all files of this
format will contain this type of data.

The *Extension* column gives the extension used when trying to detect the
format. If your file does not have this extension, you can also use the string
in the *Format* column as a parameter to the :cpp:class:`chemfiles::Trajectory`
constructor to manually specify which format to use.

.. role:: red

.. |yes| replace:: `✓`
.. |no| replace:: :red:`✗`

.. csv-table::
   :file: formats-overview.csv
   :header-rows: 1
   :class: formats-table
   :widths: 20, 11, 6, 6, 6, 7, 7, 7, 9, 9, 9


- **LAMMPS** format corresponds to trajectory files written by the LAMMPS `dump
  <https://lammps.sandia.gov/doc/dump.html>`_ command.
- **LAMMPS Data** format corresponds to LAMMPS data files, as read by the LAMMPS
  `read_data <https://lammps.sandia.gov/doc/read_data.html>`_ command.

.. note:: in-memory IO

    Additionally, some formats support reading and writing directly to memory,
    without going through a file. At this time, all text based files (excluding
    those backed by the Molfiles plugin) support both reading and writing directly
    to memory. The MMTF format supports reading from a memory buffer, but does not
    support writing. It is also possible to read a compressed GZ or XZ file directly
    to memory buffer, but writing compressed files is not supported.

Asking for a new format
-----------------------

If you want to use chemfiles with a format which is not yet implemented, you may
easily add it by yourself if you know some C++. See the ``src/formats/XYZ.cpp``
file for example. The list of planned formats can be found `here
<gh-new-format_>`_. If you can not find your favorite format in this list, you
can `open an issue <gh-new-issue_>`_ with a description of the format, or even
better a link to the format specification.

.. _gh-new-format: https://github.com/chemfiles/chemfiles/labels/A-formats
.. _gh-new-issue: https://github.com/chemfiles/chemfiles/issues/new
.. _vmd-formats: http://www.ks.uiuc.edu/Research/vmd/plugins/molfile/
