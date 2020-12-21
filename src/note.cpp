#include "note.hpp"

#include <string>
#include <tnt/math/math.hpp>
#include <vector>

namespace tnt::music
{

constexpr std::vector<std::string> NOTE_NAMES =
    {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};

constexpr int NOTES_PER_OCTAVE = static_cast<int>(NOTE_NAMES.size());

const double a = pow(2, 1.0 / NOTES_PER_OCTAVE);

Note::Note(double frequency, double f0)
    : m_frequency(frequency)
{
    // Calculate the semitone offset "n" from f0
    // fn = f0*a^n
    // fn/f0 = a^n
    // n = log_a(fn/f0)
    // n = log(fn/f0)/log(a)
    // Round "n" to the nearest integer to determine the offset. (This effectively gets the
    // quantized value.)
    int n = static_cast<int>(round(log(frequency / f0) / log(a)));

    // Gets the name of the note from the semitone offset in relation to f0
    // The modulo operation gets the correct array index even if it is negative, or larger than the
    // size of the array.
    m_name = NOTE_NAMES[static_cast<size_t>(math::mod(n, NOTES_PER_OCTAVE))];

    // Integer division is intentional here. Start at 4 because f0 is the frequency of A4.
    m_octave = 4 + n / NOTES_PER_OCTAVE;

    // Gets the frequency of "fn" the closest known musical note.
    // fn = f0*a^n
    m_quantized_frequency = f0 * pow(a, n);
}

const double& Note::frequency() const
{
    return m_frequency;
}

const double& Note::quantized_frequency() const
{
    return m_quantized_frequency;
}

const std::string& Note::name() const
{
    return m_name;
}

const int& Note::octave() const
{
    return m_octave;
}

} /* namespace tnt::music */
