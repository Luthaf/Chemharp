Errors and warnings
===================

Errors
------

In chemfiles, any error will throw an exception. Any program using chemfiles
should thus wrap any call in a ``try ... catch`` block, and handle the errors in
any pertinent way.

.. code-block:: cpp

    #include <iostream>
    #include "chemfiles.cpp"

    int main() {
        try {
            chemfiles::Trajectory file("filename.xyz");
            chemfiles::Frame frame;
            file.read(frame);
            auto positions = frame.positions();
            // Do something here
        } catch (const chemfiles::Error& e) {
            // Basic error handling logging error to stdout
            std::cout << "Error in chemfiles:" << e.what() << std::endl;
            return -1;
        }

        return 0;
    }

Any exceptions thown by chemfiles will derive from ``chemfiles::Error``.
Catching  ``chemfiles::Error`` will then catch any exception thown by chemfiles.
You also can catch any other error if you need finer grain control.
``chemfiles::Error`` derives from ``std::runtime_error``, so it should play
nicely with any exisiting C++ error handling.

.. doxygenstruct:: chemfiles::Error
    :members:

.. doxygenstruct:: chemfiles::FileError
    :members:

.. doxygenstruct:: chemfiles::MemoryError
    :members:

.. doxygenstruct:: chemfiles::FormatError
    :members:

.. doxygenstruct:: chemfiles::SelectionError
    :members:

Warnings
--------

Chemfiles also send warnings on some malformed files. You can use the
`set_warning_callback` function to register a global callback to use when
sending a warning.

.. doxygenfunction:: chemfiles::set_warning_callback

.. doxygentypedef:: chemfiles::warning_callback
