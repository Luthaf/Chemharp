Miscelaneous functions
======================

Error handling
--------------

Apart from the *constructor* functions (the functions returning pointers to the
chemfiles types); all the functions return a status code from the
``chfl_status`` enum:

.. doxygenenum:: chfl_status

.. doxygenfunction:: chfl_last_error

.. doxygenfunction:: chfl_clear_errors

Warnings
--------

The chemfiles library send warnings when it encounters malformed files, or any
other condition that the user might want to know about. By default, these
warnings are printed to the standard error stream.
:cpp:func:`chfl_set_warning_callback` allow to redirect these warning by giving
it a callback function to be called on each warning event.

.. doxygentypedef:: chfl_warning_callback

.. doxygenfunction:: chfl_set_warning_callback

Configuration files
-------------------

You can add more :ref:`configuration <configuration>` file to chemfiles with
:cpp:func:`chfl_add_configuration`.

.. doxygenfunction:: chfl_add_configuration
