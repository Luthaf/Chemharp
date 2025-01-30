Functions for errors handling
-----------------------------

Apart from the *constructor* functions (the functions returning pointers to the
chemfiles types); all the functions return a status code from the
``chfl_status`` enum:

.. doxygenenum:: chfl_status

The following function allow to handle errors:

.. doxygenfunction:: chfl_last_error

.. doxygenfunction:: chfl_clear_errors

.. doxygentypedef:: chfl_warning_callback

.. doxygenfunction:: chfl_set_warning_callback
