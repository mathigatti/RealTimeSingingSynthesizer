add_library(sinsy SHARED
        lib/converter/ConfGroup.cpp
        lib/converter/ConfManager.cpp
        lib/converter/Converter.cpp
        lib/converter/PhonemeInfo.cpp
        lib/converter/UnknownConf.cpp
        lib/converter/util_converter.cpp
        lib/hts_engine_API/SynthConditionImpl.cpp
        lib/japanese/JConf.cpp
        lib/label/LabelData.cpp
        lib/label/LabelMaker.cpp
        lib/label/LabelMeasure.cpp
        lib/label/LabelPosition.cpp
        lib/label/LabelStream.cpp
        lib/label/LabelStrings.cpp
        lib/label/NoteGroup.cpp
        lib/label/NoteLabeler.cpp
        lib/label/PhonemeLabeler.cpp
        lib/label/SyllableLabeler.cpp
        lib/score/Beat.cpp
        lib/score/Dynamics.cpp
        lib/score/Key.cpp
        lib/score/Mode.cpp
        lib/score/Note.cpp
        lib/score/Pitch.cpp
        lib/score/ScorePosition.cpp
        lib/score/Slur.cpp
        lib/score/Syllabic.cpp
        lib/score/util_score.cpp
        lib/temporary/ScoreDoctor.cpp
        lib/temporary/TempScore.cpp
        lib/util/Configurations.cpp
        lib/util/DiphthongConverter.cpp
        lib/util/IStringable.cpp
        lib/util/InputFile.cpp
        lib/util/MacronTable.cpp
        lib/util/MultibyteCharRange.cpp
        lib/util/OutputFile.cpp
        lib/util/PhonemeTable.cpp
        lib/util/StringTokenizer.cpp
        lib/util/util_string.cpp
        lib/xml/XmlData.cpp
        lib/xml/XmlParser.cpp
        lib/xml/XmlReader.cpp
        lib/xml/XmlWriter.cpp
        lib/shm_ringbuffer/ringbuffer.cpp
        lib/Sinsy.cpp
        )
  
include_directories(lib/util lib/score lib/japanese lib/converter lib/temporary lib/xml lib/shm_ringbuffer include)


set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")

set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")

add_executable(sinsyNG bin/sinsy.cpp)
target_link_libraries(sinsyNG sinsy espeak-ng sndfile samplerate)

install(FILES include/sinsy.h lib/shm_ringbuffer/ringbuffer.h DESTINATION include/sinsy)

install(TARGETS sinsy sinsyNG
        LIBRARY DESTINATION lib/${CMAKE_ARCH_TRIPLET}
        RUNTIME DESTINATION bin
)
