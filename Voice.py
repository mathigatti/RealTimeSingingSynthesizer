import os

from Composer import compose
from midi2voice.midi2xml import midi2xml

FILES_ROOT = "."

def renderize_voice(output_name, lyrics, notes, durations, tempo, scale, language_code):
	MIDI_PATH = os.path.join(FILES_ROOT, "voice.mid")
	VOICE_XML_PATH= os.path.join(FILES_ROOT, "voice.xml")

	compose(notes, durations, scale, MIDI_PATH)

	lyrics = tokenize(lyrics)

	midi2xml(lyrics, MIDI_PATH, VOICE_XML_PATH, tempo)

	os.system("LD_LIBRARY_PATH=/usr/lib synthesisSoftware/Sinsy-NG-0.0.1/build/sinsyNG -t "+str(tempo)+" -m "+language_code+" -o " + output_name + " " + VOICE_XML_PATH)

def tokenize(text):
	text_syllables = clean_text(text)
	return list(filter(lambda x: len(x) > 0, text_syllables.replace(" ", "-").split("-")))

def clean_text(text):

	text.replace("\n"," ")
	text = text.lower()

	symbolsToDelete = ".,'!?" + '"'
	for symbol in symbolsToDelete:
		text = text.replace(symbol,"")

	return text
