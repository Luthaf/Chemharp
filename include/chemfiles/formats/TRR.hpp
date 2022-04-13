// Chemfiles, a modern library for chemistry file reading and writing
// Copyright (C) Guillaume Fraux and contributors -- BSD license

#ifndef CHEMFILES_TRR_FORMAT_HPP
#define CHEMFILES_TRR_FORMAT_HPP

#include <string>

#include "chemfiles/File.hpp"
#include "chemfiles/Format.hpp"

#include "chemfiles/files/XDRFile.hpp"

namespace chemfiles {
class Frame;
class FormatMetadata;

/// GROMACS TRR file format reader.
class TRRFormat final : public Format {
  public:
    TRRFormat(std::string path, File::Mode mode, File::Compression compression);

    void read_step(size_t step, Frame& frame) override;
    void read(Frame& frame) override;
    void write(const Frame& frame) override;
    size_t nsteps() override;

  private:
    struct FrameHeader {
        bool use_double; /* Double precision?                                       */
        int ir_size;     /* Backward compatibility                                  */
        int e_size;      /* Backward compatibility                                  */
        int box_size;    /* Size in Bytes, non zero if a box is present             */
        int vir_size;    /* Backward compatibility                                  */
        int pres_size;   /* Backward compatibility                                  */
        int top_size;    /* Backward compatibility                                  */
        int sym_size;    /* Backward compatibility                                  */
        int x_size;      /* Size in Bytes, non zero if coordinates are present      */
        int v_size;      /* Size in Bytes, non zero if velocities are present       */
        int f_size;      /* Size in Bytes, non zero if forces are present           */

        int natoms;    /* The total number of atoms                               */
        int step;      /* Current step number                                     */
        int nre;       /* Backward compatibility                                  */
        double time;   /* Current time (float or double)                          */
        double lambda; /* Current value of lambda (float or double)               */
    };

    /// Read header of the Frame at the current position
    FrameHeader read_frame_header();
    /// Write header of a Frame
    void write_frame_header(const FrameHeader& header);
    /// Determine the number of frames
    /// and the corresponding offset within the file
    void determine_frame_offsets();

    /// Associated XDR file
    XDRFile file_;
    /// Offsets within file for fast indexing
    std::vector<uint64_t> frame_offsets_;
    /// The next step to read
    size_t step_ = 0;
    /// The number of atoms in the trajectory
    size_t natoms_ = 0;
};

template <> const FormatMetadata& format_metadata<TRRFormat>();

} // namespace chemfiles

#endif
