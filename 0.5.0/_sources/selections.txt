.. _selection-language:

Chemfiles selections
====================

Chemfiles selection language is based on the similar selection language provided by
`VMD`_. A selection is a string, and evaluating a selection consist to take this
string and a :ref:`Frame <overview-frame>`, and get the indexes of atoms in the frame
matching the selection.

The selection string can contain names, numbers and operators. Name are sequences of
letter, numbers and ``_`` (underscore) in any order, starting by a letter. Numbers
can be integers, floating-point numbers using a dot (``.``) as decimal separator, or
numbers in scientific notation (``456.745e-45``). Operators can be any of ``== != < <= > >=``.
These operators means respectivly equal; not equal; less; less or equal; more and
more or equal.

Simple selections consist of a selector and a condition. Supported selectors are:

- ``all`` and ``none``: Select respectively all and none of the atoms.
- ``name``: select atoms based on their name. This selector support three forms:
  ``name == <value>``, ``name != <value>`` and a short form ``name <value>``
  which is equivalent to ``name == <value>``;
- ``index``: select atoms based on their index in the frame. Any operator can be used,
  and the atom index is compared to a positive integer value. The short form
  ``index <value>`` is equivalent to ``index == <value>``. Examples: ``index < 6``,
  ``index >= 42``;
- ``mass``: select atoms based on their mass. Any operator can be used. The short form
  ``mass <value>`` is equivalent to ``mass == <value>``. Examples: ``mass < 2.0``,
  ``mass == 4.2``;
- ``x``, ``y`` and ``z``: select atoms based on their position components. Any
  operator can be used, and their is no short form with this selection. ``==`` and
  ``!=`` can be used, but comparing floating point values will procude strange
  results most of the time. Examples: ``x > 5.3``; ``z <= 5.3``;
- ``vx``, ``vy`` and ``vz``: select atoms based on their velocity components. These
  selectors works the same way as ``x``, ``y`` and ``z``.

Simple selections can be combined together using booleans operations:

- ``<selection_1> and <selection_2>``: an atom will match this selction if and only
  if it matches *selection_1* and *selection_2*;
- ``<selection_1> or <selection_2>``: an atom will match this selction if it matches
  any of *selection_1* or *selection_2*;
- ``not <selection>``: an atom will match this selction if and only if it DO NOT
  matches *selection*.

In order to remove ambiguity when using multiple boolean operations, selections
should use parentheses. If no parentheses are present, all operators will be
considered left-associatives.

Some more complex selections:

.. code-block:: text

    name H and not x < 5.0
    (z < 45 and name O) or name C
    vx > 3 or vy > 3 or vz > 3

.. _VMD: http://www.ks.uiuc.edu/Research/vmd/
