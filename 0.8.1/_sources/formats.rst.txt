Supported formats
=================

List of supported formats
-------------------------

This page list the supported formats in chemfiles, with a link to the format
specification. For eavch format, it is also indicated wether they have some
information to create a *Topology*, and if you can read them, write them or both
using chemfiles.

The *Extension* column gives the extension used when trying to detect the format.
If your file does not have this extension, you can also use the string in the
*Format* column as a parameter to the ``Trajectory`` constructor to manually
specify which format to use.

+-------------------+------------+-------------------+---------+---------+
|  Format           | Extension  | Topology ?        | Read ?  | Write ? |
+===================+============+===================+=========+=========+
| `XYZ`_            | .xyz       | |yes| Atom names  | |yes|   | |yes|   |
+-------------------+------------+-------------------+---------+---------+
| `PDB`_            | .pdb       | |yes|             | |yes|   | |yes|   |
+-------------------+------------+-------------------+---------+---------+
| `Amber NetCDF`_   | .nc        | |no|              | |yes|   | |yes|   |
+-------------------+------------+-------------------+---------+---------+
| `TNG`_            | .tng       | |yes|             | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| LAMMPS Data       |            | |yes|             | |yes|   | |yes|   |
+-------------------+------------+-------------------+---------+---------+
| Tinker            | .arc       | |yes|             | |yes|   | |yes|   |
+-------------------+------------+-------------------+---------+---------+
| LAMMPS            | .lammpstrj | |no|              | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| `GRO`_            | .gro       | |yes| Atom names  | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| `XTC`_            | .xtc       | |no|              | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| `TRJ`_            | .trj       | |no|              | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| `TRR`_            | .trr       | |no|              | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| `DCD`_            | .dcd       | |no|              | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| `MOL2`_           | .mol2      | |yes|             | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+
| `Molden`_         | .molen     | |yes| Atom names  | |yes|   | |no|    |
+-------------------+------------+-------------------+---------+---------+

"LAMMPS" format correspond to trajectory files written by the LAMMPS
`dump <http://lammps.sandia.gov/doc/dump.html>`_ command. "LAMMPS Data"
correspond to LAMMPS data files, as read by the LAMMPS
`read_data <http://lammps.sandia.gov/doc/read_data.html>`_ command.

.. _XYZ: https://openbabel.org/wiki/XYZ
.. _PDB: http://www.rcsb.org/pdb/static.do?p=file_formats/pdb/index.html
.. _Amber NetCDF: http://ambermd.org/netcdf/nctraj.xhtml
.. _TNG: http://doi.wiley.com/10.1002/jcc.23495

.. _GRO: http://manual.gromacs.org/current/online/gro.html
.. _XTC: http://manual.gromacs.org/current/online/xtc.html
.. _TRJ: http://manual.gromacs.org/current/online/trj.html
.. _TRR: http://manual.gromacs.org/current/online/trr.html
.. _DCD: http://www.ks.uiuc.edu/Research/vmd/plugins/molfile/dcdplugin.html
.. _MOL2: http://chemyang.ccnu.edu.cn/ccb/server/AIMMS/mol2.pdf
.. _Molden: http://www.cmbi.ru.nl/molden/molden_format.html

.. |yes| image:: static/img/yes.png
          :alt: Yes
          :width: 16px
          :height: 16px

.. |no| image:: static/img/no.png
          :alt: No
          :width: 16px
          :height: 16px

Asking for a new format
-----------------------

If you want to use chemfiles with a format which is not yet implemented, you may
easily add it by yourself if you know some C++. See the ``src/formats/XYZ.cpp``
file for example. The list of planned formats can be found `here
<gh-new-format_>`_. If you can not find your favorite format in this list, you
can `open an issue <gh-new-issue_>`_ with a description of the format, or even
better a link to the format specification. If your format is in the `list of
formats <vmd-formats_>`_ supported by VMD, then you are lucky! It will be easy
to add support for this format. Please `open an issue <gh-new-issue_>`_ on and
provide a file example to test the plugin against it.

.. _gh-new-format: https://github.com/chemfiles/chemfiles/labels/A-formats
.. _gh-new-issue: https://github.com/chemfiles/chemfiles/issues/new
.. _vmd-formats: http://www.ks.uiuc.edu/Research/vmd/plugins/molfile/
