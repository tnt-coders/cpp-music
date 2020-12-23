#pragma once

#include <string>

// TODO: Track the type of note as well (quarter, eigth, sixteenth, etc.)

namespace tnt::music
{

/*!
\brief Represents a musical note

This class represents musical note data. It provides a method for storing and retrieving information
about musical notes. Note objects are created byproviding the frequency of the note. Attributes of
the Note object are calculated from the equations given on the
<a href="http://pages.mtu.edu/~suits/NoteFreqCalcs.html">Physics of Music - Notes</a> page. f0 (the
reference frequency used to calculate the values of all notes) is 440 by default, but a custom value
for f0 can be specified when creating a Note object. Currently only the standard 12-tone equal
temperament note system used in most Western music is supported.
*/
class Note
{
public:
    /*!
    \brief Constructs a musical note object

    Note constructor. In order to fully define a musical note, it's frequency must be provided,
    along with a fixed reference frequency (f0). By convention, the reference frequency defines the
    value of the A note above middle C (A4). The default value for f0 is 440Hz, but a different
    frequency may be used if desired.

    \param frequency The frequency of the note in Hz
    \param f0 Reference frequency of A4 (default = 440Hz)
    */
    Note(double frequency, double f0 = 440);

    /*!
    \brief Gets the frequency of the musical note
    \return The frequency of the musical note
    */
    const double& frequency() const;

    /*!
    \brief Gets the name of the musical note
    \return The name of the musical note
    */
    const std::string& name() const;

    /*!
    \brief Gets the octave of the musical note
    \return The octave of the musical note
    */
    const int& octave() const;

    /*!
    \brief Gets the quantized frequency of the musical note
    \return The quantized frequency of the musical note
    */
    const double& quantized_frequency() const;

private:
    double      m_frequency;
    std::string m_name;
    int         m_octave;
    double      m_quantized_frequency;
};

}  // namespace tnt::music
