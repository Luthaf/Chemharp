.. _cxx-tutorials:

C++ Tutorials
=============

This section present some hand-on tutorials to the chemfiles C++ API. All the
code here is under the `CC-0 Universal Licence`_ which means that you are free
to do whatever you want with it (*i.e.* it is Public Domain code)

.. _CC-0 Universal Licence: https://creativecommons.org/publicdomain/zero/1.0/

Read a single frame
-------------------

In this tutorials we will read a frame from a trajectory, and print the indexes
of all the atom in the half-space ``x < 5``.

We start by including the headers we need: chemfiles header, iostream for
printing and vector for storing the indexes. All the public classes of chemfiles
are accessible through the ``chemfiles.hpp`` header, which is the only header
needed.

.. literalinclude:: ../../examples/cpp/indexes.cpp
   :language: cpp
   :lines: 4-6

Then we open a Trajectory and read the first frame:

.. literalinclude:: ../../examples/cpp/indexes.cpp
   :language: cpp
   :lines: 9-10
   :dedent: 4

We can now create a vector to store the indices of the atoms with ``x < 5``, and
get the positions of the atoms in the frame with the
:cpp:func:`chemfiles::Frame::positions` function

.. literalinclude:: ../../examples/cpp/indexes.cpp
   :language: cpp
   :lines: 12-13
   :dedent: 4

Iterating through the atoms in the frame, we get the ones matching our
condition. :cpp:func:`Frame::size` gives the number of atoms in the frame, which
is also the size of the ``positions`` array. This array contains
:cpp:class:`chemfiles::Vector3D` representing the positions of the atoms in
Angstroms.

.. literalinclude:: ../../examples/cpp/indexes.cpp
   :language: cpp
   :lines: 15-19
   :dedent: 4

And finally we can print our results

.. literalinclude:: ../../examples/cpp/indexes.cpp
   :language: cpp
   :lines: 21-24
   :dedent: 4

.. htmlhidden::
    :toggle: Click here to see the whole program
    :before-not-html: The whole code looks like this

    .. literalinclude:: ../../examples/cpp/indexes.cpp
       :language: cpp
       :lines: 4-

For more information about reading frame in a trajectory, see the following
functions:

- :cpp:func:`Trajectory::nsteps` and :cpp:func:`Trajectory::done` to know when
  to stop reading
- :cpp:func:`Trajectory::read_step` to directlty read a given step.
- :cpp:func:`Trajectory::set_cell` and :cpp:func:`Trajectory::set_topology` to
  specify an unit cell or a topology for all frames in a trajectory.

Generating a structure
----------------------

Now that we know how to read frames from a trajectory, let's try to create a new
structure and write it to a file. As previsouly, we start by including the
chemfiles header:

.. literalinclude:: ../../examples/cpp/generate.cpp
   :language: cpp
   :lines: 4-5

Everything starts in a :cpp:class:`chemfiles::Topology`. This is the class that
defines the atoms and the connectivity in a system. Here, we add three
:cpp:class:`chemfiles::Atom` and two bonds to create a water molecule.

.. literalinclude:: ../../examples/cpp/generate.cpp
   :language: cpp
   :lines: 7-13
   :dedent: 4

We can then create a :cpp:class:`chemfiles::Frame` corresponding to this
:cpp:class:`chemfiles::Topology` and set the atomic positions.

.. literalinclude:: ../../examples/cpp/generate.cpp
   :language: cpp
   :lines: 15-20
   :dedent: 4

Another possibility is to directly add atoms to the frame. Here we define a
second molecule representing carbon dioxyde.
:cpp:func:`chemfiles::Frame::add_atom` takes two arguments: the atom, and the
position of the atom as a :cpp:class:`chemfiles::Vector3D`.

.. literalinclude:: ../../examples/cpp/generate.cpp
   :language: cpp
   :lines: 22-26
   :dedent: 4

Finally, we can set the :cpp:class:`chemfiles::UnitCell` associated with this
frame.

.. literalinclude:: ../../examples/cpp/generate.cpp
   :language: cpp
   :lines: 28
   :dedent: 4

Now that our frame is constructed, it is time to write it to a file. For that,
we open a trajectory in write (``'w'``) mode, and write to it.

.. literalinclude:: ../../examples/cpp/generate.cpp
   :language: cpp
   :lines: 30-31
   :dedent: 4

.. htmlhidden::
    :toggle: Click here to see the whole program
    :before-not-html: Wrapping everything up, the whole code looks like this:

    .. literalinclude:: ../../examples/cpp/generate.cpp
       :language: cpp
       :lines: 4-

Using selections
----------------

Now that we know how to read and write frame from trajectories, how about we do
a bit a filtering? In this tutorial, we will read all the frames from a file,
and use :ref:`selections <selection-language>` to filter which atoms we will
write back to another file. This example will also show how chemfiles can be
used to convert from a file format to another one.

We start by opening the two trajectories we will need

.. literalinclude:: ../../examples/cpp/select.cpp
   :language: cpp
   :lines: 8-9
   :dedent: 4

And we create a :cpp:class:`chemfiles::Selection` object to filter the atoms we
want to keep.

.. literalinclude:: ../../examples/cpp/select.cpp
   :language: cpp
   :lines: 11
   :dedent: 4

Then we can iterate over all the frames in the trajectory

.. literalinclude:: ../../examples/cpp/select.cpp
   :language: cpp
   :lines: 13-14
   :dedent: 4

And use the selection to get the list of atoms to remove. The result of
:cpp:func:`Selection::list` is a ``std::vector<size_t>`` containing the atoms
matching the selection.

.. literalinclude:: ../../examples/cpp/select.cpp
   :language: cpp
   :lines: 15
   :dedent: 8

In order to remove the atoms from the frame, we need to sort the ``to_remove``
vector in descending order: removing the atom at index i will shift the index of
all the atoms after i. So we start from the end and work toward the start of the
frame.

.. literalinclude:: ../../examples/cpp/select.cpp
   :language: cpp
   :lines: 16-19
   :dedent: 8

Finally, we can write the cleaned frame to the output file, and start the next
iteration.

.. literalinclude:: ../../examples/cpp/select.cpp
   :language: cpp
   :lines: 20
   :dedent: 8

.. htmlhidden::
    :toggle: Click here to see the whole program
    :before-not-html: The whole program look like this:

    .. literalinclude:: ../../examples/cpp/select.cpp
       :language: cpp
       :lines: 4-
