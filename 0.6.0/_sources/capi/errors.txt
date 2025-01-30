Functions for errors handling
-----------------------------

Apart from the *constructor* functions (the functions returning pointers to the
types defined above); all the functions return a status code, which is 0 if
nothing went wrong, and another value in case of error. The following function
allow for error handling from the C side.

.. doxygenfunction:: chfl_strerror

.. doxygenfunction:: chfl_last_error

.. doxygenfunction:: chfl_clear_errors

.. doxygenenum:: CHFL_LOG_LEVEL

.. doxygenfunction:: chfl_loglevel

.. doxygenfunction:: chfl_set_loglevel

.. doxygenfunction:: chfl_logfile

.. doxygenfunction:: chfl_log_stderr

The return values for this status code correspond to the following macros:

.. doxygendefine:: CHFL_SUCCESS

.. doxygendefine:: CHFL_MEMORY_ERROR

.. doxygendefine:: CHFL_FILE_ERROR

.. doxygendefine:: CHFL_FORMAT_ERROR

.. doxygendefine:: CHFL_GENERIC_ERROR

.. doxygendefine:: CHFL_CXX_ERROR
