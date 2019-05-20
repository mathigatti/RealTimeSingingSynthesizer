# RealTimeSingingSynthesis
Real time singing synthesis project made from sinsy-NG.

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

- lyrics: The text where spaces delimit w

- dur: The BPM of each note

- lang: the language code, "es" for spanish and "en" for english.
There are several languages supported, can check that here http://espeak.sourceforge.net/languages.html

- tempo: The tempo in BPM, 100 by default

- file: the name of the output file

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

