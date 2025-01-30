Contributing
============

Chemfiles is an open-source project, that I make on my free time. Any contribution,
from documentation improvement to new features including bug fixes are very welcome!

I would like to help, what can I do ?
-------------------------------------

Lot of things! Just pick one considering the time you can spend, and your technical
skills.

Improving the code
^^^^^^^^^^^^^^^^^^

There are multiple way to improve the code. You can either `pick up a TODO`_ in the
code, or any `issue`_ in the list. If you plan to add a new feature which is not in
the issue list, please open a new one so that every one knows you are working on it,
and so that the implementation can be discussed!

.. _pick up a TODO: https://github.com/chemfiles/chemfiles/search?utf8=%E2%9C%93&q=todo
.. _issue: https://github.com/chemfiles/chemfiles/issues

Improve documentation
^^^^^^^^^^^^^^^^^^^^^

This documentation try to be easy to use, but there is always room for improvements.
You can easily edit any :file:`.rst` file on `the github repository
<https://github.com/chemfiles/chemfiles/tree/master/doc>`_, and propose your changes
even with no git knowledge. All you need is a Github account.

Share and spread the word
^^^^^^^^^^^^^^^^^^^^^^^^^

If you think that chemfiles is awesome, share it! The more users it will have, the
more features we can add to it, together!

External project used
---------------------

A few external projects are used in chemfiles developement, and you will need a bit
of knowledge of them to contribute. Depending on what you want to do, not all these
projects are needed.

- Source code versionning: `git`_, together with `github`_ web interface for issues
  and pull requests.
- documentation: `sphinx`_ for generating HTML and PDF documentation, `Doxygen`_ for
  documenting the source code, and `breathe`_ to use Doxygen content in sphinx.
- Build system: `cmake`_ is used as a cross-plateform, cross-build system generator.
- Automatic testing: `CATCH`_ provide an nice unit test framework, and `travis`_ run
  these tests each time the code is pushed to the repository.


.. _git: https://git-scm.com/
.. _github: https://github.com/about/
.. _sphinx: http://www.sphinx-doc.org/
.. _Doxygen: http://doxygen.org/
.. _breathe: https://breathe.readthedocs.io/
.. _cmake: https://cmake.org/
.. _CATCH: https://github.com/philsquared/Catch/
.. _travis: https://travis-ci.org/chemfiles/chemfiles/


Coding style, and other formating issues
----------------------------------------

When writing code for chemfiles, please respect the overall coding style. This is not
only a question of style, but make it easier to enter in the project if all the files
are formatted consistently. Do not use non standard features of any programming
language unless there is no other way to do it. In that case, please wrap the code in
``#ifdef`` macros, and add cases for at least Linux, OS X and Windows. You should add
unit tests for each new piece of code, they will be run on `travis`_ before your
changes are merged.

Git messages should be informatives, and describe the *what*, not the *how*. If your
commit concern the documentation, please add the ``[doc]`` at the beggining of the
message.

Happy coding!
