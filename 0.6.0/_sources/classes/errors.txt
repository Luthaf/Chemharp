Errors and exceptions
=====================

In chemfiles, the errors are handled by using exceptions. So any program using
chemfiles should wrap the call between a ``try ... catch`` statment, and handle the
errors in any pertinent way.

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
            // Basic error handling by just logging error to stdout
            std::cout << "Error in chemfiles:" << e.what() << std::endl;
            return -1;
        }

        return 0;
    }

All the exceptions derives from ``chemfiles::Error``, so catching only
``chemfiles::Error`` is OK. You also can catch any other error if you need finer
grain control. ``chemfiles::Error`` derives from ``std::runtime_error``, and thus
should play nicely with any exisiting C++ error handling.

.. doxygenstruct:: chemfiles::Error
    :members:

.. doxygenstruct:: chemfiles::FileError
    :members:

.. doxygenstruct:: chemfiles::MemoryError
    :members:

.. doxygenstruct:: chemfiles::FormatError
    :members:

.. doxygenstruct:: chemfiles::PluginError
    :members:

.. doxygenstruct:: chemfiles::SelectionError
    :members:
