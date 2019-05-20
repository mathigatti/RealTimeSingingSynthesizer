from Voice import renderizeVoice
import sys

def main(**kwargs):

    if "lyrics" in kwargs:
        lyrics = kwargs['lyrics']
    else:
        lyrics = "oo "

    if "notes" in kwargs:
        notes = list(map(int,kwargs['notes'].split(",")))
    else:
        notes = [0]

    if "dur" in kwargs:
        durations = list(map(int,kwargs['dur'].split(",")))
    else:
        durations = [1]

    if 'file' in kwargs:
        filename = kwargs['file']
    else:
        filename = 'output.wav'

    if 'tempo' in kwargs:
        tempo = kwargs['tempo']
    else:
        tempo = 100


    if 'lang' in kwargs:
        languageCode = kwargs['lang']
    else:
        languageCode = "es"


    root_note = 0 # C is the root note
    scale = [0,2,4,5,7,9,11] # Major Scale

    notes = list(map(lambda x: x + root_note,notes))

    renderizeVoice(filename,lyrics,notes,durations,tempo,scale,languageCode)

# Run main
main(**dict(arg.split('=') for arg in sys.argv[1:]))