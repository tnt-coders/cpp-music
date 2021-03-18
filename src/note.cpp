#include "note.hpp"

#include <array>
#include <cassert>
#include <cmath>
#include <string_view>
#include <tnt/math/math.hpp>

namespace tnt::music
{

note::note(double frequency, double f0)
    : m_frequency(frequency)
{
    assert(frequency > 0);

    // Array containing possible note names in 12 tone equal temperament
    constexpr std::array<std::string_view, 12> note_names =
        {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};

    // Number of notes per octave
    constexpr int notes_per_octave = static_cast<int>(note_names.size());

    // Constant used to calculate note values in 12 tone equal temperament
    const auto a = std::pow(2, 1.0 / notes_per_octave);

    // Calculate the semitone offset "n" from f0
    // fn = f0*a^n
    // fn/f0 = a^n
    // n = log_a(fn/f0)
    // n = log(fn/f0)/log(a)
    // Round "n" to the nearest integer to determine the offset. (This effectively gets the
    // quantized value.)
    const int n = static_cast<int>(std::round(std::log(frequency / f0) / std::log(a)));

    // Gets the name of the note from the semitone offset in relation to f0
    // The modulo operation gets the correct array index even if it is negative, or larger than the
    // size of the array.
    m_name = note_names[math::mod(n, notes_per_octave)];

    // Integer division is intentional here. Start at 4 because f0 is the frequency of A4.
    m_octave = 4 + n / notes_per_octave;

    // Gets the frequency of "fn" the closest known musical note.
    // fn = f0*a^n
    m_quantized_frequency = f0 * std::pow(a, n);
}

const double& note::frequency() const
{
    return m_frequency;
}

const double& note::quantized_frequency() const
{
    return m_quantized_frequency;
}

const std::string& note::name() const
{
    return m_name;
}

const int& note::octave() const
{
    return m_octave;
}

}  // namespace tnt::music
