# RealTimeSingingSynthesis
Real time singing synthesis project made from sinsy-NG.

## Requirements
- python 2.7
- musescore (It's used to convert midi to musicxml)

## Installation

Software contained in synthesisSoftware must be installed. 

- libespeag-NG (Install this first)
- Sinsy-NG (Install this second)

## Usage

You can try `main.py` script as a small singing synthesis example.

The usage is something like this
```
python2 main.py OUTPUT_FILE_NAME_WITHOUT_THE_EXTENSION LYRICS TEMPO
```

For example
```
python2 main.py example_audio "some lyrics to sing" 100
```

You can easily modify `main.py` and add notes, duration, language and more as parameters.
