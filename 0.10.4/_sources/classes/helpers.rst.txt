Helper classes
==============

Chemfiles contains C++11 implementations of various goodies from more recent
versions of the language, or support libraries. Here is a small documentation on
how to use these types.

``optional<T>``
---------------

.. cpp:class:: template <class T> chemfiles::optional

    A class representing optional values. Basic usage example is given here, you
    can also refer to the documentation for ``std::optional`` on
    `cppreference`_.

    For most purposes, one can use an ``optional<T>`` value as if it was a
    pointer ``T*``, with ``nullopt`` indicating the absence of a value.

    .. code-block:: cpp

        // nullopt is used to indicate the optional data is missing
        chemfiles::optional<double> optional = nullopt;

        if (optional) {
            // chemfiles::optional is convertible to bool
        }

        // setting a value
        optional = 78.0;

        // extracting the value
        double a = *optional;
        double b = optional.value();

        // specifying a default value to be used if data is missing
        double c = optional.value_or(-1);


.. _cppreference: https://en.cppreference.com/w/cpp/utility/optional

``span<T>``
-----------

.. cpp:class:: template <class T> chemfiles::span

    A ``span<T>`` is a view inside a ``std::vector<T>`` providing all the
    operations of a vector except for memory allocation. The idea and
    implementation comes from the `GSL`_ library.

    .. code-block:: cpp

        // you should never need to create a span yourself
        chemfiles::span<double> span = /* ... */;

        // span supports range-based iteration
        for (auto a: span) {
            // ...
        }

        // but also the usual indexing
        for (size_t i=0; i<span.size(); i++) {
            double b = span[i];
        }

        // and direct indexing
        double b = span[5];
        span[6] = 78.3;

        // you can also use a span with standard algorithms
        auto sum = std::accumulate(span.begin(), span.end(), 0.0);


.. _GSL: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-gsl
