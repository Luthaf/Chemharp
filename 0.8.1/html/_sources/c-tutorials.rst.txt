.. _c-tutorials:

C Tutorials
===========

This section present some hand-on tutorials to the chemfiles C API. These
examples do exaclty the same thing as the :ref:`C++ ones <cxx-tutorials>`, using
the C API instead of the C++ API. As such, they are much more verbose. They also
do not correclty check for error conditions. When using the C API, you should
alway check that the return value of the functions is ``CHFL_SUCCESS``.

All the code here is under the `CC-0 Universal Licence`_ which means that you
are free to do whatever you want with it (*i.e.* it is Public Domain code)

.. _CC-0 Universal Licence: https://creativecommons.org/publicdomain/zero/1.0/

Read a single frame
-------------------

In this tutorials we will read a frame from a trajectory, and print the indexes
of all the atom in the half-space ``x < 5``.

We start by including the headers we need: chemfiles header, ```stdio.h`` for
printing and ``stdlib.h`` for ``malloc``. All the public functions of chemfiles
are accessible through the ``chemfiles.h`` header, which is the only header
needed.

.. literalinclude:: ../../examples/c/indexes.c
   :language: c
   :lines: 4-6

Then we open a :cpp:type:`CHFL_TRAJECTORY` in read (``'r'``) and read the first
frame.  We need to allocate memory for the :cpp:type:`CHFL_FRAME` before calling
:cpp:func:`chfl_trajectory_read`.

.. literalinclude:: ../../examples/c/indexes.c
   :language: c
   :lines: 9-11
   :dedent: 4

We can now and get the positions of the atoms and the number of atoms in the
frame with the :cpp:func:`chfl_frame_positions` function:

.. literalinclude:: ../../examples/c/indexes.c
   :language: c
   :lines: 13-15
   :dedent: 4

Knowning the total number of atoms in the frame, we can allocate memory to store
the indices of the atoms with ``x < 5``:

.. literalinclude:: ../../examples/c/indexes.c
   :language: c
   :lines: 17
   :dedent: 4

Iterating through the atoms in the frame, we get the ones matching our
condition. We need to track the number of ``matched`` atoms to know where to add
them in the ``less_than_five`` array.

.. literalinclude:: ../../examples/c/indexes.c
   :language: c
   :lines: 19-25
   :dedent: 4

At the end we can print our results

.. literalinclude:: ../../examples/c/indexes.c
   :language: c
   :lines: 27-30
   :dedent: 4

And free all allocated memory. We don't need to free ``positions``, as it points
into memory allocated and controlled by the frame.

.. literalinclude:: ../../examples/c/indexes.c
   :language: c
   :lines: 32-34
   :dedent: 4

.. htmlhidden::
    :toggle: Click here to see the whole program
    :before-not-html: The whole code looks like this

    .. literalinclude:: ../../examples/c/indexes.c
       :language: c
       :lines: 4-

For more information about reading frame in a trajectory, see the following
functions:

- :cpp:func:`chfl_trajectory_nsteps` to know when to stop reading
- :cpp:func:`chfl_trajectory_read_step` to directlty read a given step.
- :cpp:func:`chfl_trajectory_set_cell` and
  :cpp:func:`chfl_trajectory_set_topology` to specify an unit cell or a topology
  for all frames in a trajectory.

Generating a structure
----------------------

Now that we know how to read frames from a trajectory, let's try to create a new
structure and write it to a file. As previsouly, we start by including the
chemfiles header:

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 4

Everything starts with a :cpp:type:`CHFL_TOPOLOGY`. This is the type that
defines the atoms and the connectivity in a system. Here, we add three
:cpp:type:`CHFL_ATOM` and two bonds to create a water molecule.

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 8-18
   :dedent: 4

We can then create a :cpp:type:`CHFL_FRAME` and set its topology. We free the
topology right after, because we no longer need it.

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 20-23
   :dedent: 4

Once we set the topology, we can set the positions

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 25-31
   :dedent: 4

Another possibility is to directly add atoms and bonds to the frame. Here we
define a second molecule representing carbon dioxyde.
:cpp:func:`chfl_frame_add_atom` takes three arguments: the atom, the position
and the velocity of the atom. Here we use ``NULL`` for the velocity, because we
are not interested in it.

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 33-37
   :dedent: 4

Finally, we can set the :cpp:type:`CHFL_CELL` associated with this frame. We
also free the cell memory, as it is no longer needed.

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 39-41
   :dedent: 4

Now that our frame is constructed, it is time to write it to a file. For that,
we open a trajectory in write (``'w'``) mode, and write to it.

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 43-45
   :dedent: 4

And free all remaining memory with the right function.

.. literalinclude:: ../../examples/c/generate.c
   :language: c
   :lines: 47-50
   :dedent: 4

.. htmlhidden::
    :toggle: Click here to see the whole program
    :before-not-html: Wrapping everything up, the whole code looks like this:

    .. literalinclude:: ../../examples/c/generate.c
       :language: c
       :lines: 4-

Using selections
----------------

Now that we know how to read and write frame from trajectories, how about we do
a bit a filtering? In this tutorial, we will read all the frames from a file,
and use :ref:`selections <selection-language>` to filter which atoms we will
write back to another file. This example will also show how chemfiles can be
used to convert from a file format to another one.

We start by opening the two trajectories we will need

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 10-11
   :dedent: 4

We create a :cpp:type:`CHFL_FRAME` and a :cpp:type:`CHFL_SELECTION` object to
filter the atoms we want to keep.

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 12-13
   :dedent: 4

Then we get the number of steps in the trajectory

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 15-16
   :dedent: 4

And iterate over the frames in the trajectory

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 18-19
   :dedent: 4

From here, we need to use the selection to get the atoms we want to remove. This
is a two steps process: first we evaluate the selection and get the number of
matches

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 21-22
   :dedent: 8

Second we allocate some memory and get all the matches (represented as
:cpp:class:`chfl_match`):

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 23-24
   :dedent: 8

We can get the index of atoms in a `to_remove` array

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 26-29
   :dedent: 8

In order to remove the atoms from the frame, we need to sort ``to_remove`` in
descending order: removing the atom at index i will shift the index of all the
atoms after i. So we need start from the end and work toward the start of the
frame. The ``compare_matches`` function is used to do this sorting in reverse
order with the standard `qsort function`_.

.. _qsort function: http://en.cppreference.com/w/c/algorithm/qsort

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 31-34
   :dedent: 8

Finally, we can write the cleaned frame to the output file, and free the memory
we allocated:

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 36-39
   :dedent: 8

The ``compare_matches`` function we used to sort the matches is defined as
follow:

.. literalinclude:: ../../examples/c/select.c
   :language: c
   :lines: 45-52

.. htmlhidden::
    :toggle: Click here to see the whole program
    :before-not-html: The whole program look like this:

    .. literalinclude:: ../../examples/c/select.c
       :language: c
       :lines: 4-
