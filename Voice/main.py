from Voice import renderizeVoice

def main(filename, lyrics,tempo):

    durations = [1]*len(lyrics.split())
    notes = [0,2,3,4]*len(lyrics.split())
    scale = [0,2,4,5,7,9,11]

    renderizeVoice(filename,lyrics,notes,durations,tempo,scale)

import sys

main(sys.argv[1],sys.argv[2],int(sys.argv[3]))