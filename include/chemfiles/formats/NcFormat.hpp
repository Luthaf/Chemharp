/* Chemfiles, an efficient IO library for chemistry file formats
 * Copyright (C) 2015 Guillaume Fraux
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#include "chemfiles/config.hpp"
#if HAVE_NETCDF

#ifndef CHEMFILES_FORMAT_NC_HPP
#define CHEMFILES_FORMAT_NC_HPP

#include "chemfiles/types.hpp"
#include "chemfiles/Format.hpp"
#include "chemfiles/TrajectoryFactory.hpp"

namespace chemfiles {

class UnitCell;
class Topology;
class NcFile;

/*!
 * @class NCFormat formats/NcFormat.hpp formats/NcFormat.cpp
 * @brief Amber NetCDF file format reader.
 *
 * http://ambermd.org/netcdf/nctraj.xhtml
 */
class NCFormat final: public Format {
public:
    NCFormat(File& file);
    ~NCFormat() = default;

    virtual void read_step(size_t step, Frame& frame) override;
    virtual void read(Frame& frame) override;
    virtual void write(const Frame& frame) override;

    virtual size_t nsteps() override;
    virtual std::string description() const override;

    using file_t = NcFile;

    // Register the Amber NetCDF format with the ".nc" extension and the
    // "AmberNetCDF" description.
    FORMAT_NAME(AmberNetCDF)
    FORMAT_EXTENSION(.nc)
private:
    //! Read the unit cell at the current internal step, the file is assumed to be valid.
    UnitCell read_cell() const;
    //! Generic function to read an Array3D at the current internal step,
    //! the file is assumed to be valid.
    void read_array3D(Span3D array, const std::string& name) const;

    //! Write an Array3D to the file, as a variable with the name `name`, at
    //! the current internal step.
    void write_array3D(const Array3D& array, const std::string& name) const;
    //! Write an UnitCell to the file, at the current internal step
    void write_cell(const UnitCell& cell) const;

    //! Reference to the associated file.
    NcFile& ncfile_;
    //! Last read step
    size_t step_;
    //! Was the associated file validated?
    bool validated_;
};

} // namespace chemfiles

#endif

#endif // HAVE_NETCDF
