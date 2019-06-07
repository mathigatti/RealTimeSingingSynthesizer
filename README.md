# Live Coding Singing Synthesizer
Real Time Singing Synthesizer project made from sinsy-NG. The idea was to generate vocal audio samples on real time easily for live coding performances.

## Demo
(Here)[https://www.youtube.com/watch?v=wvbV75Tw_24] is a video demonstration using the program to synthesize samples and load them into the FoxDot live coding environment.

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/wvbV75Tw_24/0.jpg)](https://www.youtube.com/watch?v=wvbV75Tw_24)

## Requirements
- python (Should work on 3 and 2.7 versions)
- musescore (It's used to convert midi to musicxml)

## Installation

Software contained in synthesisSoftware must be installed. 

- libespeag-NG (Install this first)
- Sinsy-NG (Install this second)

## Usage

You can try `main.py` script as a small singing synthesis example. After running this an output wav file will be generated containing the specified vocals.

All the parameters are optional, they contain a default value in case they are not specified. You can specify them in any order when running the program in the command line.

- notes: The numerical value of notes in the scale, in C Major would be something like 0:C, 1:D, 2:E, 3:F and so on...
The scale is C major by default, it's hardcoded in the main.py file and can be modified.

- dur: The duration of each note in BPM (beats per minute)

- lyrics: The text to be synthesized. Each word is mapped to one note from the "dur" and "notes" parameters

- lang: The language code, "es" for spanish and "en" for english
There are several languages supported, You can check those [here](http://espeak.sourceforge.net/languages.html)


- tempo: The tempo in BPM, 100 by default

- file: The name of the output file

### Usage examples
1. All the default values are used generating a single note audio file which says "Ooh" in spanish.
```
python main.py 
```
2. Example specifying only lyrics and language.
```
python main.py lyrics="hola hola hola" lang=es

```
3. Using all the parameters.
```
python main.py notes=0,0,2 lyrics="hello good morning" dur=1,1,2 lang=en file="output.wav" tempo=80
```
