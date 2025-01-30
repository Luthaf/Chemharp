.. _configuration:

Configuration files
===================

Chemfiles can be configured using `TOML`_ configuration files. By default,
chemfiles will read configuration from any file named ``.chemfilesrc`` in the
current directory or any parent directory. Data from directories higher in the
filesystem will be used instead of the one lower in the filesystem. For example,
with the following filesystem:

.. code-block:: bash

    $HOME
    ├── .chemfilesrc (1)
    └── work
        ├── .chemfilesrc (2)
        ├── test-1
        │   ├── trajectory.xyz
        │   └── ...
        └── test-2
            ├── .chemfilesrc (3)
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
