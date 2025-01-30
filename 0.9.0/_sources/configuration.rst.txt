.. _configuration:

Configuration files
===================

Chemfiles can be configured using `TOML`_ configuration files. By default,
chemfiles will read configuration from any file named ``.chemfiles.toml`` or
``chemfiles.toml`` in the current directory or any parent directory. Data from
directories higher in the filesystem will be used instead of the one lower in
the filesystem. For example, with the following filesystem:

.. code-block:: bash

    $HOME
    ├── .chemfiles.toml (1)
    └── work
        ├── chemfiles.toml (2)
        ├── test-1
        │   ├── trajectory.xyz
        │   └── ...
        └── test-2
            ├── .chemfiles.toml (3)
            ├── trajectory.nc
            └── ...

Running chemfiles from ``$HOME/`` will only use the configuration file ``(1)``,
running it from ``$HOME/work/test-1`` will use the configuration file ``(2)``
first and then from ``(1)``, and running it from ``$HOME/work/test-2`` will use
configuration data from ``(3)``, then ``(2)`` and then ``(1)``.

Configuration files should be valid `TOML`_ files, and can contain various
sections.

.. _TOML: https://github.com/toml-lang/toml


``[types]``: atomic type renaming
---------------------------------

The ``[types]`` section of the configuration file allow to change atomic types
to make sure they match element name. For example, in a simulatiion where water
molecules are named ``Hw-Ow-Hw``, one may use this section of the input file
like this:

.. code-block:: text

    [types]
    Ow = "O"
    Hw = "H"

Renaming atomic type allow to ensure that bonds will be guessed right, and that
the right atomic data can be accessed.

The ``[types]`` section contains multiple key wich are the old atom type,
associated with string values wich are the new atom type.

``[atoms]``: Defining new atom types
------------------------------------

When working with particles outside of the periodic table (for example coarse
grained particles), it can be usefull to define new atom types. This can be done
in the ``[atom]`` section.

.. code-block:: text

    [atoms.CH3]
    full_name = "methyl"
    mass = 15.035
    charge = 0
    vdw_radius = 2.4
    covalent_radius = 1.1

    # One can also override element data
    [atoms.Zn]
    charge = 1.8

    # TOML also supports inline tables
    [atoms]
    CH4 = {mass = 16.043, charge = 0, full_name = "methane"}
    Ph = {mass = 77.106, full_name = "phenyl"}

The ``[atoms]`` section contains multiple tables, one for each new atom type.
These tables can contains the following key/values (all keys are optional):

- ``full_name`` (string) : the full name of the atomic type;
- ``mass`` (number) : the mass of the atomic type in atomic units;
- ``charge`` (number) : the charge of the atomic type in multiples of *e*;
- ``vdw_radius`` (number) : the Van der Waals radius of the atomic type in Angstrom;
- ``covalent_radius`` (number) : the covalent radius of the atomic type in Angstrom;
