Usage examples
==============

All the code here is under the `CC-0 Universal Licence <http://creativecommons.org/publicdomain/zero/1.0/>`_
which means that you are free to do whatever you want with it (*i.e.* it is Public
Domain code)

This page contains the following examples, written in all the languages
supported by chemfiles:

* The ``indexes`` program read the first frame of a trajectory and fill a
  vector called ``indexes`` with the indexes of all the atom obeying the
  :math:`x < 5` relation.
* The ``rmsd`` program read all the frames from a trajectory, and compute the
  root mean square displacement of the 10th atom in the frame.
* The ``convert`` program read all the frames from a trajectory, set the unit
  cell and the topology of the frame, and then write it back to another file.
  The input file contain here the trajectory of a single water molecule, but
  without any topological or cell information. So the program add these
  informations to a new trajectory file.

Usage from C++
^^^^^^^^^^^^^^

Read a single frame (indexes.cpp)
---------------------------------

.. literalinclude:: ../examples/cpp/indexes.cpp
   :language: cpp
   :lines: 4-

Read Multiple frames (rmsd.cpp)
-------------------------------

.. literalinclude:: ../examples/cpp/rmsd.cpp
   :language: cpp
   :lines: 4-

Write frames (convert.cpp)
--------------------------

.. literalinclude:: ../examples/cpp/convert.cpp
   :language: cpp
   :lines: 4-

Usage from C
^^^^^^^^^^^^

Read a single frame (indexes.c)
-------------------------------

.. literalinclude:: ../examples/c/indexes.c
   :language: c
   :lines: 4-

Read Multiple frames (rmsd.c)
-----------------------------

.. literalinclude:: ../examples/c/rmsd.c
   :language: c
   :lines: 4-

Write frames (convert.c)
------------------------

.. literalinclude:: ../examples/c/convert.c
   :language: c
   :lines: 4-
