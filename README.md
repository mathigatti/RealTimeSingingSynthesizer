# Live Coding Singing Synthesizer
Real Time Singing Synthesizer project made from sinsy-NG. The idea was to generate vocal audio samples on real time easily for live coding performances.

## Demo
[Here](https://www.youtube.com/watch?v=wvbV75Tw_24) is a video demonstration using the program to synthesize samples and load them into the FoxDot live coding environment.

[![IMAGE ALT TEXT HERE](https://i.ytimg.com/vi/wvbV75Tw_24/maxresdefault.jpg)](https://www.youtube.com/watch?v=wvbV75Tw_24)


## Requirements
- python (Should work on 3 and 2.7 versions)
- musescore (It's used to convert midi to musicxml)

## Installation

Software contained in synthesisSoftware must be installed.

- libespeak-NG (Install this first)
- Sinsy-NG (Install this second)

You can check the Colab notebook for a detailed guide about how to install it on Ubuntu.

## Usage

### Try it on Colab

If you want to check it quickly you can try it online [here](https://colab.research.google.com/drive/10FgnJcvbPNpp8W2OjrLLon_v719chtxj?usp=sharing).

[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/10FgnJcvbPNpp8W2OjrLLon_v719chtxj?usp=sharing)

### Try it on Docker

Build it
- docker build . -t voice-synth

Run it

- docker run --rm --network="host" -p 8080:8080 -e PORT=8080 voice-synth

Once that's done you can try `test-api.py` script as a small singing synthesis example. After running this an output wav file will be generated containing the specified vocals.

```
python test-api.py 
```

All the parameters are optional, they contain a default value in case they are not specified. You can specify them in any order when running the program in the command line.

- notes: The numerical value of notes in the scale, in C Major would be something like 0:C, 1:D, 2:E, 3:F and so on...
The scale is C major by default, it's hardcoded in the main.py file and can be modified.

- dur: The duration of each note in BPM (beats per minute)

- lyrics: The text to be synthesized. Each word is mapped to one note from the "dur" and "notes" parameters

- lang: The language code, "es" for spanish and "en" for english. There are several languages supported, You can check them [here](http://espeak.sourceforge.net/languages.html)

- tempo: The tempo in BPM

- file: The name of the output file

## Support my work

If you want to help me to keep going developing and maintaining open-source projects you can contribute buying me some [ko-fi](https://ko-fi.com/mathigatti).
