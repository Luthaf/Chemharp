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

+-------------------+------------+-------+-------+--------------+-------+
|  Format           | Extension  | Read  | Write | Atomic names | Bonds |
+===================+============+=======+=======+==============+=======+
| `Amber NetCDF`_   | .nc        | |yes| | |yes| | |no|         | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `CSSR`_           | .cssr      | |yes| | |yes| | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `DCD`_            | .dcd       | |yes| | |no|  | |no|         | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `GRO`_            | .gro       | |yes| | |yes| | |yes|        | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `LAMMPS Data`_    |            | |yes| | |yes| | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `LAMMPS`_         | .lammpstrj | |yes| | |no|  | |no|         | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `mmCIF`_          | .mmcif     | |yes| | |yes| | |yes|        | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `MMTF`_           | .mmtf      | |yes| | |yes| | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `MOL2`_           | .mol2      | |yes| | |yes| | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `Molden`_         | .molen     | |yes| | |no|  | |yes|        | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `PDB`_            | .pdb       | |yes| | |yes| | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `SDF`_            | .sdf       | |yes| | |yes| | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `TNG`_            | .tng       | |yes| | |no|  | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `TRJ`_            | .trj       | |yes| | |no|  | |no|         | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `TRR`_            | .trr       | |yes| | |no|  | |no|         | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `Tinker`_         | .arc       | |yes| | |yes| | |yes|        | |yes| |
+-------------------+------------+-------+-------+--------------+-------+
| `XTC`_            | .xtc       | |yes| | |no|  | |no|         | |no|  |
+-------------------+------------+-------+-------+--------------+-------+
| `XYZ`_            | .xyz       | |yes| | |yes| | |yes|        | |no|  |
+-------------------+------------+-------+-------+--------------+-------+

"LAMMPS" format correspond to trajectory files written by the LAMMPS
`dump <http://lammps.sandia.gov/doc/dump.html>`_ command. "LAMMPS Data"
correspond to LAMMPS data files, as read by the LAMMPS
`read_data <http://lammps.sandia.gov/doc/read_data.html>`_ command.

.. _Amber NetCDF: http://ambermd.org/netcdf/nctraj.xhtml
.. _CSSR: http://www.chem.cmu.edu/courses/09-560/docs/msi/modenv/D_Files.html#944777
.. _DCD: http://www.ks.uiuc.edu/Research/vmd/plugins/molfile/dcdplugin.html
.. _GRO: http://manual.gromacs.org/current/online/gro.html
.. _LAMMPS Data: http://lammps.sandia.gov/doc/read_data.html
.. _LAMMPS: https://lammps.sandia.gov/doc/dump.html
.. _mmCIF: http://mmcif.wwpdb.org/
.. _MMTF: https://mmtf.rcsb.org/
.. _MOL2: http://chemyang.ccnu.edu.cn/ccb/server/AIMMS/mol2.pdf
.. _Molden: http://www.cmbi.ru.nl/molden/molden_format.html
.. _PDB: http://www.rcsb.org/pdb/static.do?p=file_formats/pdb/index.html
.. _SDF: http://accelrys.com/products/collaborative-science/biovia-draw/ctfile-no-fee.html
.. _TNG: http://doi.wiley.com/10.1002/jcc.23495
.. _TRJ: http://manual.gromacs.org/current/online/trj.html
.. _TRR: http://manual.gromacs.org/current/online/trr.html
.. _Tinker: http://chembytes.wikidot.com/tnk-tut00#toc2
.. _XTC: http://manual.gromacs.org/current/online/xtc.html
.. _XYZ: https://openbabel.org/wiki/XYZ

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
