// Chemfiles, a modern library for chemistry file reading and writing
// Copyright (C) Guillaume Fraux and contributors -- BSD license

#include <chemfiles.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    // [example]
    CHFL_TOPOLOGY* topology = chfl_topology();

    chfl_topology_resize(topology, 67);

    uint64_t atoms = 0;
    chfl_topology_atoms_count(topology, &atoms);
    assert(atoms == 67);

    chfl_free(topology);
    // [example]
    return 0;
}
