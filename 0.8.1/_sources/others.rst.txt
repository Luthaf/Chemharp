Other libraries for reading trajectories
========================================

If chemfiles does not provide what you are looking for, here are some other libraries
for reading and/or writing trajectories, and the main differencies with chemfiles.

VMD Molfile plugins
-------------------

`VMD <http://www.ks.uiuc.edu/Research/vmd/>`_ is a molecular visualisation program. A
set of `plugins <http://www.ks.uiuc.edu/Research/vmd/plugins/molfile/>`_ distributed
separatly provide read and write ability for around 60 differents formats.

VMD molfiles plugins are written in C, and do not provide other documentation than
the source code (which is very readable, I must say). It is pretty difficult to use
it from other languages than C or C++.

Majors differencies
^^^^^^^^^^^^^^^^^^^

* More formats than chemfiles;
* No automatic format regognition;
* Does not support a variable number of atoms;
* Not multi-language;
* Poor documentation for first start. You need to read other software to understand
  what's going on.

OpenBabel
---------

`OpenBabel <https://openbabel.org/wiki/Main_Page>`_ is the swiss army knife for
converting trajectories from one format to another. It support over 110 file format.

The library is written in C++, and provide Perl, Python, Java and Ruby bindings. It
also provide stand-alone tools for conversions and analysis of trajectories.

Majors differencies
^^^^^^^^^^^^^^^^^^^

* More formats than chemfiles;
* Provide analysis tools, SMILES matching and database searching;
* OpenBabel is distributed under the GNU Public Licence, which might make it harder
  to use by other softwares: the other software *must* be GPL softwares;
* OpenBabel is a complex tool, and provide many public classes. I could not find what
  I was looking for easily.


MDTraj
------

`MDTraj <http://mdtraj.org/latest/>`_ is a Python library for Molecular Dynamics
trajectories reading and analysis.

Majors differencies
^^^^^^^^^^^^^^^^^^^

* Provide analysis tools;
* Only usable from Python;
* Distributed under the Library GNU Public Licence, which mean that you can use the
  code in non-GPL software, but must redistribute the library under GPL.

MDAnalysis
----------

`MDAnalysis <http://www.mdanalysis.org/>`_ is a Python library for Molecular Dynamics
trajectories reading and analysis.

Majors differencies
^^^^^^^^^^^^^^^^^^^

* Provide analysis tools;
* Only usable from Python;
* MDAnalysis is distributed under the GNU Public Licence, which might make it harder
  to use by other softwares: the other software *must* be GPL softwares;
