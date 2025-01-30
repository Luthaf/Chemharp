.. _selection-language:

Selection language
==================

Chemfiles selection language allows to select some atoms in a :ref:`Frame
<overview-frame>` matching a set of constraints. For examples, ``atom: name H
and x > 15`` would select all *single atoms* whose name is ``H`` and x
coordinate is bigger than 15.

Chemfiles selections differs from the well-known `VMD`_ selections by the fact
that they are *multiple selections*: we can select more than one atom at once.
All selections starts with a context, indicating the number of atoms we are
selecting, and the relation between these atoms. Existing contextes are
``atoms`` or ``one``, ``pairs`` or ``two``, ``three`` and ``four``  to select
one, two, three or four independent atoms; and ``bonds``, ``angles`` and
``dihedrals`` for two, three or four bonded atoms.

.. _VMD: http://www.ks.uiuc.edu/Research/vmd/

A selection is built using a context and a set of constraints separated by a
colon. For example, ``atoms: name == H`` will select all atoms whose name is
``H``. ``angles: name($2) == O and distance($1, $3) < 1.5`` will select all sets
of three bonded atoms forming an angle such that the name of the second atom is
``O`` and the distance between the first and the third atom is less than 1.5.

These constraints are created using *selectors*. Selectors are small functions
which can be applied to one or more atoms. The ``name``, ``mass`` and ``z``
selectors are applied to one atom and give the name, the mass and the z
coordinate of this atom. Other selectors can be applied to two or more atoms,
like ``distance`` or ``angle``. When using a selection with more than one atom,
selectors refers to the different atoms with the ``$1``, ``$2``, ``$3`` or
``$4`` variables: ``name($3)`` will give the name of the third atom, and so on.
Then we compare the selector result for a given atom with a value, either from
another selector --- ``name($1) != name($2)`` --- or a literal value ---
``mass($2) < 4``. The comparison operators are ``==`` (equals); ``!=`` (not
equals); ``<`` (less than), ``<=`` (less or equals); ``>`` (more than); and ``>=``
(more or equals).

Finally, constraints are combined with boolean operators. The ``and`` operator
is true if both side of the expression are true; the ``or`` operator is true if
either side of the expression is true; and the ``not`` operator reverse true to
false and false to true. ``name($1) == H and not x($1) < 5.0`` and ``(z($2) < 45
and name($4) == O) or name($1) == C`` are complex selections using booleans
operators.

In order to remove ambiguity when using multiple boolean operations, selections
should use parentheses. If no parentheses are present, all operators will be
treated as left-associatives.

Selectors
---------

The following selectors are implemented in chemfiles:

- ``all``: select all the atoms;
- ``none``: select none of the atoms;
- ``name``: select atoms based on their name;
- ``index``: select atoms based on their index in the frame;
- ``mass``: select atoms based on their mass;
- ``x``, ``y`` and ``z``: select atoms based on their position cartesian components;
- ``vx``, ``vy`` and ``vz``: select atoms based on their velocity cartesian components;

Additional selectors ideas are welcome if they cannot be created easily from a
combinaison of the above. If you don't know if your selector idea can be
created from a combinaison, just ask!

Elisions
--------

This multiple selection language can be a bit verbose for simpler cases, so it
is sometimes allowed to remove parts of the selection. First, in the ``atom``
context, the ``$1`` variable is optional, and ``atom: name($1) == H`` is
equivalent to ``atom: name == H``.

Then, if no context is given, the ``atom`` context is used. This make ``atom:
name == H`` equivalent to ``name == H``.

And finally, the ``==`` comparison operator is the default one if no operator is
precised. This means that we can write ``name H`` instead of ``name == H``.

At the end, using all these elisions rules, ``atom: name($1) == H or name($1) ==
O`` is equivalent to ``name H or name O``; and ``bond: name($1) == C and
mass($2) == 4.5`` is equivalent to ``bond: name($1) C and mass($2) 4.5``.
