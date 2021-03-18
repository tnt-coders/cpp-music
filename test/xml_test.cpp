#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("test", "[test]")
{
    boost::property_tree::ptree tree;

    boost::property_tree::ptree score_partwise;
    score_partwise.put("<xmlattr>.version", "2.0");

    boost::property_tree::ptree work;
    work.put("work-title", "test");

    score_partwise.add_child("work", work);

    boost::property_tree::ptree part_list;

    boost::property_tree::ptree score_part;
    score_part.put("<xmlattr>.id", "P1");
    score_part.put("part-name", "Guitar");
    score_part.put("part-abbreviation", "Gt");

    part_list.add_child("score-part", score_part);

    score_partwise.add_child("part-list", part_list);

    boost::property_tree::ptree part;
    part.put("<xmlattr>.id", "P1");

    boost::property_tree::ptree measure;
    measure.put("<xmlattr>.number", 1);

    boost::property_tree::ptree attributes;

    boost::property_tree::ptree clef;
    clef.put("<xmlattr>.number", 1);
    clef.put("sign", "TAB");
    clef.put("line", 5);

    attributes.add_child("clef", clef);

    boost::property_tree::ptree staff_details;
    staff_details.put("<xmlattr>.number", 1);
    staff_details.put("staff-lines", 6);

    boost::property_tree::ptree staff_tuning1;
    staff_tuning1.put("<xmlattr>.line", 1);
    staff_tuning1.put("tuning-step", "E");
    staff_tuning1.put("tuning-octave", 2);

    staff_details.add_child("staff-tuning", staff_tuning1);

    boost::property_tree::ptree staff_tuning2;
    staff_tuning2.put("<xmlattr>.line", 2);
    staff_tuning2.put("tuning-step", "A");
    staff_tuning2.put("tuning-octave", 2);

    staff_details.add_child("staff-tuning", staff_tuning2);

    boost::property_tree::ptree staff_tuning3;
    staff_tuning3.put("<xmlattr>.line", 3);
    staff_tuning3.put("tuning-step", "D");
    staff_tuning3.put("tuning-octave", 3);

    staff_details.add_child("staff-tuning", staff_tuning3);

    boost::property_tree::ptree staff_tuning4;
    staff_tuning4.put("<xmlattr>.line", 4);
    staff_tuning4.put("tuning-step", "G");
    staff_tuning4.put("tuning-octave", 3);

    staff_details.add_child("staff-tuning", staff_tuning4);

    boost::property_tree::ptree staff_tuning5;
    staff_tuning5.put("<xmlattr>.line", 5);
    staff_tuning5.put("tuning-step", "B");
    staff_tuning5.put("tuning-octave", 3);

    staff_details.add_child("staff-tuning", staff_tuning5);

    boost::property_tree::ptree staff_tuning6;
    staff_tuning6.put("<xmlattr>.line", 6);
    staff_tuning6.put("tuning-step", "E");
    staff_tuning6.put("tuning-octave", 4);

    staff_details.add_child("staff-tuning", staff_tuning6);

    attributes.add_child("staff-details", staff_details);

    measure.add_child("attributes", attributes);

    boost::property_tree::ptree direction;
    direction.put("<xmlattr>.directive", "yes");

    /*boost::property_tree::ptree direction_type;

    boost::property_tree::ptree metronome;
    metronome.put("<xmlattr>.parentheses", "no");
    metronome.put("<xmlattr>.default-y", "40");
    metronome.put("beat-unit", "quarter");
    metronome.put("per-minute", 60);

    direction_type.add_child("metronome", metronome);*/

    boost::property_tree::ptree sound;
    sound.put("<xmlattr>.tempo", 60);

    direction.add_child("sound", sound);

    measure.add_child("direction", direction);

    boost::property_tree::ptree note;

    boost::property_tree::ptree pitch;
    pitch.put("step", "E");
    pitch.put("octave", 2);

    note.add_child("pitch", pitch);

    note.put("duration", 1);
    note.put("voice", 1);
    note.put("type", "quarter");
    note.put("stem", "up");

    boost::property_tree::ptree notations;

    boost::property_tree::ptree dynamics;
    dynamics.put("mf", "");

    notations.add_child("dynamics", dynamics);

    boost::property_tree::ptree technical;
    technical.put("string", 6);
    technical.put("fret", 0);

    notations.add_child("technical", technical);

    note.add_child("notations", notations);

    measure.add_child("note", note);

    part.add_child("measure", measure);

    score_partwise.add_child("part", part);

    tree.add_child("score-partwise", score_partwise);

    boost::property_tree::xml_writer_settings<std::string> settings(' ', 1);
    boost::property_tree::write_xml("test.xml", tree, std::locale(), settings);
}
