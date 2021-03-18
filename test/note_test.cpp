#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <tnt/music/note.hpp>
#include <vector>

using namespace tnt;

struct note_data
{
    music::note note;
    double      frequency;
    std::string name;
    int         octave;
    double      quantized_frequency;
};

TEST_CASE("note accessors", "[note][accessors]")
{
    std::vector<note_data> notes;
    notes.push_back({music::note(16.35), 16.35, "C", 0, 16.35});
    notes.push_back({music::note(427.65), 427.65, "A", 4, 440});
    notes.push_back({music::note(432, 432), 432, "A", 4, 432});
    notes.push_back({music::note(440), 440, "A", 4, 440});
    notes.push_back({music::note(453.08), 453.08, "A#/Bb", 4, 466.16});
    notes.push_back({music::note(261.63), 261.63, "C", 4, 261.63});
    notes.push_back({music::note(7902.13), 7902.13, "B", 8, 7902.13});

    SECTION("frequency")
    {
        for (const auto& note_data : notes)
        {
            CHECK_THAT(note_data.note.frequency(),
                       Catch::Matchers::WithinAbs(note_data.frequency, 0.01));
        }
    }

    SECTION("name")
    {
        for (const auto& note_data : notes)
        {
            CHECK(note_data.note.name() == note_data.name);
        }
    }

    SECTION("octave")
    {
        for (const auto& note_data : notes)
        {
            CHECK(note_data.note.octave() == note_data.octave);
        }
    }

    SECTION("quantized_frequency")
    {
        for (const auto& note_data : notes)
        {
            CHECK_THAT(note_data.note.quantized_frequency(),
                       Catch::Matchers::WithinAbs(note_data.quantized_frequency, 0.01));
        }
    }
}
