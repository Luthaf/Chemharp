Helper classes
==============

Chemfiles contains C++11 implentations of various goodies from more recent
versions of the language, or support libraries. Here is a small documentation on
how to use these types.

``optional<T>``
---------------

.. cpp:class:: template <class T> chemfiles::optional

    A class representing optional values. Basic usage example is given here, you
    can also refer to the documentation for ``std::optional`` on
    `cppreference`_.

    For most purposes, one can use an ``optional<T>`` value as if it was a
    pointer ``T*``, with ``nullptr`` indicating the abscence of a value.

    .. code-block:: cpp

        // nullopt is used to indicate the optional data is missing
        chemfiles::optional<double> optional = nullopt;

        if (optional) {
            // chemfiles::optional is convertible to bool
        }

        // Setting a value
        optional = 78.0;

        // Getting back the value
        double a = *optional;
        double b = optional.value();

        // Specifying a default value when data is missing
        double c = optional.value_or(-1);


.. _cppreference: http://en.cppreference.com/w/cpp/utility/optional

``span<T>``
-----------

.. cpp:class:: template <class T> chemfiles::span

    A ``span<T>`` is a view inside a ``std::vector<T>`` providing all the
    operations of a vector expect for memory allocation. The idea and
    implementation comes from the `GSL`_ library.

    .. code-block:: cpp

        // you should never need to create a span yourself
        chemfiles::span<double> span = /* ... */;

        // span supports range-based iteration
        for (double a: span) {
            // ...
        }

        // but also classical iteration
        for (size_t i=0; i<span.size(); i++) {
            double b = span[i];
        }

        // and direct indexing
        double b = span[5];
        span[6] = 78.3;

        // You can also use a span with standard algorithms
        auto sum = std::accumulate(span.begin(), std::end(span), 0.0);


.. _GSL: http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#gsl-guideline-support-library
