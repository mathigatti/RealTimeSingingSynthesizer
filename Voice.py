import os
from math import ceil

from midiutil import MIDIFile
from midi2voice.midi2xml import midi2xml

def renderize_voice(output_name, lyrics, notes, durations, tempo, scale, language_code):
	MIDI_PATH = "voice.mid"
	VOICE_XML_PATH= "voice.xml"

	compose(notes, durations, scale, MIDI_PATH)
	midi2xml(lyrics, MIDI_PATH, VOICE_XML_PATH, tempo)

	os.system("LD_LIBRARY_PATH=/usr/lib synthesisSoftware/Sinsy-NG-0.0.1/build/sinsyNG -t "+str(tempo)+" -m "+language_code+" -o " + output_name + " " + VOICE_XML_PATH)


def create_midi(midi_file, composition):
    print("Composition:")
    print(composition)

    MyMIDI = MIDIFile(1)

    track = 0
    channel = 0
    for note in composition:
        pitch = note[0]
        duration = note[1] # In beats
        volume   = note[2] # 0-127, as per the MIDI standard
        time = note[3]

        MyMIDI.addNote(track, channel, pitch, time, duration, volume)

    with open(midi_file, "wb") as output_file:
        MyMIDI.writeFile(output_file)

def extend_scale(scale,times):
    scaleAux = scale[:]
    for i in range(1,times):
        for note in scaleAux:
            scale.append(note+12*i)
    return scale

def match_lists_size(rhythm,melody):
    n_rhythm =len(rhythm)
    n_melody = len(melody)
    if n_rhythm < n_melody:
        rhythm = (rhythm*int(ceil(n_melody/float(n_rhythm))))[:n_melody]
    elif n_rhythm != n_melody:
        melody = (melody*int(ceil(n_rhythm/float(n_melody))))[:n_rhythm]

    return rhythm,melody

def to_list(rhythm, melody, scale):

    scale = extend_scale(scale,2)
    scaleSize = len(scale)

    volume = 100
    baseNote = 60

    rhythm, melody = match_lists_size(rhythm,melody)

    composition = []
    time = 0
    for i in range(len(rhythm)):
        dur = rhythm[i]
        note = scale[melody[i]%scaleSize] + baseNote
        composition.append((note,dur,volume,time))
        time += dur

    return composition

def compose(notes, durations, scale, new_midi_path):

    print(notes)
    print(durations)
    print(scale)

    composition = to_list(durations,notes,scale)
    print(composition)
    create_midi(new_midi_path, composition)